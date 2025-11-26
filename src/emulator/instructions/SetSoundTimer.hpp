#pragma once
#include "../Register.hpp"
#include "../Instruction.hpp"
#include "../Environment.hpp"

class SetSoundTimer : public Instruction {
public:
    Register reg{};
    unsigned int raw;
    SetSoundTimer(Register reg, unsigned int raw) : reg{ reg }, raw{ raw } {};
    void op(Environment&) override {
        // TODO
    }
};
