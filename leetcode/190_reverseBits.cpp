#include <cstdint>
#include <iostream>

void swapBit(uint32_t& n, int index)
{
    uint32_t low = 0x1 << index;
    uint32_t high = 0x1 << (31 - index);
    low &= n;
    high &= n;
    // low >>= index;
    // high >>= (31 - index);
    n = (low > 0) ? (n | (0x1 << (31 - index))) : (n & ~(0x1 << (31 - index)));
    // std::cout << "high: " << n << std::endl;
    n = (high > 0) ? (n | (0x1 << (index))) : (n & ~(0x1 << (index)));
    // std::cout << "low: " << n << std::endl;
}

uint32_t reverseBits(uint32_t n)
{
    if (n == 0)
    {
        return n;
    }
    for (auto index = 0; index < 16; ++index)
    {
        swapBit(n, index);
    }
    return n;
}

void test(uint32_t n, uint32_t expect)
{
    uint32_t result = reverseBits(n);
    using namespace std;
    cout << "n:" << n << ", result: " << result << ", expect:" << expect << ", match:" << (result == expect) << endl;
}

int main (int argc, char* argv[])
{
    test(43261596, 964176192);
    test(4294967293, 3221225471 );
    return 0;
}
