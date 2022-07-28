#include "InputCounter.h"
#include "InputState.h"
#include "utils.h"

/* #region Public */

InputCounter::InputCounter() {
    currentTime = lastReset = gettime();
    lastDownA = lastDownB = lastDownX = lastDownY = currentTime;
    instantHzA = instantHzB = instantHzX = instantHzY = 0.0;
    countDownA = countDownB = countDownX = countDownY = 0;
}

void InputCounter::update(InputState *state) {
    currentTime = gettime();

    if (state->btnA && !state->lastBtnA) {
        instantHzA = msToHz(currentTime - lastDownA);
        lastDownA = currentTime;
        countDownA++;
    }

    if (state->btnB && !state->lastBtnB) {
        instantHzB = msToHz(currentTime - lastDownB);
        lastDownB = currentTime;
        countDownB++;
    }

    if (state->btnX && !state->lastBtnX) {
        instantHzX = msToHz(currentTime - lastDownX);
        lastDownX = currentTime;
        countDownX++;
    }

    if (state->btnY && !state->lastBtnY) {
        instantHzY = msToHz(currentTime - lastDownY);
        lastDownY = currentTime;
        countDownY++;
    }
}

void InputCounter::reset() {
    averageHzA = getAverageHzA();
    averageHzB = getAverageHzB();
    averageHzX = getAverageHzX();
    averageHzY = getAverageHzY();

    countDownA = 0;
    countDownB = 0;
    countDownX = 0;
    countDownY = 0;

    lastReset = gettime();
}

double InputCounter::elapsedTime() {
    return (currentTime - lastReset) / 1000.0;
}

/* #endregion Public */

/* #region Private */

double InputCounter::getAverageHzA() {
    return getAverageHz(countDownA);
}

double InputCounter::getAverageHzB() {
    return getAverageHz(countDownB);
}

double InputCounter::getAverageHzX() {
    return getAverageHz(countDownX);
}

double InputCounter::getAverageHzY() {
    return getAverageHz(countDownY);
}

double InputCounter::getAverageHz(u64 count) {
    u64 timeSpan = currentTime - lastReset;

    if (timeSpan < 0) {
        return 0;
    }

    return count / (timeSpan / 1000.0);
}

/* #endregion Private */