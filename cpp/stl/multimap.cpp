#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
    multimap<int, int> m;
    m.insert({1, 10});
    m.insert({1, 12});
    m.insert({2, 10});
    m.insert({4, 10});
    for (auto pair : m)
    {
        cout << pair.first << ":" << pair.second << endl;
    }
    return 0;
}
