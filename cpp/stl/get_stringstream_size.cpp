#include <iostream>
#include <sstream>

#include "../base/time_meter.h"

using namespace std;

int main (int argc, char* argv[])
{
    stringstream ss;
    for (int i = 0; i < 1024; ++i)
    {
        ss << "0123456789";
    }
    int pos = ss.tellp();
    std::cout << "ss size:" << pos << endl;

    unsigned long begin = get_micro_time();
    for (int i = 0; i < 100; ++i)
    {
        ss.tellp();
    }
    unsigned long end = get_micro_time();
    std::cout << "tellp 100 times cost:" << end - begin << endl;


    begin = get_micro_time();
    for (int i = 0; i < 500; ++i)
    {
        ss.tellp();
    }
    end = get_micro_time();
    std::cout << "tellp 500 times cost:" << end - begin << endl;

    begin = get_micro_time();
    for (int i = 0; i < 1000; ++i)
    {
        ss.tellp();
    }
    end = get_micro_time();
    std::cout << "tellp 1000 times cost:" << end - begin << endl;


    begin = get_micro_time();
    for (int i = 0; i < 1000; ++i)
    {
        ss.str().size();
    }
    end = get_micro_time();
    std::cout << "str().size() 1000 times cost:" << end - begin << endl;
    return 0;
}
