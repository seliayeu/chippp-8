#pragma once
#include "../Instruction.hpp"
#include "../Environment.hpp"

class Return : public Instruction {
public:
    Return() {};
    void op(Environment& env) override {
        unsigned int top{ env.stack[--env.sp] };   
        env.pc = top;
    }
};
