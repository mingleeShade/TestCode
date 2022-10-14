#include <memory>
#include <iostream>
#include <string.h>

void test(char* src, char* dst, int size) {
    memcpy(dst, src, size);
}

int main() {
    char* c = new char[11]{0}; // 123
    for (int i = 0; i < 10; ++i) {
        c[i] = 'a' + i;
    }
    char* b = &c[1];
    test(c, b, 9);
    std::cout << "c: " << c << ", b: " << b << std::endl;

    for (int i = 0; i < 9; ++i) {
        b[i] = '0' + i;
    }
    std::cout << "c: " << c << ", b: " << b << std::endl;
    test(b, c, 9);
    std::cout << "c: " << c << ", b: " << b << std::endl;
    return 0;
}
