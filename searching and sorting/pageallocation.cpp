#include <iostream>
#include <algorithm>
using namespace std;

bool isfeasible(int arr[], int n, int m, int min)
{
    int sum = 0;
    int students = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > min)
        {
            return false;
        }
        if (sum + arr[i] > min)
        {
            students++;
            sum = arr[i];
            if (students > m)
            {
                return false;
            }
            else
            {
                sum += arr[i];
            }
        }
        return true;
    }
}

int pageallocation(int arr[], int n, int m)
{
    int sum = 0;

    if (n < m)
    {
        return -1;
    }

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    int start = 0;
    int end = sum;
    int ans = 999999;
    while (start < end)
    {
        int mid = (start + end) / 2;

        if (isfeasible(arr, n, m, mid))
        {
            ans = min(ans, mid);
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int arr[] = {1, 2, 3, 4};

    int n = 4;
    int m = 2;

    cout << pageallocation(arr, n, m);
}