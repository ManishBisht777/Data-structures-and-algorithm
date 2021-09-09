#include <iostream>

using namespace std;

void sort012(int arr[])
{
    int c0 = 0, c1 = 0, c2 = 0;

    for (int i = 0; i < 10; i++)
    {
        if (arr[i] == 0)
        {
            c0++;
        }
        else if (arr[i] == 1)
        {
            c1++;
        }
        else
        {
            c2++;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        if (c0 != 0)
        {
            arr[i] = 0;
            c0--;
        }
        else if (c1 != 0)
        {
            arr[i] = 1;
            c1--;
        }
        else
        {
            arr[i] = 2;
            c2--;
        }
    }
}

int main()
{
    int arr[10] = {1, 1, 2, 2, 2, 1, 1, 1, 1, 1};

    sort012(arr);

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}