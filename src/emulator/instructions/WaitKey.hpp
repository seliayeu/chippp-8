#pragma once
#include "../Register.hpp"
#include "../Instruction.hpp"
#include "../Environment.hpp"

class WaitKey : public Instruction {
public:
    Register reg{};

    WaitKey(Register reg) : reg{ reg } {};
    void op(Environment& env) override {
        env.setWaitKey(reg);
        //TODO make it increment here instead
    }
};
