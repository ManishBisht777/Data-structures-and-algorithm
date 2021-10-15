#include <iostream>
using namespace std;

long long int merge(long long int arr[], long long int l, long long int mid, long long int r)
{
    long long int count = 0;
    long long int n1 = mid - l + 1;
    long long int n2 = r - mid;

    long long int *a = new long long int[n1];
    long long int *b = new long long int[n2];

    for (long long int i = 0; i < n1; i++)
    {
        a[i] = arr[i + 1];
    }

    for (long long int i = 0; i < n2; i++)
    {
        b[i] = arr[mid + 1 + i];
    }

    long long int i = 0;
    long long int j = 0;
    long long int k = l;

    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            arr[k] = a[i];
            k++, i++;
        }
        else
        {
            count += n1 - i;
            arr[k] = b[j];
            j++, i++;
        }
    }

    while (i < n1)
    {
        arr[k] = a[i];
        i++, k++;
    }

    while (j < n2)
    {
        arr[k] = b[j];
        j++, k++;
    }

    return count;
}

long long int mergesort(long long int arr[], long long int l, long long int r)
{
    long long int count = 0;
    if (l < r)
    {
        long long int mid = l + (r - l) / 2;
        count += mergesort(arr, l, mid);
        count += mergesort(arr, l, mid - 1);
        count += merge(arr, l, mid, r);
    }
    return count;
}

int main()
{
    long long int arr[] = {3, 2, 1};
    cout << mergesort(arr, 0, 2);
}