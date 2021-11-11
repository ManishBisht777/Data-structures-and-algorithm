#include <iostream>
#include <vector>

using namespace std;

vector<int> factorial(int n)
{
    vector<int> v;
    v.push_back(1);

    for (int i = 2; i < n; i++)
    {
        int carry = 0;
        for (int j = v.size() - 1; j >= 0; j--)
        {
            int value = v[j] * i + carry;
            v[j] = value % 10;
            carry = value / 10;
        }

        while (carry > 0)
        {
            v.insert(v.begin(), carry % 10);
            carry /= 10;
        }
    }

    return v;
}