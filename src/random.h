#ifndef RANDOM_H
#define RANDOM_H

#include <cstdlib>

class Random
{
public:
    static int rand()
    {
#ifdef WIN32
    return (rand() << 16) + rand();
#else
    return ::rand();
#endif
    }

    static int nextInt(int n) { return rand() % n; }

    static double nextDouble() { return 1.0 * rand() / (~0U>>1); }
};

#endif // RANDOM_H
