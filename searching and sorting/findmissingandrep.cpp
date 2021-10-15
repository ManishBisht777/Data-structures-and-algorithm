#include <iostream>

using namespace std;

int *findTwoElement(int *arr, int n)
{
    // code here
    int a[n];
    int *ans = new int[2];
    for (int i = 0; i < n; i++)
    {
        a[arr[i] - 1]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 2)
        {
            ans[0] = i + 1;
        }
        else if (a[i] == 0)
        {
            ans[1] = i + 1;
        }
        else
        {
            continue;
        }
    }
    return ans;
}
