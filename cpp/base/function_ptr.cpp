#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

void test()
{
    return;
}

class Activity
{
public:
    bool TestFunc()
    {
        cout << "TestFunc" << endl;
        return true;
    }
};

template<typename T>
class Table
{
public:
    using Action = bool (T::*)();

    Table(T* t) : m_t(t) {}

    void RegisterFunc(Action a)
    {
        m_a = a;
    }

    void Call()
    {
        (m_t->*(m_a))();
    }

    void Call2()
    {
        //*(m_a)();
    }

    Action m_a;
    T* m_t;
};

int main()
{
    Activity a;
    Table<Activity> t(&a);
    t.RegisterFunc(&Activity::TestFunc);

    t.Call();
    t.Call2();

    int c = 1;
    if (c == 1)
    {
        cout << "2" << endl;
    }
    switch (c)
    {
        case 1:
        {
            std::cout << "1" << endl;
        }
        default:
        {
            std::cout << "default" << endl;
        }
    }

    return 0;
}
