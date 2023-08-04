#ifndef TIME_C
#define TIME_C

#include <time.h>

/**
 * Get the current time in nanoseconds
 *
 * @return long
 */
long get_time()
{
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);

    return ts.tv_nsec;
}

#endif // TIME_C