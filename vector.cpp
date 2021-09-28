#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    cout << "\n";
    vector<int>::iterator it;

    for (it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }

    cout << "\n";

    for (auto element : v)
    {
        cout << element << " ";
    }
    cout << "\n";

    v.pop_back();
    for (auto element : v)
    {
        cout << element << " ";
    }
    cout << "\n";

    vector<int> v2(3, 50);
    swap(v, v2);
    for (auto element : v)
    {
        cout << element << " ";
    }
    cout << "\n";

    for (auto element : v2)
    {
        cout << element << " ";
    }

    sort(v.begin(), v.end());
}