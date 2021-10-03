#include <Chip8.h>
#include <SDL.h>
#include <iostream>
#include <bitset>

int main(int argc, char *argv[])
{
    Chip8 *ch8{new Chip8()};
    std::cout << "Current Program Counter location: " << ch8->pc << '\n';

    std::cout << "Printing out all fonts" << '\n';
    for (unsigned int i{}; i < FONTSET_SIZE;)
    {

        std::cout << std::bitset<8>(ch8->memory[FONTSET_START_ADDRESS + i]) << '\n';
        ++i;
        if (i % 5 == 0)
        {
            std::cout << '\n';
        }
    }

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow(
        "SDL2Test",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        640,
        480,
        0);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

    SDL_Delay(3000);

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}