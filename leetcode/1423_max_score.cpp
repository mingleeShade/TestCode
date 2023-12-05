#include <iostream>
#include <vector>

using namespace std;

int maxScore(vector<int> cardPoints, int k)
{
    int ans = 0;
    for (int i = 0; i < k; ++i)
    {
        ans += cardPoints.at(i);
    }
    int size = cardPoints.size();
    if (size == k)
    {
        return ans;
    }
    int max = ans;
    cout << "first: " << ans << endl;
    for (int i = 0; i < k; ++i)
    {
        ans -= cardPoints.at(k - 1 - i);
        ans += cardPoints.at(size - 1 - i);
        if (ans > max)
        {
            max = ans;
        }
    }
    return max;
}

int main (int argc, char* argv[])
{
    cout << endl << "max" << maxScore({1, 2, 3, 4, 5, 6, 1}, 3) << endl;
    return 0;
}
