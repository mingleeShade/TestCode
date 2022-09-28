#include <array>
#include <experimental/array>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

void TestFunc(std::array<char, 4> c)
{
}

void TestBase(char* c)
{
    TestFunc(std::to_array<char>(c));
}

int main()
{
    char c[4] = "123";
    TestBase(c);
    return 0;
}
