#pragma once
#include "../Register.hpp"
#include "../Instruction.hpp"
#include "../Environment.hpp"

class StoreRegisters : public Instruction {
public:
    const Register reg{};
    StoreRegisters(Register reg) : reg{ reg } {};
    void op(Environment& env) override {
        for (unsigned int i = 0; i <= static_cast<unsigned int>(reg); ++i)
            env.memory[env.IRegister++] = env.VRegisters[i];
        env.pc += 2;
    }
};
