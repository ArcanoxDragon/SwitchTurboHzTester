#pragma once

#include <switch.h>

class InputState {
public:
    InputState();

    // Current buttons
    bool btnA, btnB, btnX, btnY;

    // Previous buttons
    bool lastBtnA, lastBtnB, lastBtnX, lastBtnY;

    void read(PadState *pad);
};