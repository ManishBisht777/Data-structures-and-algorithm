#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int max_sum = 0;

    for (int i = 0; i < k; i++)
    {
        max_sum += arr[i];
    }

    int window_sum = max_sum;

    for (int i = k; i < n; i++)
    {
        window_sum += arr[i] - arr[i - k];
        if (window_sum > max_sum)
        {
            max_sum = window_sum;
        }
    }

    cout << max_sum;
}