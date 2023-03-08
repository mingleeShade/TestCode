#include <ctime>
#include <sys/time.h>
#pragma once

namespace toolkit
{

inline time_t get_microsecond()
{
    struct timeval tv;
    time_t t;

    if (0 == ::gettimeofday(&tv, 0))
    {
        t = tv.tv_sec * 1000 * 1000 + tv.tv_usec;
    }
    return t;
}

}
