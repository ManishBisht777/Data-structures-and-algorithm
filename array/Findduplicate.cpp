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

int main()
{
    int arr[] = {1, 3, 4, 5, 1, 6};
    cout << duplicate(arr, 6);
}