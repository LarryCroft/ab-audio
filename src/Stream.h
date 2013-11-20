#ifndef STREAM_H__
#define STREAM_H__

class Stream {
public:
    Stream(long size);

    char* data;
    long size;

    float amp;
    int offset;
};

Stream* loadStreamFromWav(const char* path);

#endif
