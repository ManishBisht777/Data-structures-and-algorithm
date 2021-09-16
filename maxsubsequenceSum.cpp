#include <iostream>
#include <algorithm>

using namespace std;

int maxSubsequenceSum(int arr[], int n)
{
    int excl = 0;
    int incl = arr[0];
    for (int i = 1; i < n; i++)
    {
        int temp = incl;
        incl = max(excl + arr[i], incl);
        excl = temp;
    }
    return incl;
}

int main()
{
    int n;
    cout << "\n\t ENTER SIZE OF ARRAY : ";
    cin >> n;
    int *arr = new int[n];

    cout << "\n\t ENTER ELEMENTS IN ARRAY : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "\n\t MAX SUM OF SUBSEQUENCE IS : ";

    cout << maxSubsequenceSum(arr, n);
}