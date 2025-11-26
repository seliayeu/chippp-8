#pragma once
#include "../Register.hpp"
#include "../Instruction.hpp"
#include "../Environment.hpp"

class SetISprite : public Instruction {
public:
    Register reg{};
    unsigned int raw;
    SetISprite(Register reg, unsigned int raw) : reg{ reg }, raw{ raw } {};
    void op(Environment& env) override {
        env.IRegister = env.spriteInds[env.VRegisters[static_cast<unsigned int>(reg)]];
        env.pc += 1;
    }
};
