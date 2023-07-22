#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <ostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <string>
#include <unistd.h>
#include "../performance/memory.h"
using namespace std;

int main()
{
    std::ofstream ss;
    ss.open("test.txt", std::ios::out | std::ios::trunc);
    std::string content;
    srand((unsigned)time(NULL));

    for (int i = 0; i < 100; ++i)
    {
        for (int j = 0; j < 20; ++j)
        {
            ss << rand() << "|||";
        }
        ss << endl;
        // ss.flush();
        if (i % 10 == 0)
        {
            print_memory_usage();
        }
        ::usleep(1000 * 1000);
    }
    ss.close();
    print_memory_usage();
    return 0;
}
