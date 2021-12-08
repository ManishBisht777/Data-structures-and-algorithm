#include <iostream>
using namespace std;

int binarysearch(int n)
{
    int start = 0, end = n - 2;
    int mid = start + (end - start) / 2;
    int ans = 0;
    while (start <= end)
    {
        if (mid * mid == n)
        {
            return mid;
        }
        else if (mid * mid < n)
        {
            start = mid + 1;
            ans = mid;
        }
        else
        {
            end = mid - 1;
        }
        int mid = start + (end - start) / 2;
    }

    return ans;
}
