#include <ctime>
#include <sys/time.h>
#include <vector>
#include <iostream>

unsigned long get_micro_time()
{
    struct timeval tp;
    gettimeofday(&tp, NULL);
    unsigned long micro_sec = tp.tv_sec * 1000 * 1000 + tp.tv_usec;
    return micro_sec;
}

int main()
{
    /* TODO:   <Dec 08, 2022, lihaiming> */

    std::vector<int> v;
    for (int i = 0; i < 100000; ++i)
    {
        v.push_back(i * 2);
    }

    unsigned long long total = 0;
    auto begin = get_micro_time();
    for (auto value : v)
    {
        total += value;
    }
    auto end = get_micro_time();

    std::cout << "cost: " << end - begin << ", total: " << total << std::endl;
}
