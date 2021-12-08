#include <iostream>
#include <algorithm>

using namespace std;

bool ispossible(int arr[], int n, int k, int mid)
{
    int cows = 1;
    int lastpos = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] - lastpos >= mid)
        {
            count++;
            if (count == k)
            {
                return true;
            }
            lastpos = arr[i];
        }
    }
    return false;
}

int cows(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int s = 0;
    int maxi = -1;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
    }
    int e = maxi;
    int ans = -1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (ispossible(arr, n, k, mid))
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            ans = mid - 1;
        }
        mid = s + (e - s) / 2;
    }

    return ans;
}

int main()
{
}