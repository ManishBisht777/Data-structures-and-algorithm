#include <iostream>
#include <algorithm>

using namespace std;

int findfeasible(int arr[], int n, int limit)
{
    int sum = 0;
    int painter = 1;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum > limit)
        {
            sum = arr[i];
            painter++;
        }
    }
    return painter;
}

int painter(int arr[], int n, int m)
{
    int totallen = 0;
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        k = max(k, arr[i]);
        totallen += arr[i];
    }

    int start = k;
    int end = totallen;

    while (start < end)
    {
        int mid = (start + end) / 2;
        int painter = findfeasible(arr, n, mid);
        if (painter <= m)
        {
            end = mid;
        }
        else
        {
            start = mid + 1;
        }
    }

    return start;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5;
    int m = 2;
    cout << painter(arr, n, m);
}