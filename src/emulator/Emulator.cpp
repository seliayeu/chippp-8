#include "Instruction.hpp"
#include "instructions/Clear.hpp"
#include "instructions/LoadByte.hpp"
#include "instructions/SetIImmediate.hpp"
#include "instructions/Draw.hpp"
#include "instructions/JumpAddress.hpp"
#include "Emulator.hpp"
#include <iostream>
#include <utility>
#include <chrono>
#include <thread>
#include "raylib.h"

void Emulator::execute() {
    const int framerate{ 60 };

    const int width{ 64 * 8 };
    const int height{ 32 * 8 };

    InitWindow(width, height, "CHIP-8");

    while (env.pc < env.end && !WindowShouldClose()) {
        // update timer registers
        if (env.timerRegister > 0)
            env.timerRegister -= 1;
        if (env.soundRegister > 0) {
            env.soundRegister -= 1;
            // play bell
        }

        // process instruction
        std::unique_ptr<Instruction> inst;
        unsigned char byte0{ env.memory[env.pc] }, byte1{ env.memory[env.pc + 1] };
        std::cout << "[PC: " << std::hex << env.pc << "] ";
        std::cout << std::setfill('0') << std::setw(2) << static_cast<int>(byte0);
        std::cout << std::setfill('0') << std::setw(2) << static_cast<int>(byte1);
        std::cout << std::endl;

        if (byte0 == 0x00 && byte1 == 0xE0) {
            std::cout << "Clear\n";
            inst = std::make_unique<Clear>();
        } else if ((byte0 >> 4) == 0x06) {
            std::cout << "LoadByte\n";
            std::cout << std::setfill('0') << std::setw(2) << byte1 + 1 << std::endl;
            inst = std::make_unique<LoadByte>(Register(byte0 & 0x0F), byte1);
        } else if ((byte0 >> 4) == 0x0A) {
            std::cout << "SetIImmediate\n";
            inst = std::make_unique<SetIImmediate>(((byte0 & 0x0F) << 8) | byte1);
        } else if ((byte0 >> 4) == 0x0D) {
            std::cout << "Draw\n";
            inst = std::make_unique<Draw>(Register(byte0 & 0x0F), Register((byte1 & 0xF0) >> 4), byte1 & 0x0F);
        } else if ((byte0 >> 4) == 0x01) {
            std::cout << "JumpAddress\n";
            inst = std::make_unique<JumpAddress>(((byte0 & 0x0F) << 8) | byte1);
        } else {
            break;
            env.pc += 2;
        }

        inst->op(env);

        // draw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        for (unsigned int y = 0; y < 32; ++y) {
            auto& row{ env.display[y] };
            for (unsigned int x = 0; x < 64; ++x) {
                if (!row[x])
                    continue;
                DrawRectangle(static_cast<int>(x * 8), static_cast<int>(y * 8), 8, 8, LIGHTGRAY);
            }
        }
        EndDrawing();
        std::this_thread::sleep_for(std::chrono::milliseconds((framerate / 60) * 10));
    }

    CloseWindow();
}
