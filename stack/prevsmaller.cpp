#include <iostream>
#include <stack>

using namespace std;

void prevsmall(int arr[], int n)
{
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && s.top() >= arr[i])
        {
            s.pop();
        }

        if (s.empty())
        {
            cout << "-1 ";
        }
        else
        {
            cout << s.top() << " ";
        }
        s.push(arr[i]);
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    nextsmall(arr, 5);
}