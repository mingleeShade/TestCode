#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

long long pop_test(long long tval) {
    long long rval = 0;
    /*
     * Insert the following assembly code:
     * pushl tval           # Save tval on stack
     * movl %esp,%edx       # Save stack pointer
     * popl %esp            # Pop on stack pointer
     * movl %esp,rval       # Set popped value as return value
     * movl %edx,%esp       # Restore original stack pointer
     */
    // 上述注释是原书中所述，但实际上有问题， Save %esp 寄存器的指令需要提到最前面，
    // 否则 rsp 的值将出现混乱，导致后续退出函数的时候，出栈时会跳转到错误的地方，进而导致宕机
    asm("movq %%rsp,%%rdx; pushq %1; popq %%rsp; movq %%rsp,%0; movq %%rdx,%%rsp"
        : "=r" (rval)  /* Outputs */
        : "r" (tval)
        : "%rdx");
    return rval;
}

int main()
{
    /* TODO:   <1月 16, 2023, lihaiming> */
    cout << "\nresult: " << pop_test(1) << endl;
    return 0;
}
