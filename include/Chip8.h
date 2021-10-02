/** @file Chip8.h
 *  @brief Header class for Chip8 core
 * 
 *  This file containes the prototypes for
 *  the Chip-8 core functionalities.
 * 
 *  @author Gaurav Patel
 */
#ifndef CHIP8_DESCRIPTION_HEADER
#define CHIP8_DESCRIPTION_HEADER

#include <prelude.h>

#include <cstdint>
#include <fstream>
#include <chrono>
#include <random>

/** @brief Chip8 prototype class
 * 
 * Contains all the data members and
 * the associated member functions
 * 
 * The main components to be emulated include:
 * 
 * - <b>16 bit Registers</b>
 *
 * - <b>4K Memory</b>
 * 
 * - <b>16-bit Index Register</b>
 * 
 * - <b>16-bit Program Counter</b>
 * 
 * - <b>16-level Stack</b>
 * 
 * - <b>8-bit Stack Pointer</b>
 * 
 * - <b>8-bit Delay Timer</b>
 * 
 * - <b>8-bit Sound Timer</b>
 * 
 * - <b>16 Input Keys</b>
 * 
 * - <b>64x32 Monochrome Monitor</b>
 */
class Chip8
{
public:
    uint8_t registers[16]{};
    uint8_t memory[4096]{};
    uint16_t index{};
    uint16_t pc{};
    uint16_t stack[16]{};
    uint8_t sp{};
    uint8_t delayTimer{};
    uint8_t soundTimer{};
    uint8_t keypad[16]{};
    uint8_t video[64 * 32]{};
    uint16_t opcode{};

public:
    std::default_random_engine randGen;
    std::uniform_int_distribution<uint8_t> randByte;

public:
    /** @brief Chip8 Constructor
 * 
 * Used to initialize the program counter
 */
    Chip8();

    /** @brief Chip8 Destructor
     */
    ~Chip8();

public:
    /** @brief ROM Loader
 * 
 * Loads ROM into the main memory before any execution occurs
 * 
 * @param filename Constant char ptr to filename
 * @return Void
 */
    void LoadROM(char const *);
};

#endif