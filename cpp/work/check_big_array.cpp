#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <string>
#include "check_big_array.h"
#include "../../../../hgame/h-opserver/xsdk/xString.h"
using namespace std;

int main()
{
    size_t nSize0 = sizeof(x::gbk2utf8) / sizeof(uint32_t);
    size_t nSize1 = sizeof(gbk2utf8_1) / sizeof(uint32_t);
    cout << "\nsize0: " << nSize0 << ", size: " << nSize1 << endl;
    if (nSize0 != nSize1) {
        cout << "size not match!!!!" << endl;
    }

    bool all_match = true;
    for (int i = 0; i < nSize0; ++i)
    {
        if (x::gbk2utf8[i] != gbk2utf8_1[i]) {
            cout << "value not match!!!!!" << endl;
            all_match = false;
        }
    }
    cout << "all_match: " << all_match << endl;
    return 0;
}
