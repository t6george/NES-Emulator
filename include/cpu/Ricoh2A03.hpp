#pragma once
#include <memory>
#include <cstdint>
#include <array>

#include <Bus.hpp>
#include <MOS6502Instruction.hpp>

#define STACK_BASE 0x0100
#define NUM_OPCODES 0x100
#define FRAME_TICKS 29781

class GamePak;
class AddressableDevice;
class NesSystem;
class GamePad;
class Apu2A03;

class Ricoh2A03
{
public:
    std::unique_ptr<Bus> bus;

    std::shared_ptr<AddressableDevice> Ppu;
    std::shared_ptr<AddressableDevice> ram;
    std::shared_ptr<AddressableDevice> cartridge;
    std::array<std::unique_ptr<MOS6502Instruction>, NUM_OPCODES> instructions;

    uint8_t cycles;

public:
    enum Flags6502
    {
        C = (1 << 0),
        Z = (1 << 1),
        I = (1 << 2),
        D = (1 << 3),
        B = (1 << 4),
        U = (1 << 5),
        V = (1 << 6),
        N = (1 << 7),
    };

    enum class AddressingType
    {
        IMP,
        IMM,
        ZP,
        ZPX,
        ZPY,
        REL,
        AB,
        ABX,
        ABY,
        IN,
        IX,
        IY,
    };

    uint8_t A;
    uint8_t X;
    uint8_t Y;
    uint8_t SP;
    uint16_t PC;
    uint8_t S;
    int remaining;

    uint8_t dma_page;
    uint8_t dma_addr;
    bool dma_transfer;

    std::shared_ptr<Apu2A03> apu;

    Ricoh2A03(std::shared_ptr<AddressableDevice> ppu, std::shared_ptr<GamePad> p1);
    ~Ricoh2A03() = default;

    uint8_t read(uint16_t addr, bool zpageMode = false);
    uint16_t readDoubleWord(uint16_t addr, bool zpageMode = false);

    void write(uint16_t addr, uint8_t data);

    void fetch();
    void reset();
    void irq();
    void nmi(uint16_t interruptAddr = 0xFFFA);

    void pushWord(uint8_t word);
    void pushDoubleWord(uint16_t dWord);

    uint8_t popWord();
    uint16_t popDoubleWord();

    bool getFlag(Flags6502 f) const;
    void setFlag(Flags6502 f, bool b);

    uint8_t branch(uint16_t absoluteAddress, bool cond);
    void addCartridge(std::shared_ptr<AddressableDevice> cart);

    uint16_t elapsed() const;

    void processFrameAudio() const;
    bool isFrameDone() const;
    void restartFrameTimer();
};
