#include <iostream>
using namespace std;

int getpivot(int arr[], int n)
{
    int start = 0, end = n - 1;
    int mid = (start + end) / 2;
    while (start < end)
    {
        if (arr[mid] >= arr[0])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
        mid = (start + end) / 2;
    }
    return start;
}

int main()
{
    int arr[5] = {3, 8, 10, 17, 1};
    cout << getpivot(arr, 5);
}