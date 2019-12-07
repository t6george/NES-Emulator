#include <MMU.hpp>
#include <AddressableDevice.hpp>

MMU::MMU(const std::vector<AddressingInfo> &table) : virtToPhys{table} {}

void MMU::addEntry(const AddressingInfo entry)
{
    virtToPhys.emplace_back(entry);
}

uint8_t MMU::read(uint16_t addr) const
{
    uint8_t data = 0x00;

    for (size_t i = 0; i < virtToPhys.size(); ++i)
    {
        if (addr <= virtToPhys[i].limit && addr >= virtToPhys[i].base)
        {
            addr -= virtToPhys[i].base;
            data = virtToPhys[i].device->read(addr, virtToPhys[i].mirror);
            break;
        }
    }

    return data;
}

void MMU::write(uint16_t addr, uint8_t data) const
{
    for (size_t i = 0; i < virtToPhys.size(); ++i)
    {
        if (addr <= virtToPhys[i].limit && addr >= virtToPhys[i].base)
        {
            addr -= virtToPhys[i].base;
            virtToPhys[i].device->write(addr, virtToPhys[i].mirror, data);
            break;
        }
    }
}