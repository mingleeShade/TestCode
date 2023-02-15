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
    // 上述汇编是 32 位环境下，64 位环境下，pushl 和 popl 应该改为 pushq 和 popq，
    // 因此干脆将所有指令和寄存器都改为 64 位的
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
