#include <vector>
#include <algorithm>
#include <iostream>
#include <limits.h>
using namespace std;

int mindiff(vector<int> a, int n, int m)
{
    sort(a.begin(), a.end());

    int st = 0, end = m - 1, diff = INT_MAX;

    while (end < n)
    {
        diff = min(diff, a[end] - a[st]);
        st++;
        end++;
    }

    return diff;
}