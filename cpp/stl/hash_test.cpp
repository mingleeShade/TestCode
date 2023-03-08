#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <string>
#include "../../toolkit/time.hpp"

using namespace std;


bool test()
{
    unordered_map<int, int> um;
    map<int, int> mm;

    cout << "\nInput run_times: ";
    int run_times = 0;
    std::cin >>  run_times;

    if (run_times <= 0)
    {
        return false;
    }

    time_t begin = toolkit::get_microsecond();
    for (int i = 0; i < run_times; ++i)
    {
        um[i] = i * 10;
    }
    time_t end = toolkit::get_microsecond();

    cout << "[Hash] cost time: " << end - begin << endl;


    time_t cbegin = toolkit::get_microsecond();
    for (int i = 0; i < run_times; ++i)
    {
        mm[i] = i * 10;
    }
    time_t cend = toolkit::get_microsecond();
    cout << "[Map] cost time: " << cend - cbegin << endl;
    return true;
}


int main()
{
    while (test()) {
        // do nothing
    }
    return 0;
}
