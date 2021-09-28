#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// function for sorting on the basis ofsecond element of pair
bool mycompare(pair<int, int> v, pair<int, int> v2)
{
    return v.second < v2.second;
}

int main()
{
    int arr[] = {10, 16, 7, 14, 5, 3, 12, 9};

    vector<pair<int, int>> v;

    for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
    {
        v.push_back(make_pair(arr[i], i));
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        arr[v[i].second] = i;
    }

    for (int i = 0; i < v.size(); i++)
    {
        cout << arr[i] << " ";
    }
}