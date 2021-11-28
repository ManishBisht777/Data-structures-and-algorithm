#include <iostream>
#include <algorithm>

using namespace std;

int together(int arr[], int n, int k)
{
    int count = 0;
    int ans = 0;
    int swaps = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= k)
        {
            count++;
        }
    }

    int i = 0;
    int j = 0;

    while (j < count)
    {
        if (arr[j] > k)
        {
            swaps++;
        }
        j++;
    }

    ans = swaps;

    while (j < n)
    {
        if (arr[i] > k)
        {
            swaps--;
        }
        if (arr[j] > k)
        {
            swaps++;
        }
        ans = min(ans, swaps);
        i++, j++;
    }

    return swaps;
}

int main()
{
}