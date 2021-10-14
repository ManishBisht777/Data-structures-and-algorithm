#include <iostream>

using namespace std;

int minlen(int arr[], int n, int k)
{
    int ml = n + 1;
    int currsum = 0;
    int i = 0, j = 0;

    while (j < n)
    {
        while (currsum <= k && j < n)
        {
            currsum += arr[j];
            j++;
        }

        while (currsum > k && i < n)
        {
            if ((j - i) < ml)
            {
                ml = j - i;
            }

            currsum -= arr[i];
            i++;
        }
    }

    return ml;
}

int main()
{
    int arr[] = {2, 5, 45, 6, 0, 19};

    cout << minlen(arr, 6, 51);
}