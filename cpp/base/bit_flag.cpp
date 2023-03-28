#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
    int flag = 0;
    flag |= (1<<1);
    flag |= (1<<2);
    flag |= (1<<3);
    flag |= (1<<4);

    std::cout << "\nflag=" << flag << endl;
    flag &= ~(1<<2);
    std::cout << "\nflag=" << flag << endl;
    return 0;
}
