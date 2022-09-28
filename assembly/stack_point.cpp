int sum(int a, int b) {
    a++;
    ++b;
    return a + b;
}

int test(int a, int b) {
    --a;
    --b;
    return sum(a, b);
}

int exchange(int* xp, int y) {
    int x = *xp;
    *xp = y;
    return x;
}

int main()
{
    int a = 12;
    int b = 34;
    test(a, b);

    b = exchange(&a, b);
    return 0;
}
