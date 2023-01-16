#include <stdio.h>

long long push_test()
{
    long long rval;
    /*
     * Insert the following assembly code:
     * movl %esp, %eax      # Save stack pointer
     * pushl %esp           # Push stack pointer
     * popl %edx            # Pop it back
     * subl %edx, %eax      # 0 or 4
     * movl %eax, rval      # Set as return value
     */
    asm("movq %%rsp,%%rax;pushq %%rsp;popq %%rdx;subq %%rdx,%%rax;movq %%rax,%0"
        : "=r" (rval)
        : /* No Input */
        : "%rdx", "%rax");
    return rval;
}

int main()
{
    printf("test result: %lld", push_test());
    return 0;
}
