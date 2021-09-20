#include <iostream>

using namespace std;

bool getbit(int n, int pos)
{
    return ((n & (1 << pos)) != 0);
}

void unique(int arr[], int n)
{
    int xorsum = 0;

    for (int i = 0; i < n; i++)
    {
        xorsum ^= arr[i];
    }

    // now xorsum sum contain xor of both unique elements

    int setbit = 0, pos = 0;
    int temp = xorsum;
    int newxor = 0;

    while (setbit != 1)
    {
        setbit = xorsum & 1;
        pos++;
        xorsum = xorsum >> 1;
    }

    for (int i = 0; i < n; i++)
    {
        if (getbit(arr[i], pos - 1))
        {
            newxor ^= arr[i];
        }
    }

    cout << newxor << " ";
    temp = temp ^ newxor;
    cout << temp;
}

int main()
{
    int arr[8] = {1, 2, 3, 1, 2, 3, 4, 5};

    unique(arr, 8);

    return 0;
}