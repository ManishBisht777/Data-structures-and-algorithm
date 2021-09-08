#include <bits/stdc++.h>
using namespace std;

int max(int arr[], int n)
{
    int max = -1999;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}
int min(int arr[], int n)
{
    int min = 999999;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    return min;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << max(arr, n);
    cout << " " << min(arr, n);

    return 0;
}
