#include "PlaybackManager.h"

#include <cassert>

#include <algorithm>
#include <iostream>

#include <pulse/error.h>

PlaybackManager::PlaybackManager():
    paConnection(nullptr),
    currentStream(nullptr),
    sample(0)
{
    // Create sample spec
    pa_sample_spec* ss = new pa_sample_spec();
    ss->format = PA_SAMPLE_S16NE;
    ss->channels = 2;
    ss->rate = 44100;

    int err = 0;
    paConnection = pa_simple_new(nullptr, "ab-test", PA_STREAM_PLAYBACK, nullptr, "ab-test", ss, nullptr, nullptr, &err);

    if (err != 0) {
        std::cerr << "Error connecting to pulse: " << pa_strerror(err) << std::endl;
    }
    assert(err == 0);
}

PlaybackManager::~PlaybackManager() {
    pa_simple_free(paConnection);
}

void PlaybackManager::main() {
    const long N_SAMPLES = 1024;

    int err = 0;
    Stream* myStream = currentStream;
    for (; sample < myStream->size; sample += N_SAMPLES) {
        // Thread local
        myStream = currentStream;

        size_t bytes = std::min(myStream->size - sample, N_SAMPLES);

        pa_simple_write(paConnection, myStream->data + sample, bytes, &err);

        if (err != 0) {
            std::cerr << "Error writing to pulse: " << pa_strerror(err) << std::endl;
            assert(err == 0);
            break;
        }
    }
}


void PlaybackManager::add(Stream* s) {
    streams.push_back(s);
    currentStream = s;
}

void PlaybackManager::switchTo(unsigned id) {
    if (id >= streams.size()) {
        return;
    }

    currentStream = streams[id];
}
