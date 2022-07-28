#include <switch.h>

#include "InputState.h"

/* #region Public */

InputState::InputState() {
    btnA = btnB = btnX = btnY = false;
    lastBtnA = lastBtnB = lastBtnX = lastBtnY = false;
}

void InputState::read(PadState *pad) {
    u64 currentButtons = padGetButtons(pad);

    lastBtnA = btnA;
    lastBtnB = btnB;
    lastBtnX = btnX;
    lastBtnY = btnY;

    btnA = currentButtons & HidNpadButton_A;
    btnB = currentButtons & HidNpadButton_B;
    btnX = currentButtons & HidNpadButton_X;
    btnY = currentButtons & HidNpadButton_Y;
}

/* #endregion Public */