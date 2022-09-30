#include <stdio.h>
#include <stdlib.h>
#define ICE_P(x) (sizeof(int) == sizeof(*(1 ?  ((void*)((x) * 0l)) : (int*)1)))

#define VOID_PTR(x) ((void*)((x) * 0l))

int func(int a) {
    srand(0);
    a = rand() % 100;
    return a;
}

int main()
{
    printf("\n");
    if (NULL == VOID_PTR(1 + 1)) {
        printf("NULL \n");
    } else {
        printf("VOID_PTR \n");
    }

    int a = 10;
    if (NULL == VOID_PTR(func(a))) {
        printf("NULL \n");
    } else {
        printf("VOID_PTR \n");
    }
    if (ICE_P(1+1)) {
        printf("CONST \n");
    }
    if (!ICE_P(func(a))) {
        printf("Not CONST \n");
    }
    if ((1 ? NULL : 3) == NULL) {
        printf("1 ? NULL : 3  ->  NULL \n");
    } else {
        printf("1 ? NULL : 3  ->  3\n");
    }
    if ((1 ? ((void*)0) : 3) == ((void*)0)) {
        printf("1 ? ((void*)0) : 3  ->  ((void*)0)\n");
    } else {
        printf("1 ? ((void*)0) : 3  ->  3\n");
    }
    printf(sizeof(int) == sizeof(*(1 ? ((void *)0) : (int*)1)));
    printf(sizeof(int) == sizeof(*(1 ? NULL : (int*)1)));
    return 0;
}
