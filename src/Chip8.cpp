/** @file Chip8.cpp
 *  @brief Implementation file for Chip8.h
 * 
 *  This file implements the Chip-8 core
 *  functionalities.
 * 
 *  @author Gaurav Patel
 */
#include <Chip8.h>

// Chip8 constructor implementation
Chip8::Chip8() : pc(START_ADDRESS)
{
    // Load fonts into main memory
    for (unsigned int i{}; i < FONTSET_SIZE; ++i)
    {
        memory[FONTSET_START_ADDRESS + i] = fontset[i];
    }
}

// Chip8 destructor
Chip8::~Chip8() {}

void Chip8::LoadROM(char const *filename)
{
    // Open the file as a binary filestream
    // and move the file pointer to the end
    std::ifstream file(filename, std::ios::binary | std::ios::ate);

    if (file.is_open())
    {
        // Get size of the file and allocate a buffer to hold its contents
        std::streampos size{file.tellg()};
        char *buffer{new char[size]};

        // Go to beginning of the file and fill the buffer
        file.seekg(0, std::ios::beg);
        file.read(buffer, size);
        file.close();

        // Fill the Chip-8's memory with ROM's content starting from 0x200
        // as memory from 0x000 - 0x1FF is reserved
        for (int i{}; i < size; ++i)
        {
            memory[START_ADDRESS + i] = buffer[i];
        }

        // Free the buffer
        delete[] buffer;
    }
}
