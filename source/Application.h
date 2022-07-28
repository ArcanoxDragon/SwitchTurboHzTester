#pragma once

#include <switch.h>

#include "InputCounter.h"
#include "InputState.h"

class Application {
public:
    void initialize();
    bool update();

private:
    PadState pad;
    InputState inputState;
    InputCounter counterOneSec, counterFiveSec, counterTenSec;
    u64 pressedButtons;

    void initializeInput();
    void updateInput();
    bool shouldExit();
    void printUI();
};