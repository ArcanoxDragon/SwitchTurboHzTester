#pragma once

#include "InputState.h"

class InputCounter {
public:
    InputCounter();

    // Times
    u64 currentTime, lastReset;
    u64 lastDownA, lastDownB, lastDownX, lastDownY;
    double averageHzA, averageHzB, averageHzX, averageHzY;
    double instantHzA, instantHzB, instantHzX, instantHzY;

    // Counts
    u32 countDownA, countDownB, countDownX, countDownY;

    void update(InputState *state);
    void reset();
    double elapsedTime();

private:
    double getAverageHzA();
    double getAverageHzB();
    double getAverageHzX();
    double getAverageHzY();

    double getAverageHz(u64 count);
};