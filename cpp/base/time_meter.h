#include <ctime>
#include <sys/time.h>

inline unsigned long get_micro_time()
{
    struct timeval tp;
    gettimeofday(&tp, NULL);
    unsigned long micro_sec = tp.tv_sec * 1000 * 1000 + tp.tv_usec;
    return micro_sec;
}
