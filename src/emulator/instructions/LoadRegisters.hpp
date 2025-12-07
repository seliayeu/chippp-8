#pragma once
#include "../Register.hpp"
#include "../Instruction.hpp"
#include "../Environment.hpp"

class LoadRegisters : public Instruction {
public:
    unsigned int raw;
    const Register reg{};
    LoadRegisters(unsigned int raw, Register reg) : raw{ raw }, reg{ reg } {};
    void op(Environment& env) override {
        for (unsigned int i = 0; i <= static_cast<unsigned int>(reg); ++i)
            env.memory[env.IRegister++] = env.VRegisters[i];
        env.pc += 2;
    }
};
