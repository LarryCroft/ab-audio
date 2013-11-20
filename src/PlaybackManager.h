#ifndef PLAYBACKMANAGER_H__
#define PLAYBACKMANAGER_H__

#include <vector>

#include <pulse/simple.h>

#include "Stream.h"

class PlaybackManager {
public:
    PlaybackManager();
    virtual ~PlaybackManager();

    void main();

    void start();

    void add(Stream* s);
    void switchTo(unsigned id);

    void addDelay(int delta);
    void addAmp(float delta);

private:
    pa_simple* paConnection;

    std::vector<Stream*> streams;

    // Playback status
    Stream* currentStream;
    unsigned sample;
};

#endif
