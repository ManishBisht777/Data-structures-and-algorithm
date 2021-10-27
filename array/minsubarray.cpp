#include <iostream>

using namespace std;

int smallsize(int arr[], int n, int x)
{
    int sum = 0, minlen = n + 1, start = 0, end = 0;

    while (end < n)
    {
        while (sum <= x && end < n)
            sum += arr[end++];

        while (sum > x && start < n)
        {
            if (end - start < minlen)
                minlen = end - start;

            sum -= arr[start++];
        }
    }

    return minlen;
}

int main()
{
}