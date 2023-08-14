#include <iostream>
#include <list>
#include <map>
#include <string>
#include <string_view>
#include <typeinfo>
#include <unordered_map>
#include <vector>

using namespace std;

template <typename Derived>
class Base
{
public:
    string GetName() const
    {
        string name = typeid(Derived).name();
        cout << "\nname: " << name << endl;
        return name;
    }
    virtual string ThisName() const
    {
        string name = typeid(*this).name();
        cout << "ThisName: " << name << endl;
        return name;
    }
    string GetClassName() const
    {
        string name = typeid(Derived).name();
        size_t pos = name.find_last_of("::");
        if (pos != string::npos)
        {
            name = name.substr(pos + 1);
        }
        if (name[0] == 'N' &&
                name.find_first_of("0123456789", 1) != string::npos)
        {
            name = name.substr(1);
        }
        cout << "ClassName: " << name << endl;
        return name;
    }

    // void ParseClassName(const string& strName, vector<string> ns, );

    virtual string ClassName() const
    {
        string name = typeid(*this).name();
        if (name[0] == 'N')
        {
        }
        return name;
    }
};

class Derived : public Base<Derived> {};

template <typename T1, typename T2, typename T3, typename T4, typename T5>
class TDerived : public Base<TDerived<T1, T2, T3, T4, T5>> {};

namespace Test
{
    class SubDerived : public Base<SubDerived> {};

    template <typename T> class TSubDerived : public Base<TSubDerived<T>> {};
    namespace XXX
    {
        class SSubDerived : public Base<SSubDerived> {};
    } // namespace XXX
} // namespace Test

int main()
{
    Derived d1;
    d1.GetName();
    d1.GetClassName();
    d1.ThisName();

    Base<Derived>* pb1 = new Derived();
    pb1->GetName();
    pb1->GetClassName();
    pb1->ThisName();

    Base<Test::SubDerived>* s1 = new Test::SubDerived();
    s1->GetName();
    s1->GetClassName();
    s1->ThisName();

    TDerived<int, long long, double, string, Derived> t1;
    t1.GetName();
    t1.GetClassName();
    t1.ThisName();

    TDerived<short, char, unsigned long, float, std::vector<int>> t2;
    t2.GetName();
    t2.GetClassName();
    t2.ThisName();

    Test::TSubDerived<int> ts1;
    ts1.GetName();
    ts1.GetClassName();
    ts1.ThisName();

    Test::XXX::SSubDerived ss1;
    ss1.GetName();
    ss1.GetClassName();
    ss1.ThisName();
    return 0;
}
