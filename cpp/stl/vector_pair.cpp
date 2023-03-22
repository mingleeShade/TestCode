#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
    vector<pair<int, int>> t;
    t.emplace_back(10, 3);
    t.push_back({2, 10});
    auto& t1 = t.at(0);
    std::cout << "\nfirst: " << t1.first << ", second:" << t1.second << endl;
    return 0;
}
