#include <cstdint>
#include <iostream>

int hammingWeight(uint32_t n)
{
    int weight = 0;
    while (n > 0)
    {
        uint32_t n_1 = n - 1;
        n = n & n_1;
        ++weight;
    }
    return weight;
}

int main (int argc, char* argv[])
{
    std::cout << hammingWeight(0b0101) << std::endl;
    std::cout << hammingWeight(0b010111) << std::endl;
    return 0;
}
