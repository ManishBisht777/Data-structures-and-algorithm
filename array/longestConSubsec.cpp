#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <limits>
using namespace std;

int findlongest(int arr[], int n)
{
    unordered_set<int> s;
    int ans = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        s.insert(arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (s.find(arr[i] - 1) != s.end())
        {
            int j = arr[i];

            while (s.find(arr[j]) != s.end())
                j++;
            ans = max(ans, j - arr[i]);
        }
    }

    return ans;
}

int main()
{
}