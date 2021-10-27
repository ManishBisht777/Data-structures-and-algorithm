#include <iostream>

using namespace std;

int search(int arr[], int key, int left, int right)
{
    if (left > right)
    {
        return -1;
    }

    int mid = (left + right) / 2;

    if (arr[mid] == key)
        return mid;

    if (arr[left] <= arr[mid])
    {
        if (key >= arr[left] && key <= arr[mid])
            return search(arr, key, left, mid - 1);

        return search(arr, key, mid + 1, right);
    }

    if (key >= arr[mid] && key <= arr[right])
        return search(arr, key, mid + 1, right);

    return search(arr, key, left, mid + 1);
}

int main()
{
    int arr[] = {3, 4, 5, 1, 2};
    cout << search(arr, 1, 0, 4);
}