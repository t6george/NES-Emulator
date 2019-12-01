#include <PpuBus.hpp>

void PpuBus::initMmu()
{
    mmu.resize(TOTAL_DEVICES);
    mmu[RAM] = { .base = 0x0000, .end = 0x1FFF, .mirrorSize = 0x0800};
    mmu[PPU] = { .base = 0x2000, .end = 0x3FFF, .mirrorSize = 0x0008};
    mmu[CART] = { .base = 0x4020, .end = 0xFFFF, .mirrorSize = 0x0000};
}

AddressableDevice* PpuBus::delegate(uint16_t& addr)
{
    AddressableDevice* device = nullptr;
    Devices dev = RAM;

    for(; dev < TOTAL_DEVICES; ++dev)
    {
        if(addr <= mmu[dev].end && addr >= mmu[dev].base)
        {
            addr = (addr - mmu[dev].base) & (mmu[dev].mirrorSize - 1);
            break;
        }
    }

    switch(dev)
    {
        case CART:
            device = cartridge;
            break;
        default:
            break;
    }

    return device;
}