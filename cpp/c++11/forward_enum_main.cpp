#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <string>
#include "forward_enum.h"
#include "forward_enum_main.h"
using namespace std;

void ForwardEnumMain::TestFunc(ColorInt c)
{
    cout << "color: " << c << endl;
    return;
}

int main()
{
    ForwardEnumMain::TestFunc(CI_Red);
    return 0;
}
