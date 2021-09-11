#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int max = -199999;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            if (arr[j] > max)
            {
                max = arr[j];
            }
        }
        cout << max << " ";
    }
}