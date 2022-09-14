// 演示汇编代码

int accum = 0;

int sum (int x, int y) {
    int t = x + y;
    accum += t;
    return t;
}

// int main() {
//     int x = 0;
//     int y = 0;
//     cin >> x;
//     cin >> y;
//     sum(x, y);
//     return 0;
// }
