#include <vector>
#include "Environment.hpp"

Environment::Environment(std::vector<unsigned char>& program) {
    std::random_device rd;
    gen = std::mt19937(rd());

    spriteInds[0] = 0;
    memory[0] = 0xF0;
    memory[1] = 0x90;
    memory[2] = 0x90;
    memory[3] = 0x90;
    memory[4] = 0xF0;

    spriteInds[1] = 5;
    memory[5] = 0x20;
    memory[6] = 0x60;
    memory[7] = 0x20;
    memory[8] = 0x20;
    memory[9] = 0x70;

    spriteInds[2] = 10;
    memory[10] = 0xF0;
    memory[11] = 0x10;
    memory[12] = 0xF0;
    memory[13] = 0x80;
    memory[14] = 0xF0;

    spriteInds[3] = 15;
    memory[15] = 0xF0;
    memory[16] = 0x10;
    memory[17] = 0xF0;
    memory[18] = 0x10;
    memory[19] = 0xF0;

    spriteInds[4] = 20;
    memory[20] = 0x90;
    memory[21] = 0x90;
    memory[22] = 0xF0;
    memory[23] = 0x10;
    memory[24] = 0x10;

    spriteInds[5] = 25;
    memory[25] = 0xF0;
    memory[26] = 0x80;
    memory[27] = 0xF0;
    memory[28] = 0x10;
    memory[29] = 0xF0;

    spriteInds[6] = 30;
    memory[30] = 0xF0;
    memory[31] = 0x80;
    memory[32] = 0xF0;
    memory[33] = 0x90;
    memory[34] = 0xF0;

    spriteInds[7] = 35;
    memory[35] = 0xF0;
    memory[36] = 0x10;
    memory[37] = 0x20;
    memory[38] = 0x40;
    memory[39] = 0x40;

    spriteInds[8] = 40;
    memory[40] = 0xF0;
    memory[41] = 0x90;
    memory[42] = 0xF0;
    memory[43] = 0x90;
    memory[44] = 0xF0;

    spriteInds[9] = 45;
    memory[45] = 0xF0;
    memory[46] = 0x90;
    memory[47] = 0xF0;
    memory[48] = 0x10;
    memory[49] = 0xF0;

    spriteInds[10] = 50;
    memory[50] = 0xF0;
    memory[51] = 0x90;
    memory[52] = 0xF0;
    memory[53] = 0x90;
    memory[54] = 0x90;

    spriteInds[11] = 55;
    memory[55] = 0xE0;
    memory[56] = 0x90;
    memory[57] = 0xE0;
    memory[58] = 0x90;
    memory[59] = 0xE0;

    spriteInds[12] = 60;
    memory[60] = 0xF0;
    memory[61] = 0x80;
    memory[62] = 0x80;
    memory[63] = 0x80;
    memory[64] = 0xF0;

    spriteInds[13] = 65;
    memory[65] = 0xE0;
    memory[66] = 0x90;
    memory[67] = 0x90;
    memory[68] = 0x90;
    memory[69] = 0xE0;

    spriteInds[14] = 70;
    memory[70] = 0xF0;
    memory[71] = 0x80;
    memory[72] = 0xF0;
    memory[73] = 0x80;
    memory[74] = 0xF0;

    spriteInds[15] = 75;
    memory[75] = 0xF0;
    memory[76] = 0x80;
    memory[77] = 0xF0;
    memory[78] = 0x80;
    memory[79] = 0x80;

    unsigned int ind{ 0x200 };
    for (auto& byte : program)
        memory[static_cast<size_t>(ind++)] = byte;
    end = ind;
}

void Environment::clearDisplay() {
    for (auto& row : display)
        row.reset();
}
