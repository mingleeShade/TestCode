#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

#define ENUM_TO_DESC(ENUM) (std::to_string(ENUM) + "["+ #ENUM + "]")

enum Color
{
    Color_White = 0,
    Color_Blue  = 1,
};

int main()
{
    /* TODO:   <3月 13, 2023, lihaiming> */
    std::cout << "\nColor: "<< ENUM_TO_DESC(Color_White) << endl;
    Color c = Color_Blue;
    std::cout << "\nColor: "<< ENUM_TO_DESC(c) << endl;
    return 0;
}
