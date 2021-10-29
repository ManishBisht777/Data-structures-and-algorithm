#include <iostream>
#include <stack>

using namespace std;

void nextsmall(int arr[], int n)
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

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}
int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    nextsmall(arr, 5);
}