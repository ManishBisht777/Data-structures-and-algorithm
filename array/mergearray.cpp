#include <iostream>
#include <algorithm>

using namespace std;
void merge(int arr1[], int arr2[], int n, int m)
{
    // code here
    int i = n - 1;
    int j = 0;

    while (i >= 0 && j < m)
    {
        if (arr1[i] > arr2[j])
        {
            swap(arr1[i], arr2[j]);
            i--;
            j++;
        }
        else
        {
            break;
        }
    }
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}

int main()
{
    int a[] = {1, 3, 5, 7};
    int b[] = {0, 2, 6, 8, 9};

    merge(a, b, 4, 5);
    for (int i = 0; i < 4; i++)
    {
        cout << a[i] << " ";
    }
    for (int i = 0; i < 5; i++)
    {
        cout << b[i] << " ";
    }
}