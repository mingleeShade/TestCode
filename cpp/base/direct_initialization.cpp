#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

struct Foo {};

struct Bar {
    Bar(Foo) {}
};

Bar b(Foo()) {
    Foo f;
    Bar b(f);
    return b;
}

Foo *f () {

    Foo f;
    return &f;
}

int main()
{
    Foo f;
    Bar b2(f);
    return 0;
}
