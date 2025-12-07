#pragma once
#include "../Register.hpp"
#include "../Instruction.hpp"
#include "../Environment.hpp"

class StoreBCD : public Instruction {
public:
    const Register reg{};
    StoreBCD(Register reg) : reg{ reg } {};
    void op(Environment& env) override {
        unsigned char val{ env.VRegisters[static_cast<unsigned int>(reg)] };
        env.memory[env.IRegister] = val / 100;
        val %= 100;
        env.memory[env.IRegister + 1] = val / 10;
        val %= 10;
        env.memory[env.IRegister + 2] = val;
        env.pc += 2;
    }
};
