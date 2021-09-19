#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int s;
    cin >> s;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (arr[i] + arr[j] == s)
            {
                count++;
            }
        }
    }

    cout << count;

    return 0;
}