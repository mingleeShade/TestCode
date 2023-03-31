#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <string>
#include <typeinfo>
#include <string_view>

using namespace std;

template <typename Derived>
class Base {
public:
    string GetName() const {
        string name = typeid(Derived).name();
        cout << "\nname: " << name << endl;
        return name;
    }
    string GetClassName() const {
        string name = typeid(Derived).name();
        size_t pos = name.find_last_of("::");
        if (pos != string::npos) {
            name = name.substr(pos + 1);
        }
        if (name[0] == 'N' && name.find_first_of("0123456789", 1) != string::npos) {
            name = name.substr(1);
        }
        cout << "ClassName: " << name << endl;
        return name;
    }
    string GetViewName() const
    {
        string_view name = typeid(Derived).name();
    }
    
};

class Derived : public Base<Derived> { };

template<typename T>
class TDerived : public Base<TDerived<T> > {};

namespace Test
{
 class SubDerived : public Base<SubDerived> {};
}

int main()
{
    Derived d1;
    d1.GetName();
    d1.GetClassName();
    Test::SubDerived s1;
    s1.GetName();
    s1.GetClassName();

    TDerived<int> t1;
    t1.GetName();
    t1.GetClassName();
    return 0;
}
