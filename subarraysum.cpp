#include <iostream>

using namespace std;

int main()
{
    int n, s;
    cin >> n >> s;
    int sum = 0;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == s)
            {
                cout << i + 1 << " " << j + 1;
                return 0;
            }
        }
        sum = 0;
    }

    return 0;
}