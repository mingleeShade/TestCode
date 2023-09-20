#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

std::string StrToHex(const std::string& strData)
{
    std::stringstream ss;
    size_t nSize = strData.length();
    ss << std::hex;
    for (size_t i = 0; i < nSize; ++i)
    {
        short w = strData.at(i);
        ss << std::setw(2) << std::setfill('0') << w;
    }
    return ss.str();
}

int main()
{
    std::string strData;
    char c[10];
    c[0] = 10;
    c[1] = 1;
    for (int i = 2; i < 9; ++i){
        c[i] = i + 3;
    }
    c[9] = 0;
    cout << StrToHex(c) << endl;
    return 0;
}
