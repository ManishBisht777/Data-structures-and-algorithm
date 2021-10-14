#include <iostream>
#include <algorithm>

using namespace std;

int maxproduct(int arr[], int n)
{
    int maxval = 1;
    int minval = 1;
    int product = 0;
    if (n == 1)
    {
        return arr[0];
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            swap(minval, maxval);
        }

        maxval = max(arr[i], arr[i] * maxval);
        minval = min(arr[i], arr[i] * minval);
        product = max(product, maxval);
    }
    return product;
}

int main()
{
    int arr[] = {2, 3, 4, 5, -1, 0};
    cout << maxproduct(arr, 6);
}