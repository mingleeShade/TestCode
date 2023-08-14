#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <string>

// B.h 必须放在 A.h 之前，否则会编译不过，B.h 中的 using namespace TTT 可以让 A.h 中的 TStruct 找到命名空间 TTT 中的定义
//#include "A.h"
#include "B.h"
#include "A.h"

using namespace std;


int main()
{
    TStruct t;
    t.b = 3;
    cout << "t.b: " << Func(&t) << endl;
    return 0;
}
