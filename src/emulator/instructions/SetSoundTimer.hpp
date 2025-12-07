#pragma once
#include "../Register.hpp"
#include "../Instruction.hpp"
#include "../Environment.hpp"

class SetSoundTimer : public Instruction {
public:
    Register reg{};

    SetSoundTimer(Register reg) : reg{ reg } {};
    void op(Environment& env) override {
        env.soundRegister = env.VRegisters[static_cast<unsigned int>(reg)];
        env.pc += 2;
    }
};
