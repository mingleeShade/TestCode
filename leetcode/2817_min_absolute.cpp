#include <cstdlib>
#include <iostream>
#include <vector>
#include <set>
#include <limits.h>

using namespace std;


int minAbsoluteDiffenence(vector<int> nums, int x)
{
    std::vector<int> mins;
    size_t s = nums.size();
    int min = -1;
    for (int i = 0; i < s; ++i)
    {
        for (int j = 0; j < s; ++j)
        {
            if (abs(j - i) < x)
            {
                continue;
            }
            int abs_result = abs(nums.at(j) - nums.at(i));
            if (min == -1 || abs_result < min)
            {
                min = abs_result;
            }
        }
    }
    cout << "array[";
    for (auto num : nums)
    {
        cout << num << ",";
    }
    cout << "], x:" << x << ", min:" << min << endl;;
    return min;
}

int minAbsoluteDiffenence2(vector<int> nums, int x)
{
    int ans = INT_MAX;
    int n = nums.size();
    set<int> s = {INT_MIN / 2, INT_MAX};
    for (int i = x; i < n; ++i)
    {
        s.insert(nums.at(i - x));
        int y = nums.at(i);
        auto it = s.lower_bound(y);
        ans = min(ans, min(*it - y, y - *prev(it)));
    }
    cout << "array[";
    for (auto num : nums)
    {
        cout << num << ",";
    }
    cout << "], x:" << x << ", min:" << ans << endl;
    return ans;
}

int main (int argc, char* argv[])
{
    minAbsoluteDiffenence({4, 3, 2, 4}, 2);
    minAbsoluteDiffenence({5, 3, 2, 10, 15}, 1);
    minAbsoluteDiffenence({1, 2, 3, 4}, 3);
    minAbsoluteDiffenence2({4, 3, 2, 4}, 2);
    minAbsoluteDiffenence2({5, 3, 2, 10, 15}, 1);
    minAbsoluteDiffenence2({1, 2, 3, 4}, 3);
    return 0;
}
