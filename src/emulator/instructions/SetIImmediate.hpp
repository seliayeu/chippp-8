#pragma once
#include "../Register.hpp"
#include "../Instruction.hpp"
#include "../Environment.hpp"
#include <iostream>

class SetIImmediate : public Instruction {
public:
    const unsigned int immediate{};
    SetIImmediate(unsigned int immediate) : immediate{ immediate } {};
    void op(Environment& env) override {
        std::cout << "RI" << " = " << immediate << std::endl;
        env.IRegister = immediate;
        env.pc += 2;
    }
};
