#ifndef CLI_H__
#define CLI_H__

#include "PlaybackManager.h"

class Cli {
public:
    Cli(PlaybackManager& pm);

    void main();

private:
    PlaybackManager& pm;   
};

#endif
