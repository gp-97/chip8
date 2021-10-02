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
    /** @brief <b>Chip8 Constructor</b>
 * 
 * Used to initialize the Chip-8 member variables
 * 
 */
    Chip8();

    /** @brief Chip8 Destructor
     * 
     * Basic destructor for Chip8 class object
     * 
     */
    ~Chip8();

public:
    /** @brief <b>ROM Loader</b>
 * 
 * Loads ROM into the main memory before any execution occurs
 * 
 * @param filename Constant char ptr to filename
 * @return Void
 */
    void LoadROM(char const *);

public:
    /** @brief <b>Clear Screen</b>
 * 
 * Set the entire video buffer to zeroes
 * 
 */
    void OP_00E0();

    /** @brief <b>Return from Sub Routine</b>
 * 
 * Set the program counter to the calling routine
 * 
 */
    void OP_00EE();

    /** @brief <b>Jump to location NNN</b>
 * 
 * Set the program counter to nnn
 * 
 */
    void OP_1nnn();

    /** @brief <b>Call addr</b>
 * 
 * Call sub-routine at nnn
 * 
 */
    void OP_2nnn();

    /** @brief <b>SE Vx, byte</b>
 * 
 * Skip next instruction if Vx = kk
 * 
 */
    void OP_3xkk();

    /** @brief <b>SNE Vx, byte</b>
 * 
 * Skip next instruction if Vx != kk
 * 
 */
    void OP_4xkk();

    /** @brief <b>SE Vx, Vy</b>
 * 
 * Skip next instruction if Vx = Vy
 * 
 */
    void OP_5xy0();

    /** @brief <b>LD Vx, byte</b>
 * 
 * Set Vx = kk
 * 
 */
    void OP_6xkk();

    /** @brief <b>ADD Vx, byte</b>
 * 
 * Set Vx = Vx + kk
 * 
 */
    void OP_7xkk();

    /** @brief <b>LD Vx, Vy</b>
 * 
 * Set Vx = Vy
 * 
 */
    void OP_8xy0();

    /** @brief <b>OR Vx, Vy</b>
 * 
 * Set Vx = Vx OR Vy
 * 
 */
    void OP_8xy1();

    /** @brief <b>AND Vx, Vy</b>
 * 
 * Set Vx = Vx AND Vy
 * 
 */
    void OP_8xy2();

    /** @brief <b>XOR Vx, Vy</b>
 * 
 * Set Vx = Vx XOR Vy
 * 
 */
    void OP_8xy3();

    /** @brief <b>ADD Vx, Vy</b>
 * 
 * Set Vx = Vx + Vy. Set VF = carry
 * 
 */
    void OP_8xy4();

    /** @brief <b>SUB Vx, Vy</b>
 * 
 * Set Vx = Vx - Vy. Set VF = NOT borrow
 * 
 */
    void OP_8xy5();

    /** @brief <b>SHR Vx</b>
 * 
 * Set Vx = Vx SHR 1
 * 
 */
    void OP_8xy6();

    /** @brief <b>SUBN Vx, Vy</b>
 * 
 * Set Vx = Vy - Vx. Set VF = NOT borrow
 * 
 */
    void OP_8xy7();

    /** @brief <b>SHL Vx</b>
 * 
 * Set Vx = Vx SHL 1. Set VF = MSB 
 * 
 */
    void OP_8xyE();

    /** @brief <b>SNE Vx, Vy</b>
 * 
 * Skip next instruction if Vx != Vy
 * 
 */
    void OP_9xy0();

    /** @brief <b>LD I, addr</b>
 * 
 * Set I = nnn
 * 
 */
    void OP_Annn();

    /** @brief <b>JP V0, addr</b>
 * 
 * Jump to location nnn + V0
 * 
 */
    void OP_Bnnn();

    /** @brief <b>RND Vx, byte</b>
 * 
 * Set Vx = randomByte AND kk
 * 
 */
    void OP_Cxkk();

    /** @brief <b>DRW Vx, Vy, nibble</b>
 * 
 * Draw n-byte sprite starting at memory location I at (Vx, Vy). Set VF = collision
 * 
 */
    void OP_Dxyn();

    /** @brief <b>SKP Vx</b>
 * 
 * Skip next instruction if key with value = Vx is pressed
 * 
 */
    void OP_Ex9E();

    /** @brief <b>SKNP Vx</b>
 * 
 * Skip next instruction if key with value = Vx is NOT pressed
 * 
 */
    void OP_ExA1();

    /** @brief <b>LD Vx, DT</b>
 * 
 * Set Vx = delay timer value 
 * 
 */
    void OP_Fx07();

    /** @brief <b>LD Vx, K</b>
 * 
 * Wait for key press and store its value in Vx
 * 
 */
    void OP_Fx0A();

    /** @brief <b>LD DT, Vx</b>
 * 
 * Set delay timer value = Vx
 * 
 */
    void OP_Fx15();

    /** @brief <b>LD ST, Vx</b>
 * 
 * Set sound timer = Vx
 * 
 */
    void OP_Fx18();

    /** @brief <b>ADD I, Vx</b>
 * 
 * Set I = I + Vx
 * 
 */
    void OP_Fx1E();

    /** @brief <b>LD F, Vx</b>
 * 
 * Set I = location of sprite for digit Vx
 * 
 */
    void OP_Fx29();

    /** @brief <b>LD B, Vx</b>
 * 
 * Store BCD representation of Vx in memory locations I, I+1, I+2
 * 
 */
    void OP_Fx33();

    /** @brief <b>LD [I], Vx</b>
 * 
 * Store registers V0 to Vx in memory starting from location I
 * 
 */
    void OP_Fx55();

    /** @brief <b>LD [Vx], I</b>
 * 
 * Read registers V0 to Vx starting from memory location I
 *  
 */
    void OP_Fx65();
};

#endif