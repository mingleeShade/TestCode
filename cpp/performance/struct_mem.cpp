#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unistd.h>
#include <unordered_map>
#include <string>
#include "memory.h"
#include "../base/time_meter.h"

using namespace std;

struct ca1
{
    unsigned long long a1 = 0;
    unsigned int a2 = 0;
};

#pragma pack(push, 4)
struct ca2
{
    unsigned long long a1;
    unsigned int a2;
};
#pragma pack(pop)

struct ca3
{
    unsigned int a1 = 0;
    unsigned int a2 = 0;
    unsigned int a3 = 0;
};

int main()
{
    cout << "sizeof(a1): " << sizeof(ca1) << ", sizeof(ca2): " << sizeof(ca2)
         << ", sizeof(ca3): " << sizeof(ca3) << endl;

    int N = 1000000;

    print_memory_usage();
    ca1* p1 = new ca1[N];
    for (int i = 0; i < N; ++i)
    {
        p1[i].a1 = i;
    }
    // ::usleep(1000 * 1000);
    print_memory_usage();

    ca2* p2 = new ca2[N];
    for (int i = 0; i < N; ++i)
    {
        p2[i].a1 = i;
    }
    print_memory_usage();

    ca3* p3 = new ca3[N];
    for (int i = 0; i < N; ++i)
    {
        p3[i].a1 = i + 1;
        p3[i].a2 = i * i;
        p3[i].a3 = i * 2 + i;
    }
    // ::usleep(1000 * 1000);
    print_memory_usage();

    auto begin_time = get_micro_time();
    for (int i = 0; i < N; ++i)
    {
        p1[i].a2 = i * i;
    }
    auto end_time = get_micro_time();
    std::cout << "cost of p1: " << end_time - begin_time << endl;

    begin_time = get_micro_time();
    for (int i = 0; i < N; ++i)
    {
        p2[i].a2 = i * i;
    }
    end_time = get_micro_time();
    std::cout << "cost of p2: " << end_time - begin_time << endl;

    begin_time = get_micro_time();
    for (int i = 0; i < N; ++i)
    {
        p3[i].a2 = i * i;
    }
    end_time = get_micro_time();
    std::cout << "cost of p3: " << end_time - begin_time << endl;

    delete[] p1;
    delete[] p3;
    return 0;
}
