#include <iostream>
#include <vector>

using namespace std;

vector<int> quick_sort(std::vector<int> src)
{
    if (src.size() <= 1)
    {
        return src;
    }
    // 取中间数
    int pivot = src.at(src.size() / 2);
    pivot = (src.at(0) + pivot) / 2;
    vector<int> left;
    vector<int> right;
    for (auto i : src)
    {
        if (i <= pivot)
        {
            left.emplace_back(i);
        }
        else
        {
            right.emplace_back(i);
        }
    }
    left = quick_sort(left);
    right = quick_sort(right);
    left.insert(left.end(), right.begin(), right.end());
    return left;
}

void show(const vector<int>& vec)
{
    for (auto v : vec)
    {
        cout << v << ",";
    }
    cout << endl;
}

int main (int argc, char* argv[])
{
    auto result = quick_sort({2, 9, 6, 7, 4, 3, 1, 7});
    show(result);
    return 0;
}
