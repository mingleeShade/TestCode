/**
 * @file        variadic_templates.cpp
 * @date        Feb 15, 2023
 * @author      lihaiming
 * @maintainer  lihaiming
 * @brief       可变参数模板测试
*/

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;


// template<typename... ParamList>
// void test_param(ParamList... args)
// {
//     cout << "Param ... " << endl;
//     return test_param(args...);
// }

template<typename Last>
void test_param(Last l) {
    cout << "Last: " << l << endl;
}

template<typename First, typename... ParamList>
void test_param(First f, ParamList... args)
{
    cout << "First: " << f << endl;
    return test_param(args...);
}


int main()
{
    cout << "Program begin" << endl;
    cout << "============= test: 1==============" << endl;
    test_param(1);
    cout << "============= test: 1==============" << endl << endl;


    cout << "============= test: 2==============" << endl;
    test_param(1, 2);
    cout << "============= test: 2==============" << endl << endl;

    cout << "============= test: 3==============" << endl;
    test_param(1, 2, 3);
    cout << "============= test: 3==============" << endl << endl;

    cout << "============= test: 4==============" << endl;
    test_param(1, 2, 3, 4);
    cout << "============= test: 4==============" << endl << endl;

    cout << "============= test: 5==============" << endl;
    test_param(1, 2, 3, 4, 5);
    cout << "============= test: 5==============" << endl << endl;

    cout << "Program end" << endl;
    return 0;
}
