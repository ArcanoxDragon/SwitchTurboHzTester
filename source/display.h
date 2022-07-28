#pragma once

typedef enum {
	FgColor_Black = 30,
	FgColor_Red = 31,
	FgColor_Green = 32,
	FgColor_Yellow = 33,
	FgColor_Blue = 34,
	FgColor_Magenta = 35,
	FgColor_Cyan = 36,
	FgColor_White = 37,
} FgColor;

typedef enum {
	BgColor_Black = 40,
	BgColor_Red = 41,
	BgColor_Green = 42,
	BgColor_Yellow = 43,
	BgColor_Blue = 44,
	BgColor_Magenta = 45,
	BgColor_Cyan = 46,
	BgColor_White = 47,
} BgColor;

void clearScreen();
void moveCursor(int row, int column);
void setForeground(FgColor color);
void setBackground(BgColor color);
void setColor(FgColor foreground, BgColor background);

void cprintf(int col, const char* fmt, ...);

void black(const char* msg);
void red(const char* msg);
void green(const char* msg);
void yellow(const char* msg);
void blue(const char* msg);
void magenta(const char* msg);
void cyan(const char* msg);
void white(const char* msg);