#include <iostream>
#include <algorithm>

using namespace std;

void merge(int arr1[], int arr2[], int n, int m)
{
    int i = 0, k = n - 1, j = 0;
    while (i <= k && j < m)
    {
        if (arr1[i] <= arr2[j])
            i++;
        else
            swap(arr1[k], arr2[j]), k--, j++;
    }
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}
