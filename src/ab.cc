#include <iostream>
#include <string>

#include "Cli.h"
#include "PlaybackManager.h"
#include "Stream.h"

void* pmMain(void* args) {
    PlaybackManager* pm = static_cast<PlaybackManager*>(args);
    pm->main();

    return nullptr;
}

int main(int argc, char* argv[]) {
    PlaybackManager pm;

    // Load input files
    for (int i = 1; i < argc; ++i) {
        Stream* s = loadStreamFromWav(argv[i]);
        pm.add(s);
    }

    // Start playback
    pthread_t pmThread;
    pthread_create(&pmThread, nullptr, &pmMain, &pm);

    // Start CLI
    Cli cli(pm);
    cli.main();
}
