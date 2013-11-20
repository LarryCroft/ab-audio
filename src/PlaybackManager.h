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

    /**
     * Global playback control
     */
    void start();
    void stop();
    void seek(float dt);

    void add(Stream* s);
    void switchTo(unsigned id);

    /**
     * Control the current stream
     */
    void addDelay(int delta);
    void addAmp(float delta);

private:
    pa_simple* paConnection;

    std::vector<Stream*> streams;

    // Playback status
    Stream* currentStream;
    bool play;
    unsigned sample;
};

#endif
