#include <Chip8.h>

#include <iostream>

int main()
{
    Chip8 *ch8{new Chip8()};
    std::cout << "Current Program Counter location: " << ch8->pc << '\n';
    return 0;
}