#include <iostream>

using namespace std;

void rotate(int arr[], int n)
{

    if (n == 2)
    {
        int temp = arr[0];
        arr[0] = arr[1];
        arr[1] = temp;
        return;
    }
    for (int j = 0; j < n; j++)
    {
        int temp = arr[j];
        arr[j] = arr[n - 1];
        arr[n - 1] = temp;
    }
}

int main()
{

    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    rotate(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}