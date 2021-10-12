#include <iostream>
#include <algorithm>
using namespace std;

int minimize(int arr[], int k, int n)
{
    int ans = arr[n - 1] - arr[0];
    int small = arr[0] + k;
    int large = arr[n - 1] - k;

    for (int i = 0; i < n - 1; i++)
    {
        int mn = min(small, arr[i + 1] - k);
        int mx = max(large, arr[i] + k);

        if (mn < 0)
        {
            continue;
        }
        else
        {
            ans = min(ans, mx - mn);
        }
    }
    return ans;
}

int main()
{
    int k = 2;
    int arr[4] = {1, 5, 8, 10};
    cout << minimize(arr, k, 4);
}