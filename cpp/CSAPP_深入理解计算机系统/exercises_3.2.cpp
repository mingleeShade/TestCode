void decodel(int *xp, int *yp, int *zp) {
    int x = *xp;
    int y = *yp;
    int z = *zp;
    *yp = x;
    *zp = y;
    *xp = z;
}

int main() {
    int x = 1;
    int y = 2;
    int z = 3;
    decodel(&x, &y, &z);
    return 0;
}
