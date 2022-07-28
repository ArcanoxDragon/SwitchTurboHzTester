#include <cstdarg>
#include <stdio.h>
#include <stdlib.h>
#include <switch.h>

#include "display.h"

#define ESC         "\x1b["

#define ansi(fmt, ...) printf(ESC fmt, ## __VA_ARGS__)

void clearScreen() {
    ansi("2J");
}

void moveCursor(int row, int column) {
    ansi("%d;%dH", row, column);
}

void setForeground(FgColor color) {
    ansi("%dm", color);
}

void setBackground(BgColor color) {
    ansi("%dm", color);
}

void setColor(FgColor foreground, BgColor background) {
    ansi("%d;%dm", foreground, background);
}

void cprintf(int col, const char *fmt, ...) {
    printf("\x0d");
    ansi("%dC", col);

    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
}

/* #region Color Helpers */

void black(const char *msg) {
    ansi("%dm%s" ESC "39m", FgColor::FgColor_Black, msg);
}

void red(const char *msg) {
    ansi("%dm%s" ESC "39m", FgColor::FgColor_Red, msg);
}

void green(const char *msg) {
    ansi("%dm%s" ESC "39m", FgColor::FgColor_Green, msg);
}

void yellow(const char *msg) {
    ansi("%dm%s" ESC "39m", FgColor::FgColor_Yellow, msg);
}

void blue(const char *msg) {
    ansi("%dm%s" ESC "39m", FgColor::FgColor_Blue, msg);
}

void magenta(const char *msg) {
    ansi("%dm%s" ESC "39m", FgColor::FgColor_Magenta, msg);
}

void cyan(const char *msg) {
    ansi("%dm%s" ESC "39m", FgColor::FgColor_Cyan, msg);
}

void white(const char *msg) {
    ansi("%dm%s" ESC "39m", FgColor::FgColor_White, msg);
}


/* #endregion Color Helpers */