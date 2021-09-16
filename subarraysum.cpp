#include <iostream>

using namespace std;

int main()
{

    // brute force approach

    // int n, s;
    // cin >> n >> s;
    // int sum = 0;
    // int *arr = new int[n];

    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i; j < n; j++)
    //     {
    //         sum += arr[j];
    //         if (sum == s)
    //         {
    //             cout << i + 1 << " " << j + 1;
    //             return 0;
    //         }
    //     }
    //     sum = 0;
    // }

    // optimised appraoch

    int n, s;
    cin >> n >> s;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int st = 0, ed = 0, sum = 0, i = 0, j = 0;

    while (j < n && sum + arr[j] <= s)
    {
        sum += arr[j];
        j++;
    }

    if (sum == s)
    {
        cout << i + 1 << " " << j;
    }

    while (j < n)
    {
        sum += arr[j];

        while (sum > s)
        {
            sum -= arr[i];
            i++;
        }

        if (sum == s)
        {
            st = i + 1;
            ed = j + 1;
            break;
        }
        j++;
    }

    cout << st << " " << ed;
    return 0;
}