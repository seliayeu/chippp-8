#pragma once
#include "../Register.hpp"
#include "../Instruction.hpp"
#include "../Environment.hpp"

class Return : public Instruction {
public:
    unsigned int raw;
    Return(unsigned int raw) : raw{ raw } {};
    void op(Environment& env) override {
        unsigned int top{ env.stack[env.sp - 1] };   
        env.sp--;
        env.pc = top;
    }
};
