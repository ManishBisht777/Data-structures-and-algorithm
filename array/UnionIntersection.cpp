#include <iostream>
#include <array>
using namespace std;

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int i = l - 1;

    for (int j = l; j < r; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, r);
    return i + 1;
}

void quicksort(int arr[], int l, int r)
{
    if (l < r)
    {
        int pi = partition(arr, l, r);
        quicksort(arr, l, pi - 1);
        quicksort(arr, pi + 1, r);
    }
}

void intersection(int arr1[], int arr2[], int m, int n)
{
    quicksort(arr1, 0, m - 1);
    quicksort(arr2, 0, n - 1);

    int i = 0, j = 0, prev1 = 0, prev2 = 0;

    while (i < m && j < n)
    {
        while (arr1[i] == prev1 && i < m)
        {
            i++;
        }
        while (arr2[i] == prev2 && j < n)
        {
            j++;
        }
        if (arr1[i] == arr2[j])
        {
            cout << arr1[i] << " ";
            prev1 = arr1[i];
            prev2 = arr2[j];
            i++, j++;
        }
        else if (arr1[i] < arr2[j])
        {
            prev1 = arr1[i];
            i++;
        }
        else
        {
            prev2 = arr2[j];
            j++;
        }
    }
}

void Union(int arr1[], int arr2[], int m, int n)
{
    quicksort(arr1, 0, m - 1);
    quicksort(arr2, 0, n - 1);

    int i = 0, j = 0, prev1 = 0, prev2 = 0;

    while (i < m && j < n)
    {
        while (arr1[i] == prev1 && i < m)
        {
            i++;
        }
        while (arr2[i] == prev2 && j < n)
        {
            j++;
        }
        if (arr1[i] == arr2[j])
        {
            cout << arr1[i] << " ";
            prev1 = arr1[i];
            prev2 = arr2[j];
            i++, j++;
        }
        else if (arr1[i] < arr2[j])
        {
            cout << arr1[i] << " ";
            prev1 = arr1[i];
            i++;
        }
        else
        {
            cout << arr2[j] << " ";
            prev2 = arr2[j];
            j++;
        }
    }
    while (i < m)
    {
        cout << arr1[i] << " ";
        i++;
    }
    while (j < n)
    {
        cout << arr2[j] << " ";
        j++;
    }
}
int main()
{
    int n1, n2;
    cin >> n1 >> n2;

    int *a = new int[n1];
    for (int i = 0; i < n1; i++)
    {
        cin >> a[i];
    }

    int *b = new int[n2];
    for (int i = 0; i < n2; i++)
    {
        cin >> b[i];
    }

    intersection(a, b, n1, n2);
    cout << "\n";
    Union(a, b, n1, n2);
}