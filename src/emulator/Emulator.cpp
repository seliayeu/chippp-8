#include "Instruction.hpp"
#include "instructions/Clear.hpp"
#include "instructions/Return.hpp"
#include "instructions/JumpAddress.hpp"
#include "instructions/Call.hpp"
#include "instructions/SkipEqualByte.hpp"
#include "instructions/SkipNotEqualByte.hpp"
#include "instructions/SkipEqualRegister.hpp"
#include "instructions/StoreByte.hpp"
#include "instructions/AddByte.hpp"
#include "instructions/Move.hpp"
#include "instructions/Or.hpp"
#include "instructions/And.hpp"
#include "instructions/Xor.hpp"
#include "instructions/AddRegister.hpp"
#include "instructions/SubFromDest.hpp"
#include "instructions/ShiftRight.hpp"
#include "instructions/SubFromSource.hpp"
#include "instructions/ShiftLeft.hpp"
#include "instructions/SkipNotEqualRegister.hpp"
#include "instructions/SetIImmediate.hpp"
#include "instructions/JumpRegister.hpp"
#include "instructions/Random.hpp"
#include "instructions/Draw.hpp"
#include "instructions/SkipPressed.hpp"
#include "instructions/SkipNotPressed.hpp"
#include "instructions/GetDelayTimer.hpp"
#include "instructions/WaitKey.hpp"
#include "instructions/SetDelayTimer.hpp"
#include "instructions/SetSoundTimer.hpp"
#include "instructions/AddIRegister.hpp"
#include "instructions/SetISprite.hpp"
#include "instructions/StoreBCD.hpp"
#include "instructions/StoreRegisters.hpp"
#include "instructions/LoadRegisters.hpp"
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
        if (env.waitKeyFlag) {
            int key{ GetKeyPressed() };

            if (key > 0) {
                if ((key >= KEY_ZERO && key <= KEY_NINE) || (key >= KEY_A && key <= KEY_F)) {
                    env.VRegisters[static_cast<unsigned int>(env.waitKeyReg)] = env.raylibToHex[key];
                    env.waitKeyFlag = false;
                    env.pc += 2;
                }
            }

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

            continue;
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
        } else if (byte0 == 0x00 && byte1 == 0xEE) {
            std::cout << "Return\n";
            inst = std::make_unique<Return>();
        } else if ((byte0 >> 4) == 0x01) {
            std::cout << "JumpAddress\n";
            inst = std::make_unique<JumpAddress>(((byte0 & 0x0F) << 8) | byte1);
        } else if ((byte0 >> 4) == 0x02) {
            std::cout << "Call\n";
            inst = std::make_unique<Call>(((byte0 & 0x0F) << 8) | byte1);
        } else if ((byte0 >> 4) == 0x03) {
            std::cout << "SkipEqualByte\n";
            inst = std::make_unique<SkipEqualByte>(Register(byte0 & 0x0F), byte1);
        } else if ((byte0 >> 4) == 0x04) {
            std::cout << "SkipNotEqualByte\n";
            inst = std::make_unique<SkipNotEqualByte>(Register(byte0 & 0x0F), byte1);
        } else if ((byte0 >> 4) == 0x05 && (byte1 & 0x0F) == 0) {
            std::cout << "SkipEqualRegister\n";
            inst = std::make_unique<SkipEqualRegister>(Register(byte0 & 0x0F), Register((byte1 & 0xF0) >> 4));
        } else if ((byte0 >> 4) == 0x06) {
            std::cout << "StoreByte\n";
            std::cout << std::setfill('0') << std::setw(2) << byte1 + 1 << std::endl;
            inst = std::make_unique<StoreByte>(Register(byte0 & 0x0F), byte1);
        } else if ((byte0 >> 4) == 0x07) {
            std::cout << "AddByte\n";
            inst = std::make_unique<AddByte>(Register(byte0 & 0x0F), byte1);
        } else if ((byte0 >> 4) == 0x08 && (byte1 & 0x0F) == 0) {
            std::cout << "Move\n";
            inst = std::make_unique<Move>(Register(byte0 & 0x0F), Register((byte1 & 0xF0) >> 4));
        } else if ((byte0 >> 4) == 0x08 && (byte1 & 0x0F) == 1) {
            std::cout << "Or\n";
            inst = std::make_unique<Or>(Register(byte0 & 0x0F), Register((byte1 & 0xF0) >> 4));
        } else if ((byte0 >> 4) == 0x08 && (byte1 & 0x0F) == 2) {
            std::cout << "And\n";
            inst = std::make_unique<And>(Register(byte0 & 0x0F), Register((byte1 & 0xF0) >> 4));
        } else if ((byte0 >> 4) == 0x08 && (byte1 & 0x0F) == 3) {
            std::cout << "Xor\n";
            inst = std::make_unique<Xor>(Register(byte0 & 0x0F), Register((byte1 & 0xF0) >> 4));
        } else if ((byte0 >> 4) == 0x08 && (byte1 & 0x0F) == 4) {
            std::cout << "AddRegister\n";
            inst = std::make_unique<AddRegister>(Register(byte0 & 0x0F), Register((byte1 & 0xF0) >> 4));
        } else if ((byte0 >> 4) == 0x08 && (byte1 & 0x0F) == 5) {
            std::cout << "SubFromDest\n";
            inst = std::make_unique<SubFromDest>(Register(byte0 & 0x0F), Register((byte1 & 0xF0) >> 4));
        } else if ((byte0 >> 4) == 0x08 && (byte1 & 0x0F) == 6) {
            std::cout << "ShiftRight\n";
            inst = std::make_unique<ShiftRight>(Register(byte0 & 0x0F));
        } else if ((byte0 >> 4) == 0x08 && (byte1 & 0x0F) == 7) {
            std::cout << "SubFromSource\n";
            inst = std::make_unique<SubFromSource>(Register(byte0 & 0x0F), Register((byte1 & 0xF0) >> 4));
        } else if ((byte0 >> 4) == 0x08 && (byte1 & 0x0F) == 0xE) {
            std::cout << "ShiftLeft\n";
            inst = std::make_unique<ShiftLeft>(Register(byte0 & 0x0F));
        } else if ((byte0 >> 4) == 0x09 && (byte1 & 0x0F) == 0) {
            std::cout << "SkipNotEqualRegister\n";
            inst = std::make_unique<SkipNotEqualRegister>(Register(byte0 & 0x0F), Register((byte1 & 0xF0) >> 4));
        } else if ((byte0 >> 4) == 0x0A) {
            std::cout << "SetIImmediate\n";
            inst = std::make_unique<SetIImmediate>(((byte0 & 0x0F) << 8) | byte1);
        } else if ((byte0 >> 4) == 0x0B) {
            std::cout << "JumpRegister\n";
            inst = std::make_unique<JumpRegister>(((byte0 & 0x0F) << 8) | byte1);
        } else if ((byte0 >> 4) == 0x0C) {
            std::cout << "Random\n";
            inst = std::make_unique<Random>(Register(byte0 & 0x0F), byte1);
        } else if ((byte0 >> 4) == 0x0D) {
            std::cout << "Draw\n";
            inst = std::make_unique<Draw>(Register(byte0 & 0x0F), Register((byte1 & 0xF0) >> 4), byte1 & 0x0F);
        } else if ((byte0 >> 4) == 0x0E && byte1 == 0x9E) {
            std::cout << "SkipPressed\n";
            inst = std::make_unique<SkipPressed>(Register(byte0 & 0x0F));
        } else if ((byte0 >> 4) == 0x0E && byte1 == 0xA1) {
            std::cout << "SkipNotPressed\n";
            inst = std::make_unique<SkipNotPressed>(Register(byte0 & 0x0F));
        } else if ((byte0 >> 4) == 0x0E && byte1 == 0xA1) {
            std::cout << "SkipNotPressed\n";
            inst = std::make_unique<SkipNotPressed>(Register(byte0 & 0x0F));
        } else if ((byte0 >> 4) == 0x0F && (byte1 & 0xFF) == 0x07) {
            std::cout << "GetDelayTimer\n";
            inst = std::make_unique<GetDelayTimer>(Register(byte0 & 0x0F));
        } else if ((byte0 >> 4) == 0x0F && (byte1 & 0xFF) == 0x0A) {
            std::cout << "WaitKey\n";
            inst = std::make_unique<WaitKey>(Register(byte0 & 0x0F));
        } else if ((byte0 >> 4) == 0x0F && (byte1 & 0xFF) == 0x15) {
            std::cout << "SetDelayTimer\n";
            inst = std::make_unique<SetDelayTimer>(Register(byte0 & 0x0F));
        } else if ((byte0 >> 4) == 0x0F && (byte1 & 0xFF) == 0x18) {
            std::cout << "SetSoundTimer\n";
            inst = std::make_unique<SetSoundTimer>(Register(byte0 & 0x0F));
        } else if ((byte0 >> 4) == 0x0F && (byte1 & 0xFF) == 0x1E) {
            std::cout << "AddIRegister\n";
            inst = std::make_unique<AddIRegister>(Register(byte0 & 0x0F));
        } else if ((byte0 >> 4) == 0x0F && (byte1 & 0xFF) == 0x29) {
            std::cout << "SetISprite\n";
            inst = std::make_unique<SetISprite>(Register(byte0 & 0x0F));
        } else if ((byte0 >> 4) == 0x0F && (byte1 & 0xFF) == 0x33) {
            std::cout << "StoreBCD\n";
            inst = std::make_unique<StoreBCD>(Register(byte0 & 0x0F));
        } else if ((byte0 >> 4) == 0x0F && (byte1 & 0xFF) == 0x55) {
            std::cout << "StoreRegisters\n";
            inst = std::make_unique<StoreRegisters>(Register(byte0 & 0x0F));
        } else if ((byte0 >> 4) == 0x0F && (byte1 & 0xFF) == 0x65) {
            std::cout << "LoadRegisters\n";
            inst = std::make_unique<LoadRegisters>(Register(byte0 & 0x0F));
        } else {
            break;
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
