// #include <bits/stdc++.h>
// using namespace std;

// int max(int arr[], int n)
// {
//     int max = -1999;
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] > max)
//         {
//             max = arr[i];
//         }
//     }

//     return max;
// }
// int min(int arr[], int n)
// {
//     int min = 999999;
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] < min)
//         {
//             min = arr[i];
//         }
//     }
//     return min;
// }

// int main()
// {
//     int n;
//     cin >> n;
//     int arr[n];

//     for (int i = 0; i < n; i++)
//     {
//         cin >> arr[i];
//     }

//     cout << max(arr, n);
//     cout << " " << min(arr, n);

//     return 0;
// }

#include <iostream>

using namespace std;

struct Pair
{
    int min;
    int max;
};

struct Pair getMinMax(int arr[], int n)
{
    struct Pair minmax;
    int i;

    if (n % 2 == 0)
    {
        if (arr[0] > arr[1])
        {
            minmax.min = arr[1];
            minmax.max = arr[0];
        }
        else
        {
            minmax.min = arr[0];
            minmax.max = arr[1];
        }

        i = 2;
    }

    else
    {
        minmax.min = arr[0];
        minmax.max = arr[0];

        i = 1;
    }

    while (i < n - 1)
    {
        if (arr[i] > arr[i + 1])
        {
            if (arr[i] > minmax.max)
            {
                minmax.max = arr[i];
            }
            if (arr[i + 1] < minmax.min)
            {
                minmax.min = arr[i + 1];
            }
        }
        else
        {
            if (arr[i] < minmax.min)
            {
                minmax.min = arr[i];
            }
            if (arr[i + 1] > minmax.max)
            {
                minmax.max = arr[i + 1];
            }
        }

        i += 2;
    }

    return minmax;
}
int main()
{
    int arr[] = {1000, 11, 445,
                 1, 330, 3000};
    int arr_size = 6;

    Pair minmax = getMinMax(arr, arr_size);

    cout << "nMinimum element is "
         << minmax.min << endl;
    cout << "nMaximum element is "
         << minmax.max;

    return 0;
}
