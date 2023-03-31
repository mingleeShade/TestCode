#include <iostream>
#include <memory>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <string>
#include <complex>
using namespace std;

#define n(t) (#t)

template <typename T>
void print_type() {
    std::cout << typeid(T).name() << '\n';
}

int main() {
    print_type<bool>();
    print_type<char>();
    print_type<signed char>();
    print_type<unsigned char>();
    print_type<short>();
    print_type<unsigned short>();
    print_type<int>();
    print_type<unsigned int>();
    print_type<long>();
    print_type<unsigned long>();
    print_type<long long>();
    print_type<unsigned long long>();
    print_type<float>();
    print_type<double>();
    print_type<long double>();
    print_type<std::string>();
    print_type<std::complex<float>>();
    print_type<std::complex<double>>();
    print_type<std::complex<long double>>();
    print_type<std::allocator<char>>();
    return 0;
}
