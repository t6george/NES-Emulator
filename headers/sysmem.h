#include "6502.h"

#define RAM_RANGE 0x800
#define PPU_REGS_RANGE 0x8
#define APU_IO_REGS_RANGE 0x8
#define APU_REGS_RANGE 0x18
#define CART_SPACE_RANGE 0xBFE0

typedef struct {
	u8 *ram = NULL;
	u8 *ppuRegs = NULL;
	u8 *apuRegs = NULL;
	u8 *apuIORegs = NULL;
	u8 *cartridgeMem = NULL;

	u8 *cpuRegA = NULL;
	u8 *cpuRegX = NULL;
	u8 *cpuRegY = NULL;
	u8 *cpuRegPC = NULL;
} mainMemory;

enum addressingMode {
	ABSOLUTE = 0,
	ZERO_PAGE,
	INDIRECT,
	ABSOLUTE_INDEXED,
	ZERO_PAGE_INDEXED,
	INDEXED_INDIRECT,
	INDIRECT_INDEXED,
};


mainMemory *initMemory (cpu* mos6502);
void uninitMemory (void);
u8* decodeAddress (u16 address, mainMemory *memory);
u8 readByte (u16 address, u8 addrMode, mainMemory *memory);
void writeByte (u8 data, u16 address, u8 addrMode, mainMemory *memory);
