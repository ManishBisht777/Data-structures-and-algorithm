#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int maxsubarray(int arr[], int n)
{
    int Max = INT_MIN;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            Max = max(sum, Max);
        }

        sum = 0;
    }

    return Max;
}
int main()
{
    int n;
    cout << "\n\t ENTER SIZE OF ARRAY : ";
    cin >> n;
    int *arr = new int[n];

    cout << "\n\t ENTER ELEMENT  OF ARRAY : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << " \n\t MAX SUM OF ASUB ARRAY IS : ";
    cout << maxsubarray(arr, n);
    return 0;
}