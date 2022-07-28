#include <stdio.h>
#include <time.h>

#include "Application.h"
#include "display.h"
#include "utils.h"

/* #region Public */

void Application::initialize() {
    initializeInput();
}

bool Application::update() {
    updateInput();

    if (pressedButtons & HidNpadButton_Minus) {
        // Reset input counters
        counterOneSec.reset();
        counterFiveSec.reset();
        counterTenSec.reset();
    }

    if (counterOneSec.elapsedTime() > 1.0) {
        counterOneSec.reset();
    }

    if (counterFiveSec.elapsedTime() > 5.0) {
        counterFiveSec.reset();
    }

    if (counterTenSec.elapsedTime() > 10.0) {
        counterTenSec.reset();
    }

    printUI();

    return !shouldExit();
}

/* #endregion Public */

/* #region Private */

void Application::initializeInput() {
    padConfigureInput(1, HidNpadStyleSet_NpadStandard);
    padInitializeDefault(&pad);
}

void Application::updateInput() {
    padUpdate(&pad);
    pressedButtons = padGetButtonsDown(&pad);

    inputState.read(&pad);
    counterOneSec.update(&inputState);
    counterFiveSec.update(&inputState);
    counterTenSec.update(&inputState);
}

bool Application::shouldExit() {
    return pressedButtons & HidNpadButton_Plus;
}

void Application::printUI() {
    PrintConsole *console =consoleGetDefault();

    clearScreen();
    printf("Currently pressed buttons:\t\t\t(time: %7.3fs)\n", gettime() / 1000.0);

    printf("\tA: ");
    inputState.btnA ? green("YES") : red("NO");
    printf("\n");

    printf("\tB: ");
    inputState.btnB ? green("YES") : red("NO");
    printf("\n");

    printf("\tX: ");
    inputState.btnX ? green("YES") : red("NO");
    printf("\n");

    printf("\tY: ");
    inputState.btnY ? green("YES") : red("NO");
    printf("\n");

    moveCursor(8, 1);
    printf("Instantaneous Hz:\n");
    printf("\tA: %4.1f\n", counterOneSec.instantHzA);
    printf("\tB: %4.1f\n", counterOneSec.instantHzB);
    printf("\tX: %4.1f\n", counterOneSec.instantHzX);
    printf("\tY: %4.1f\n", counterOneSec.instantHzY);

    moveCursor(8, 20);
    cprintf(20, "1s Average Hz:\n");
    cprintf(20, "\tA: %4.1f\n", counterOneSec.averageHzA);
    cprintf(20, "\tB: %4.1f\n", counterOneSec.averageHzB);
    cprintf(20, "\tX: %4.1f\n", counterOneSec.averageHzX);
    cprintf(20, "\tY: %4.1f\n", counterOneSec.averageHzY);

    moveCursor(8, 40);
    cprintf(40, "5s Average Hz:\n");
    cprintf(40, "\tA: %4.1f\n", counterFiveSec.averageHzA);
    cprintf(40, "\tB: %4.1f\n", counterFiveSec.averageHzB);
    cprintf(40, "\tX: %4.1f\n", counterFiveSec.averageHzX);
    cprintf(40, "\tY: %4.1f\n", counterFiveSec.averageHzY);

    moveCursor(8, 40);
    cprintf(60, "10s Average Hz:\n");
    cprintf(60, "\tA: %4.1f\n", counterTenSec.averageHzA);
    cprintf(60, "\tB: %4.1f\n", counterTenSec.averageHzB);
    cprintf(60, "\tX: %4.1f\n", counterTenSec.averageHzX);
    cprintf(60, "\tY: %4.1f\n", counterTenSec.averageHzY);

    moveCursor(console->consoleHeight - 1, 1);
    printf("Press - to reset averages\n");
    printf("Press + to exit");
}

/* #endregion Private */