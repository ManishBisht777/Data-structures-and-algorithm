#include <iostream>
#include <algorithm>

using namespace std;

int duplicate(int arr[], int n)
{
    sort(arr, arr + n);

    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i - 1])
        {
            return arr[i];
        }
    }
}

int duplicate2(int arr[], int n)
{
    int max_idx = 0;
    int curr_max = 0;

    for (int i = 0; i < n; i++)
    {
        int id = arr[i] % n;
        arr[id] += n;
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > curr_max)
        {
            curr_max = arr[i];
            max_idx = i;
        }
        arr[i] %= n;
    }
    return max_idx;
}

int main()
{
    int arr[] = {1, 3, 4, 5, 1, 6};
    cout << duplicate2(arr, 6);
}