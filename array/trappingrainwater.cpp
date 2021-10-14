#include <iostream>
using namespace std;

int trappingWater(int arr[], int n)
{
    // code here
    int size = n - 1;
    int prev = arr[0];
    int prev_idx = 0;
    int water = 0;
    int temp = 0;

    for (int i = 1; i <= size; i++)
    {
        if (arr[i] >= prev)
        {
            prev = arr[i];
            prev_idx = i;
            temp = 0;
        }
        else
        {
            water += prev - arr[i];
            temp += prev - arr[i];
        }
    }

    if (prev_idx < size)
    {
        water -= temp;
        prev = arr[size];
        for (int i = size; i >= prev_idx; i--)
        {
            if (arr[i] >= prev)
            {
                prev = arr[i];
            }
            else
            {
                water += prev - arr[i];
            }
        }
    }

    return water;
}

int main()
{
    int arr[] = {3, 0, 0, 2, 0, 4};
    cout << trappingWater(arr, 6);
}