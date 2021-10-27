#include <iostream>

using namespace std;

int maxsum(int arr[], int n, int k, int x)
{
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }

    if (sum > x)
        ans = sum;

    for (int i = k; i < n; i++)
    {
        sum -= arr[i - k];
        sum += arr[i];

        if (sum < x)
        {
            ans = max(ans, sum);
        }
    }

    return ans;
}

int main()
{
}