#include <iostream>
#include <vector>

bool IsPalindrome(int x)
{
    if (x < 0)
    {
        return false;
    }
    if (x < 10)
    {
        return true;
    }
    std::vector<int> vec;
    int remain = x;
    while (remain != 0)
    {
        vec.push_back(remain % 10);
        remain /= 10;
    }
    size_t begin = 0;
    size_t end = vec.size() - 1;
    while (end > begin)
    {
        if (vec.at(begin) != vec.at(end))
        {
            return false;
        }
        ++begin;
        --end;
    }
    return true;
}

bool IsPalindrome2(int x)
{
    if (x < 0)
    {
        return false;
    }
    if (x < 10)
    {
        return true;
    }

    int remain = x;
    int revx = 0;
    while (remain >= 0)
    {
        revx = revx * 10 + remain % 10;
        remain /= 10;
    }
    return revx == x;
}

int main (int argc, char* argv[])
{
    std::cout << "123321: " << IsPalindrome(123321) << std::endl;
    std::cout << "12321: " << IsPalindrome(12321) << std::endl;
    std::cout << "123421: " << IsPalindrome(123421) << std::endl;
    return 0;
}
