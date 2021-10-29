#include <bits/stdc++.h>
#include <stack>

using namespace std;

int *prevsmall(int arr[], int n)
{
    stack<int> s;
    int *prevs = new int[n];
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && s.top() >= arr[i])
        {
            s.pop();
        }

        if (s.empty())
        {
            prevs[i] = -1;
        }
        else
        {
            prevs[i] = s.top();
        }
        s.push(arr[i]);
    }

    return prevs;
}

int *nextsmall(int arr[], int n)
{
    stack<int> s;
    int *ans = new int[n];
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() >= arr[i])
        {
            s.pop();
        }

        if (s.empty())
        {
            ans[i] = n + 1;
        }
        else
        {
            ans[i] = s.top();
        }
        s.push(arr[i]);
    }
    return ans;
}

int maxarea(int arr[], int n)
{
    int maxarr = 0;

    int *ps = prevsmall(arr, n);
    int *ns = nextsmall(arr, n);

    for (int i = 0; i < n; i++)
    {
        int curr = (ns[i] - ps[i] - 1) * arr[i];

        maxarr = max(maxarr, curr);
    }

    return maxarr;
}

int main()
{
    int arr[] = {6, 2, 5, 4, 5, 1, 6};

    cout << maxarea(arr, 7);
}