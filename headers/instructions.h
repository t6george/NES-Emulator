#include "sysmem.h"

typedef struct {
  u8 size;
  addressingMode addrMode;
  u8 cycles;
  u8 *indexReg;
  void *dst;
  bool
  u8 (*exec)(instruction* instr);
  u8 auxBytes[2];
} instruction;


const instruction instructionMap [0x100] {
  //0x0X
  {0, ABSOLUTE, 7, .exec = },
  {1, INDEXED_INDIRECT, 6, .exec = },
  {}, {}, {},
  {1, ZERO_PAGE, 3, .exec = },
  {1, ZERO_PAGE, 5, .exec = },
  {},
  {0, ABSOLUTE, 3, .exec = },
  {1, NON_MEMORY, 2, .exec = },
  {0, NON_MEMORY, 2, .exec = },
  {}, {},
  {2, ABSOLUTE, 4, .exec = },
  {2, ABSOLUTE, 6, .exec = },
  {},
  //0x1X
  {1, NON_MEMORY, 2, .exec = },
  {1, INDIRECT_INDEXED, 5, .exec = },
  {}, {}, {},
  {1, ZERO_PAGE_INDEXED, 4, .exec = },
  {1, ZERO_PAGE_INDEXED, 6, .exec = },
  {},
  {0, NON_MEMORY, 2, .exec = },
  {2, ABSOLUTE_INDEXED, 4, .exec = },
  {}, {}, {},
  {2, ABSOLUTE_INDEXED, 4, .exec = },
  {2, ABSOLUTE_INDEXED, 7, .exec = },
  {},
  //0x2X
  {2, ABSOLUTE, 6, .exec = },
  {1, INDEXED_INDIRECT, 6, .exec = },
  {},{},
  {1, ZERO_PAGE, 3, .exec = },
  {1, ZERO_PAGE, 3, .exec = },
  {1, ZERO_PAGE, 5, .exec = },
  {},
  {0, ABSOLUTE, 4, .exec = },
  {1, NON_MEMORY, 2, .exec = },
  {0, NON_MEMORY, 2, .exec = },
  {},
  {2, ABSOLUTE, 4, .exec = },
  {2, ABSOLUTE, 4, .exec = },
  {2, ABSOLUTE, 6, .exec = },
  {},
  //0x3X
  {1, NON_MEMORY, 2, .exec = },
  {1, INDIRECT_INDEXED, 5, .exec = },
  {},{},{},
  {1, ZERO_PAGE_INDEXED, 4, .exec = },
  {1, ZERO_PAGE_INDEXED, 6, .exec = },
  {},
  {0, NON_MEMORY, 2, .exec = },
  {2, ABSOLUTE_INDEXED, 4, .exec = },
  {},{},{},
  {2, ABSOLUTE_INDEXED, 4, .exec = },
  {2, ABSOLUTE_INDEXED, 7, .exec = },
  {},
  //0x4X
  {0, ABSOLUTE, 6, .exec = },
  {1, INDEXED_INDIRECT, 6, .exec = },
  {},{},{},
  {1, ZERO_PAGE, 3, .exec = },
  {1, ZERO_PAGE, 5, .exec = },
  {},
  {0, ABSOLUTE, 3, .exec = },
  {0, NON_MEMORY, 2, .exec = },
  {0, NON_MEMORY, 2, .exec = },
  {},
  {2, ABSOLUTE, 3, .exec = },
  {2, ABSOLUTE, 4, .exec = },
  {2, ABSOLUTE, 6, .exec = },
  {},
  //0x5X
  {1, NON_MEMORY, 2, .exec = },
  {1, INDIRECT_INDEXED, 5, .exec = },
  {},{},{},
  {1, ZERO_PAGE_INDEXED, 4, .exec = },
  {1, ZERO_PAGE_INDEXED, 6, .exec = },
  {},
  {0, NON_MEMORY, 2, .exec = },
  {2, ABSOLUTE_INDEXED, 4, .exec = },
  {},{},{},
  {2, ABSOLUTE_INDEXED, 4, .exec = },
  {2, ABSOLUTE_INDEXED, 7, .exec = },
  {},
  //0x6X
  {0, ABSOLUTE, 6, .exec = },
  {1, INDEXED_INDIRECT, 6, .exec = },
  {},{},{},
  {1, ZERO_PAGE, 3, .exec = },
  {1, ZERO_PAGE, 5, .exec = },
  {},
  {0, ABSOLUTE, 4, .exec = },
  {1, NON_MEMORY, 2, .exec = },
  {0, NON_MEMORY, 2, .exec = },
  {},
  {2, INDEXED_INDIRECT, 5, .exec = },
  {2, ABSOLUTE, 4, .exec = },
  {2, ABSOLUTE, 6, .exec = },
  {},
  //0x7X
  {1, NON_MEMORY, 2, .exec = },
  {1, INDIRECT_INDEXED, 5, .exec = },
  {},{},{},
  {1, ZERO_PAGE_INDEXED, 4, .exec = },
  {1, ZERO_PAGE_INDEXED, 6, .exec = },
  {},
  {0, NON_MEMORY, 2, .exec = },
  {2, ABSOLUTE_INDEXED, 4, .exec = },
  {},{},{},
  {2, ABSOLUTE_INDEXED, 4, .exec = },
  {2, ABSOLUTE_INDEXED, 7, .exec = },
  {},
  //0x8X
  {},
  {1, INDEXED_INDIRECT, 6, .exec = },
  {},{},
  {1, ZERO_PAGE, 3, .exec = },
  {1, ZERO_PAGE, 3, .exec = },
  {1, ZERO_PAGE, 3, .exec = },
  {},
  {0, NON_MEMORY, 2, .exec = },
  {},
  {0, NON_MEMORY, 2, .exec = },
  {},
  {2, ABSOLUTE, 4, .exec = },
  {2, ABSOLUTE, 4, .exec = },
  {2, ABSOLUTE, 4, .exec = },
  {},
  //0x9X
  {1, NON_MEMORY, 2, .exec = },
  {1, INDIRECT_INDEXED, 6, .exec = },
  {},{},
  {1, ZERO_PAGE_INDEXED, 4, .exec = },
  {1, ZERO_PAGE_INDEXED, 4, .exec = },
  {1, ZERO_PAGE_INDEXED, 4, .exec = },
  {},
  {0, NON_MEMORY, 2, .exec = },
  {2, ABSOLUTE, 5, .exec = },
  {0, NON_MEMORY, 2, .exec = },
  {},{},
  {2, ABSOLUTE, 5, .exec = },
  {},{},
  //0xAX
  {1, NON_MEMORY, 2, .exec = },
  {1, INDEXED_INDIRECT, 6, .exec = },
  {1, NON_MEMORY, 2, .exec = },
  {},
  {1, ZERO_PAGE, 3, .exec = },
  {1, ZERO_PAGE, 3, .exec = },
  {1, ZERO_PAGE, 3, .exec = },
  {},
  {0, NON_MEMORY, 2, .exec = },
  {1, NON_MEMORY, 2, .exec = },
  {0, NON_MEMORY, 2, .exec = },
  {},
  {2, ABSOLUTE, 4, .exec = },
  {2, ABSOLUTE, 4, .exec = },
  {2, ABSOLUTE, 4, .exec = },
  {},
  //0xBX
  {1, NON_MEMORY, 2, .exec = },
  {1, INDIRECT_INDEXED, 5, .exec = },
  {},{},
  {1, ZERO_PAGE_INDEXED, 4, .exec = },
  {1, ZERO_PAGE_INDEXED, 4, .exec = },
  {1, ZERO_PAGE_INDEXED, 4, .exec = },
  {},
  {0, NON_MEMORY, 2, .exec = },
  {1, INDIRECT_INDEXED, 5, .exec = },
  {0, NON_MEMORY, 2, .exec = },
  {},
  {2, ABSOLUTE_INDEXED, 4, .exec = },
  {2, ABSOLUTE_INDEXED, 4, .exec = },
  {2, ABSOLUTE_INDEXED, 4, .exec = },
  {},
  //0xCX
  {1, ABSOLUTE, 2, .exec = },
  {1, INDEXED_INDIRECT, 6, .exec = },
  {},{},
  {1, ZERO_PAGE, 3, .exec = },
  {1, ZERO_PAGE, 3, .exec = },
  {1, ZERO_PAGE, 5, .exec = },
  {},
  {0, NON_MEMORY, 2, .exec = },
  {1, NON_MEMORY, 2, .exec = },
  {0, NON_MEMORY, 2, .exec = },
  {},
  {2, ABSOLUTE, 4, .exec = },
  {2, ABSOLUTE, 4, .exec = },
  {2, ABSOLUTE, 3, .exec = },
  {},
  //0xDX
  {1, NON_MEMORY, 2, .exec = },
  {1, INDIRECT_INDEXED, 5, .exec = },
  {},{},{},
  {1, ZERO_PAGE_INDEXED, 4, .exec = },
  {1, ZERO_PAGE_INDEXED, 6, .exec = },
  {},
  {0, NON_MEMORY, 2, .exec = },
  {2, ABSOLUTE_INDEXED, 4, .exec = },
  {},{},{},
  {2, ABSOLUTE, 4, .exec = },
  {2, ABSOLUTE, 3, .exec = },
  {},
  //0xEX
  {1, NON_MEMORY, 2, .exec = },
  {1, INDEXED_INDIRECT, 6, .exec = },
  {},{},
  {1, ZERO_PAGE, 3, .exec = },
  {1, ZERO_PAGE, 3, .exec = },
  {1, ZERO_PAGE, 5, .exec = },
  {},
  {0, NON_MEMORY, 2, .exec = },
  {1, NON_MEMORY, 2, .exec = },
  {0, NON_MEMORY, 2, .exec = },
  {},
  {2, ABSOLUTE, 4, .exec = },
  {2, ABSOLUTE, 4, .exec = },
  {2, ABSOLUTE, 6, .exec = },
  {},
  //0xFX
  {1, NON_MEMORY, 2, .exec = },
  {1, INDIRECT_INDEXED, 5, .exec = },
  {},{},{},
  {1, ZERO_PAGE_INDEXED, 4, .exec = },
  {1, ZERO_PAGE_INDEXED, 6, .exec = },
  {},
  {0, NON_MEMORY, 2, .exec = },
  {2, ABSOLUTE_INDEXED, 4, .exec = },
  {},{},{},
  {2, ABSOLUTE_INDEXED, 4, .exec = },
  {2, ABSOLUTE_INDEXED, 7, .exec = },
  {},
};
