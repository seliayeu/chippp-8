#pragma once
#include "../Register.hpp"
#include "../Instruction.hpp"
#include "../Environment.hpp"

class Clear : public Instruction {
public:
    void op(Environment& env) override {
        env.clearDisplay();
        env.pc += 2;
    }
};
