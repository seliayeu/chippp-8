#pragma once
#include "../Register.hpp"
#include "../Instruction.hpp"
#include "../Environment.hpp"

class SetISprite : public Instruction {
public:
    Register reg{};
    SetISprite(Register reg) : reg{ reg } {}
    void op(Environment& env) override {
        env.IRegister = env.spriteInds[env.VRegisters[static_cast<unsigned int>(reg)]];
        env.pc += 2;
    }
};
