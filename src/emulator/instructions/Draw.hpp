#pragma once
#include "../Register.hpp"
#include "../Instruction.hpp"
#include "../Environment.hpp"
#include <iostream>

class Draw : public Instruction {
public:
    const Register reg1{};
    const Register reg2{};
    unsigned char nibble;
    Draw(Register reg1, Register reg2, unsigned char nibble) : reg1{ reg1 }, reg2{ reg2 }, nibble{ nibble } {};
    void op(Environment& env) override {
        unsigned int x{ env.VRegisters[static_cast<unsigned int>(reg1)] };
        unsigned int y{ env.VRegisters[static_cast<unsigned int>(reg2)] };

        env.FRegister = 0;
        std::cout << "Drawing " << static_cast<unsigned int>(nibble) << " bytes starting from memory address " << env.IRegister << " to coordinates (" << x << ", " << y << ")" << std::endl;

        for (unsigned char i = 0; i < nibble; ++i) {
            unsigned char rowValues{ env.memory[env.IRegister + i]};
            auto& row{ env.display[y + i] };

            for (unsigned char j = 0; j < 8; ++j) {
                bool bit{ static_cast<bool>((rowValues >> (7 - j)) & 1 )};
                env.FRegister = (row[x + j] & bit) ? 1 : env.FRegister;
                row.set(x + j, row[x + j] ^ bit);
            }
        }

        env.pc += 2;
    }
};
