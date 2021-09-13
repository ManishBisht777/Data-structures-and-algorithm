#include <iostream>

using namespace std;

int maxsubarray(int arr[], int n)
{
    int max = -19999;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            sum += arr[i];
            if (sum > max)
            {
                max = sum;
            }
        }
        sum = 0;
    }

    return max;
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << maxsubarray(arr, n);
    return 0;
}