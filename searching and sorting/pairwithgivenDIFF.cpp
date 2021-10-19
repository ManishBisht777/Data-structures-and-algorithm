#include <algorithm>
#include <iostream>

using namespace std;

bool findPair(int arr[], int size, int n)
{
    //code
    sort(arr, arr + size);
    int i = 0, j = 1;
    while (i < j && j < size && i < size)
    {
        int d = arr[j] - arr[i];
        if (d == n)
            return 1;
        else if (d < n)
            j++;
        else
        {
            if (j == i + 1)
                j++;
            else
                i++;
        }
    }

    return 0;
}

int main()
{
    int arr[] = {5, 20, 3, 2, 5, 80};

    cout << findPair(arr, 6, 78);
}