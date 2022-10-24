#include <stdio.h>
#include <string.h>
#include "inline_test.h"

inline  void test() {
    printf("test...");
}

int main() {
    int c = 0;
    test();
}
