#include <iostream>
#include <vector>

using namespace std;

vector<int> find(int arr[], int n, int x)
{
    int i = 0;
    int j = n - 1;
    vector<int> v;
    while (i <= j)
    {
        if (arr[i] != x)
        {
            i++;
        }
        if (arr[j] != x)
        {
            j--;
        }
        if (arr[i] == x && arr[j] == x)
        {
            v.push_back(i);
            v.push_back(j);
            break;
        }
    }
    if (i > j)
    {
        v.push_back(-1);
        v.push_back(-1);
    }
    return v;
}

int main()
{
    int a[] = {1, 2, 4, 4, 4};
    vector<int> arr = find(a, 5, 4);
    cout << arr[0] << " " << arr[1];
    return 0;
}