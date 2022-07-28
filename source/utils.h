#pragma once

#include <climits>
#include <stdio.h>
#include <switch.h>

#define DBG(msg, ...) printf("%s:%d: " msg "\n", __FILE__, __LINE__, ##__VA_ARGS__); consoleUpdate(NULL)

#define gettime_ns() armTicksToNs(armGetSystemTick())
#define gettime_us() (gettime_ns() / 1000LL)
#define gettime() (gettime_us() / 1000LL)

#define msToHz(ms) ((ms) < __DBL_EPSILON__ ? 0 : (1000.0 / (ms)))