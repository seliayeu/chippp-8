#pragma once
#include "../Register.hpp"
#include "../Instruction.hpp"
#include "../Environment.hpp"
#include <limits.h>
#include <iostream>

class SubFromDest : public Instruction {
public:
    const Register dest{};
    const Register source{};
    SubFromDest(Register dest, Register source) : dest{ dest }, source{ source } {};

    void op(Environment& env) override {
        unsigned int destInd{ static_cast<unsigned int>(dest) };
        unsigned int sourceInd{ static_cast<unsigned int>(source) };
        unsigned int res{ static_cast<unsigned int>(env.VRegisters[destInd] - env.VRegisters[sourceInd]) }; 

        bool setVF{ env.VRegisters[destInd] >= env.VRegisters[sourceInd] };
        env.VRegisters[destInd] = static_cast<unsigned char>(res);

        std::cout << "SUBFROMDEST" << std::endl;
        std::cout << static_cast<unsigned int>(env.VRegisters[15]) << std::endl;
        if (setVF)
            env.VRegisters[15] = 1; // set VF to 1 for carry
        else     
            env.VRegisters[15] = 0;

        std::cout << "RES" << static_cast<unsigned int>(res) << std::endl;
        std::cout << static_cast<unsigned int>(env.VRegisters[15]) << std::endl;

        env.pc += 2;
    }
};
