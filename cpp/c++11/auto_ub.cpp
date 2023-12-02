#include <vector>
#include <iostream>

std::vector<bool> vec;

std::vector<bool> features()
{
    return vec;
}

void process_flag(bool flag)
{
    std::cout << "flag=" << flag << std::endl;
}

int main()
{
    for (int i = 0; i < 10; i++)
    {
        vec.emplace_back(true);
    }

    //bool flag = features()[5];        // 1
    auto flag = features()[5];          // 2
    process_flag(flag);
    return 0;
}
