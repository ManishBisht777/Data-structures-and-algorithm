#include <iostream>
#include <algorithm>

using namespace std;

int triplet(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int count = 0;
    int i = 0;
    for (int i = 0; i < n; i++)
    {
        int j = i + 1, k = n - 1;
        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];

            if (sum < k)
                count++;
            else

                k--;
        }
    }

    return count;
}

int main()
{
}
