#pragma once
#include "../Register.hpp"
#include "../Instruction.hpp"
#include "../Environment.hpp"

#include <iostream>

class StoreByte : public Instruction {
public:
    const Register dest{};
    const unsigned char byte{};
    StoreByte(Register dest, unsigned char byte) : dest{ dest }, byte{ byte }  {};
    void op(Environment& env) override {
        unsigned int destInd{ static_cast<unsigned int>(dest) };
        std::cout << "R" << destInd << " = " << static_cast<unsigned int>(byte) << std::endl;
        env.VRegisters[destInd] = byte;
        env.pc += 2;
    }
};
