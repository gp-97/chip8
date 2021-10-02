#include <Chip8.h>

#include <iostream>
#include <bitset>

int main()
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
    return 0;
}