#pragma once

#include "qstring.h"
#include "screen.h"
#include "keyboard.h"

const int MEM_SIZE = 32 * 1024;
const int REG_AMOUNT = 8;

class Vcpu
{
    public:
        Vcpu();
        ~Vcpu();

        bool n, z, v, c;

        uint16_t    getRegValue(uint16_t numReg);
        void        setRegValue(uint16_t numReg, uint16_t value);
        uint16_t*    getRegAddr(uint16_t numReg);
        uint16_t    getMemValue(uint16_t address);
        uint16_t*    getMemAddr(uint16_t address);
        void        setMemValue(uint16_t address, uint16_t value);
        bool        getMemString(QString& str, uint16_t address = 0);
        bool        getDisasmString(QString& str, uint16_t address = 0);
        bool        reset();
        bool        getFlag(uint16_t flagNum);

        uchar* getFrameBuffer();

    private:
        uint16_t* reg0_;
        uint16_t* reg1_;
        uint16_t* reg2_;
        uint16_t* reg3_;
        uint16_t* reg4_;
        uint16_t* reg5_;
        uint16_t* reg6_;
        uint16_t* reg7_;

        uchar frameBuffer_[SCREEN_WIDTH * SCREEN_HEIGHT];

        uint16_t memory_[MEM_SIZE + REG_AMOUNT];

        Keyboard keyboard = Keyboard("./img/font.bmp");
};
