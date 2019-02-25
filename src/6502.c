#include <stdio.h>
#include <SDL2/SDL.h>

#include "../headers/6502.h"

static mainMemory *memory;

cpu6502* powerUpCpu (void) {
  cpu6502* cpu;

  cpu->regP = 0x34;
  cpu->regA = 0x00;
  cpu->regX = 0x00;
  cpu->regY = 0x00;
  cpu->regS = 0xFD;

  cpu->memory = powerUpMemory (void);

  return cpu;
}

void powerDownCpu (cpu6502* cpu) {
  powerDownMemory (cpu->memory);
}

void resetCpu (cpu6502* cpu) {
  cpu->regS -= 0x03;
  cpu->regP |= 0x04;
  writeByte (0x00, 0x1540, ABSOLUTE, cpu->memory, 0x00);
}




int main (int argc, char* argv[]) {
	memory = initMemory ();
	//PPU stuff
	SDL_Window* window = NULL;
	window = SDL_CreateWindow
	(
	"NES", SDL_WINDOWPOS_UNDEFINED,
	SDL_WINDOWPOS_UNDEFINED,
	640,
	480,
	SDL_WINDOW_SHOWN
	);

	SDL_Renderer* renderer = NULL;
	renderer =  SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);

	SDL_SetRenderDrawColor( renderer, 255, 0, 0, 255 );

	SDL_RenderClear( renderer );

	SDL_Rect r;
	r.x = 50;
	r.y = 50;
	r.w = 50;
	r.h = 50;

	SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );

	SDL_RenderFillRect( renderer, &r );

	SDL_RenderPresent(renderer);

	SDL_Delay( 5000 );

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
