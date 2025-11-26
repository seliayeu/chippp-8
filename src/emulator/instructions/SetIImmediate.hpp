#pragma once
#include "../Register.hpp"
#include "../Instruction.hpp"
#include "../Environment.hpp"
#include <limits.h>

class SetIImmediate : public Instruction {
public:
    const unsigned int immediate{};
    unsigned int raw;
    SetIImmediate(unsigned int immediate, unsigned int raw) : immediate{ immediate }, raw{ raw } {};
    void op(Environment& env) override {
        env.IRegister = immediate;
        env.pc += 1;
    }
};
