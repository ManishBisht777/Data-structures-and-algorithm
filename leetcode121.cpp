#include <iostream>
#include <limits.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int minprice = INT_MAX;

    int maxprofit = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < minprice)
        {
            minprice = arr[i];
        }

        else if (arr[i] - minprice > maxprofit)
        {
            maxprofit = arr[i] - minprice;
        }
    }

    cout << maxprofit;
}