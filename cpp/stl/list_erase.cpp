#include <list>
#include <iostream>

using namespace std;

void show(const list<int>& l)
{
    for (const auto& param : l)
    {
        cout << param << ",";
    }
    cout << endl;
}

// 编译指令：g++ list_erase.cpp -o main -fsanitize=address

int main (int argc, char* argv[])
{
    std::list<int> l = {1, 2, 3, 4, 5};
    auto it = l.begin();
    ++it;//2
    auto it2 = it;
    // ++it2;//3
    l.erase(it2);
    l.erase(it);// use after free,但是 这一行改成 ++it，不会出错
    // cout << "*it should == 4:" << *it << endl;
    show(l);
    return 0;
}
