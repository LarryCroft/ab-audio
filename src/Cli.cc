#include "Cli.h"

#include <iostream>

const float SEEK_TIME_SHORT = 3;
const float SEEK_TIME_LONG = 30;

Cli::Cli(PlaybackManager& pm):
    pm(pm)
{
}

void Cli::main() {
    std::string cmd;
    while (true) {
        std::cout << "> " << std::flush;
        std::cin >> cmd;

        // Switch streams
        if (cmd == "s") {
            unsigned id;
            std::cin >> id;
            
            if (std::cin) {
                pm.switchTo(id);
            }
            else {
                std::cin.clear();
            }
        }
        // Seek
        else if (cmd == "h") {
            pm.seek(-SEEK_TIME_LONG);
        }
        else if (cmd == "j") {
            pm.seek(-SEEK_TIME_SHORT);
        }
        else if (cmd == "k") {
            pm.seek(-SEEK_TIME_SHORT);
        }
        else if (cmd == "l") {
            pm.seek(SEEK_TIME_LONG);
        }
        // Delay
        else if (cmd == "d") {
            int delta;
            std::cin >> delta;

            if (std::cin) {
                //pm.addDelay(delta);
            }
            else {
                std::cin.clear();
            }
        }
        // Volume
        else if (cmd == "v") {
            float delta;
            std::cin >> delta;

            if (std::cin) {
                //pm.addAmp(delta);
            }
            else {
                std::cin.clear();
            }
        }
        // Quit
        else if (cmd == "q") {
            pm.stop();
            return;
        }
        else {
            std::cerr << "Unknown command: " << cmd << std::endl;
        }
    }
}
