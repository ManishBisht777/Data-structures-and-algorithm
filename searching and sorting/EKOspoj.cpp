#include <iostream>
#include <algorithm>

using namespace std;

bool solve(int arr[], int n, int m, int mid)
{
    int wood = 0;
    for (int i = 0; i < n; i++)
    {
        if (mid < arr[i])
        {
            wood += arr[i] - mid;
        }
    }
    if (wood >= m)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int arr[4] = {20, 15, 10, 17};
    int meter = 7;
    int s = 0, e;
    int maxi = 0;
    for (int i = 0; i < 4; i++)
    {
        maxi = max(maxi, arr[i]);
    }
    int ans;
    e = maxi;

    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (solve(arr, 4, meter, mid))
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }

    cout << ans;
}