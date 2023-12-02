#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& num1, int m, vector<int>& num2, int n)
{
    int index_m = m - 1;
    int index_n = n - 1;
    for (int i = m + n - 1; n >= 0; --i)
    {
        if (index_m == i)
        {
            return;
        }
        if (index_m < 0)
        {
            num1[i] = num2.at(index_n);
            --index_n;
            continue;
        }
        if (index_n < 0)
        {
            num1[i] = num1.at(index_m);
            --index_m;
        }
        if (num1.at(index_m) < num2.at(index_n))
        {
            num1[i] = num2.at(index_n);
            --index_n;
        }
        else
        {
            num1[i] =  num1.at(index_m);
            --index_m;
        }
    }
}

void show(const vector<int>& vec)
{
    for (auto i : vec)
    {
        cout << i << ",";
    }
    cout << endl;
}

int main (int argc, char* argv[])
{
    vector<int> num1 = {1, 3, 4, 7, 0, 0, 0};
    show(num1);
    vector<int> num2 = {1, 2, 5};
    show(num2);
    merge(num1, 4, num2, 3);
    show(num1);
    return 0;
}
