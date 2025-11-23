#pragma once
#include "../Register.hpp"
#include "../Instruction.hpp"
#include "../Environment.hpp"

class Clear : public Instruction {
public:
    unsigned int raw{ 0x00EE };
    Clear(unsigned int raw) : raw{ raw } {};
    void op(Environment& env) override {
        env.clearDisplay();
        env.pc += 1;
    }
};
