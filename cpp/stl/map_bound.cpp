#include <map>
#include <iostream>

using namespace std;

int main()
{
    std::map<int, int> m;
    m[10] = 1;
    m[20] = 2;
    m[30] = 3;

    auto it = m.lower_bound(11);
    std::cout << "lower_bound 11: " << it->first << endl;
    it = m.upper_bound(11);
    std::cout << "upper_bound 11: " << it->first << endl;

    it = m.lower_bound(20);
    std::cout << "lower_bound 20: " << it->first << endl;
    it = m.upper_bound(20);
    std::cout << "upper_bound 20: " << it->first << endl;

    it = m.lower_bound(1);
    if (it == m.end())
    {
        cout << "lower_bound 1 not found" << endl;
    }
    else
    {
        cout << "lower_bound 1: " << it->first << endl;
    }

    it = m.upper_bound(30);
    if (it == m.end())
    {
        cout << "upper_bound 30 not found" << endl;
    }
}
