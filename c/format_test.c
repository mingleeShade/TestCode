#include <stdio.h>
#include <stdbool.h>

#define ser(ss) \
    if (ss == 1) \
    { \
        ss = 2; \
    }

int main(void)
{
    if (true) {
        if (!true) {
            ;
        }
    }
    return 0;
}
