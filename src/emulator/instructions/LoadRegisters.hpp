#pragma once
#include "../Register.hpp"
#include "../Instruction.hpp"
#include "../Environment.hpp"

class LoadRegisters : public Instruction {
public:
    const Register reg{};
    LoadRegisters(Register reg) : reg{ reg } {};
    void op(Environment& env) override {
        for (unsigned int i = 0; i <= static_cast<unsigned int>(reg); ++i)
            env.VRegisters[i] = env.memory[env.IRegister++];
        env.pc += 2;
    }
};
