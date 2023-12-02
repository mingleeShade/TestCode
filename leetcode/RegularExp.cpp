#include <iostream>

using namespace std;

struct Cache
{
    int index_p = 0;
    int index_s = 0;
};

bool IsMatch(string s, string p)
{
    if (p.empty())
    {
        return false;
    }
    size_t index_p = 0;
    size_t index_s = 0;
    size_t index_p_bak = -1;
    char pre_c = 0;
    for (; index_s < s.length() && index_p < p.length();)
    {
        char c_s = s.at(index_s);
        char cur_match_c = p.at(index_p);
        switch (cur_match_c)
        {
            case '.':
            {
                // .匹配任意字符
                ++index_p;
                ++index_s;
                pre_c = '.';
            }
            break;
            case '*':
            {
                if (pre_c == '.')
                {
                    // .* 匹配任意字符串，需要特殊处理
                    if (index_p < p.length() - 1)
                    {
                        if (p.at(index_p + 1) == c_s)
                        {
                            // 如 .*aa 匹配 baa, 需要将匹配.* 匹配范围缩减
                            index_p_bak = index_p;
                            index_p += 2;
                        }
                        ++index_s;
                    }
                    else
                    {
                        return true;
                    }
                }
                else
                {
                    if (pre_c != c_s)
                    {
                        // 出现不匹配，尝试回溯
                        if (index_p_bak > 0)
                        {
                            index_p = index_p_bak;
                            pre_c = '.';
                            // 用前一个 .* 覆盖当前
                            ++index_s;
                            index_p_bak = -1;
                            continue;
                        }
                        else
                        {
                            // 没有可以回溯的，直接匹配失败
                            return false;
                        }
                    }
                    else
                    {
                        // 匹配，继续
                        ++index_s;
                    }
                }
            }
            break;
            default:
            {
                if (cur_match_c != c_s)
                {
                    // 尝试回溯
                    if (index_p_bak > 0)
                    {
                        index_p = index_p_bak;
                        pre_c = '.';
                        // 用前一个 .* 覆盖当前
                        ++index_s;
                        index_p_bak = -1;
                        continue;
                    }
                    else
                    {
                        // 没有可以回溯的，直接匹配失败
                        return false;
                    }
                }
                else
                {
                    ++index_s;
                    ++index_p;
                    pre_c = cur_match_c;
                }
            }
        }
    }
    return index_s > s.length() - 1 && index_p >= p.length() - 1;
}

void Test(string s, string p)
{
    std::cout << "s:" << s << ", p:" << p << ", match:" << IsMatch(s, p) << std::endl;
}

int main (int argc, char* argv[])
{
    std::cout << endl;
    Test("aabbaa", ".*bbaa");
    Test("ab", ".*");
    Test("aa", "a*");
    Test("aabbaabaa", ".*aa.*");
    Test("baacaa", ".*a*");
    Test("aa", "a");
    Test("aab", "c*a*b");
    return 0;
}
