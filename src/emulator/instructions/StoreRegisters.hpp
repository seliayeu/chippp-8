#pragma once
#include "../Register.hpp"
#include "../Instruction.hpp"
#include "../Environment.hpp"

class StoreRegisters : public Instruction {
public:
    unsigned int raw;
    const Register reg{};
    StoreRegisters(unsigned int raw, Register reg) : raw{ raw }, reg{ reg } {};
    void op(Environment& env) override {
        for (unsigned int i = 0; i <= static_cast<unsigned int>(reg); ++i)
            env.VRegisters[i] = env.memory[env.IRegister++];
        env.pc += 1;
    }
};
