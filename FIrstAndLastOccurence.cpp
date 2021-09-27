#include <iostream>
using namespace std;

int first(int arr[], int size, int n, int i)
{
    if (i == size)
    {
        return -1;
    }
    if (arr[i] == n)
    {
        return i;
    }

    return first(arr, size, n, i + 1);
}

int last(int arr[], int size, int n, int i)
{
    if (i == size)
    {
        return -1;
    }
    int restarray = last(arr, size, n, i + 1);

    if (restarray != -1)
    {
        return restarray;
    }
    if (arr[i] == n)
    {
        return i;
    }
    return -1;
}
int main()
{
    int arr[7] = {4, 1, 2, 2, 5, 2, 7};
    cout << first(arr, 7, 2, 0) << " ";
    cout << last(arr, 7, 2, 0);
}