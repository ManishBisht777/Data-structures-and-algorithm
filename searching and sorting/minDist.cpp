#include <algorithm>
#include <iostream>

bool isfeasible(int mid, int arr[], int n, int k)
{
    int pos = arr[0];
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - pos >= mid)
        {
            pos = arr[i];
            count++;
            if (count == k)
            {
                return true;
            }
        }
    }
    return false;
}

int largestmindist(int arr[], int n, int k)
{
    sort(arr, arr + n);

    int result = -1;
    int left = arr[0];
    int right = arr[n - 1];

    while (left > right)
    {
        int mid = (left + right) / 2;

        if (isfeasible(mid, arr, n, k))
        {
            result = max(result, mid);
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return result;
}

using namespace std;

int main()
{
    int arr[] = {1, 2, 8, 4, 9};
    int k = 3;
    int n = 5;

    cout << largestmindist(arr, n, k);
}