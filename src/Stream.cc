#include "Stream.h"

#include <cstdio>

Stream::Stream(long size):
    data(new char[size]),
    size(size),
    amp(1),
    offset(0)
{
}

Stream* loadStreamFromWav(const char* path) {
    FILE* fp = fopen(path, "rb");

    // Read file size
    fseek(fp, 0, SEEK_END);
    long int size = ftell(fp);
    rewind(fp);

    // Read file contents
    Stream* s = new Stream(size);
    long read = fread(s->data, 1, size, fp);

    // Check for errors
    if (read != size) {
        delete s;
        s = nullptr;
    }

    fclose(fp);

    return s;
}
