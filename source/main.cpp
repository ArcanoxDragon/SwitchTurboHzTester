// Include the most common headers from the C standard library
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Include the main libnx system header, for Switch development
#include <switch.h>

#include "Application.h"

// Main program entrypoint
int main(int argc, char *argv[]) {
    consoleInit(NULL);

    // Initialize application
    Application app;
    app.initialize();

    // Main loop
    while (appletMainLoop()) {
        if (!app.update())
            break;

        // Update the console, sending a new frame to the display
        consoleUpdate(NULL);
    }

    // Deinitialize and clean up resources used by the console (important!)
    consoleExit(NULL);
    return 0;
}
