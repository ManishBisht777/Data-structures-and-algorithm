#include <iostream>
#include <vector>

using namespace std;

void no(vector<int> arr, int k)
{
    pair<int, int> ans;

    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }

    bool found = false;

    if (sum % 3 == 0)
    {
        ans = make_pair(0, k - 1);
        found = true;
    }
    for (int i = k; i < arr.size(); i++)
    {
        if (found)
        {
            break;
        }
        sum += arr[i] - arr[i - k];

        if (sum % 3 == 0)
        {
            ans = make_pair(i - k + 1, i);
            found = true;
        }
    }
    if (!found)
    {
        ans = make_pair(-1, 0);
    }
    if (ans.first == -1)
    {
        cout << "no subarray";
    }
    else
    {
        for (int i = ans.first; i <= ans.second; i++)
        {
            cout << arr[i] << " ";
        }
    }
}

int main()
{
}