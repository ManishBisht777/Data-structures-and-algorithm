#include <iostream>

using namespace std;

int main()
{
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    int *arr1 = new int[n1];
    int *arr2 = new int[n2];
    int *arr3 = new int[n3];

    for (int i = 0; i < n1; i++)
    {
        cin >> arr2[i];
    }

    for (int i = 0; i < n2; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < n3; i++)
    {
        cin >> arr3[i];
    }

    common()

    return 0;
}