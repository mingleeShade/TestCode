#include <map>
#include <string>

#include "memory.h"


int main()
{
    std::map<unsigned long long, unsigned int> m;

    for (int i = 0; i < 38 * 1000 * 1000; ++i )
    {
        m[i] = i + 1;
    }

    print_memory_usage();
}
