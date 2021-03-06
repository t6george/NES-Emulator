#include <fstream>
#include <cassert>
#include <iostream>
#include <stdexcept>

#include <GamePak.hpp>
#include <Mapper000.hpp>
#include <SDL2/SDL.h>

GamePak::GamePak(const std::string &fname) : mem{PRG}
{
    parseFile(fname);
}

void GamePak::parseFile(const std::string &fname)
{
    std::ifstream in;

    try
    {
        in.open(fname, std::ifstream::binary);
        in.read((char *)&header, sizeof(GameHeader));

        // Validate NES ROM Checksum
        if (header.name[0] != 'N' || header.name[1] != 'E' || header.name[2] != 'S' || header.name[3] != 0x1A)
        {
            throw std::ifstream::failure("Invalid ROM:\nCheck https://github.com/t6george/NESS for supported mappers/games.");
        }

        if (header.mapper1 & 0x04)
        {
            in.seekg(0x200, std::ios_base::cur);
        }

        uint8_t mapperNum = (header.mapper2 & 0xFFF0) | (header.mapper1 >> 0x4);
        mMode = (header.mapper1 & 0x01) ? VERTICAL : HORIZONTAL;

        uint8_t ftype = 1;

        if (ftype == 1)
        {
            header.chrBanks = header.chrBanks == 0 ? 0x1 : header.chrBanks;
            prg.resize(CARTRIDGE::PrgBankSize * header.prgBanks);
            chr.resize(CARTRIDGE::ChrBankSize * header.chrBanks);

            in.read((char *)prg.data(), prg.size());
            in.read((char *)chr.data(), chr.size());
        }

        switch (mapperNum)
        {
        case 0:
            mapper.reset(new Mapper000(header.prgBanks, header.chrBanks));
            break;
        default:
            // Unsupported Mapper Type
            throw std::ifstream::failure("Unsupported ROM:\nCheck https://github.com/t6george/NESS for supported mappers/games.");
            break;
        }

        in.close();
    }
    catch (const std::ifstream::failure &e)
    {
        std::cerr << e.what() << std::endl;
        in.close();
        exit(0);
    }
}

inline uint8_t GamePak::getByte(uint16_t addr, bool readOnly)
{
    uint8_t data = 0x00;

    if (mem == PRG && mapper->translatePrgAddress(addr))
    {
        data = prg[addr];
    }
    else if (mem == CHR && mapper->translateChrAddress(addr))
    {
        data = chr[addr];
    }

    return data;
}

inline void GamePak::setByte(uint16_t addr, uint8_t data)
{
    if (mem == PRG && mapper->translatePrgAddress(addr))
    {
        prg[addr] = data;
    }
    else if (mem == CHR && mapper->translateChrAddress(addr))
    {
        chr[addr] = data;
    }
}

inline uint16_t GamePak::mirrorAddress(uint16_t addr, uint16_t mirror)
{
    if (mirror == CPU::CARTRIDGE::Mirror)
    {
        mem = PRG;
    }
    else if (mirror == PPU::CARTRIDGE::Mirror)
    {
        mem = CHR;
    }

    return addr;
}

GamePak::MirrorMode GamePak::getMirrorMode() const
{
    return mMode;
}