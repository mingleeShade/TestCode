#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <string>
#include <errno.h>
using namespace std;

int test_switch(int a) {
    int b = 0;
    switch (a) {
        case 1:
            b = 1 * a;
            break;
        case 100:
            b = 2 * a;
        case 10000:
            b = 4 * a;
        default:
            b = 0;
    }
    return b;
}

int test_switch2(int a, int b) {
    switch(a) {
        case 1:
            b = b * b;
            break;
        case 2:
            b = b + a;
            break;
        case 3:
            b = b / a;
            break;
        default:
            b = 0;
    }
    return b;
}

int main()
{
    int a = 10;
    a = test_switch(a);
    int b = 12;
    a = test_switch2(a, b);
    return 0;
}
