#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <string>
#include "memory.h"
using namespace std;

int main()
{

    unsigned long long* ull = new unsigned long long [38 * 1000 * 1000];
    for (int i = 0; i < 38 * 1000 * 1000; ++i)
    {
        ull[i] = i;
    }
    print_memory_usage();

    unordered_multimap<long, long> m;

    for (int i = 0; i < 38 * 1000 * 1000; ++i)
    {
        m.insert({i, i + 1});
    }

    print_memory_usage();
    return 0;
}
