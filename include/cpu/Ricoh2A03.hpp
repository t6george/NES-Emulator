#pragma once
#include <memory>
#include <cstdint>

#define STACK_BASE 0x0100

class Bus;

class Ricoh2A03
{
    std::shared_ptr<Bus> bus;
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

    enum AddressingType
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

    uint8_t A;
    uint8_t X;
    uint8_t Y;
    uint8_t SP;
    uint16_t PC;
    uint8_t S;

    Ricoh2A03(std::shared_ptr<Bus> bus);
    ~Ricoh2A03() = default;

    uint8_t read(uint16_t addr);
    void write(uint16_t addr, uint8_t data);

    void tick();
    void reset();
    void irq();
    void nmi(uint16_t interruptAddr = 0xFFFA);

    void pushWord(uint8_t word);
    void pushDoubleWord(uint16_t dWord);

    uint8_t popWord();
    uint16_t popDoubleWord();

    bool GetFlag(Flags6502 f) const;
    void SetFlag(Flags6502 f, bool b);
};