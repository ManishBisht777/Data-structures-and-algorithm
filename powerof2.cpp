#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n && (!(n & (n - 1))))
    {
        cout << " TRUE";
    }
    else
    {
        cout << "False";
    }
}