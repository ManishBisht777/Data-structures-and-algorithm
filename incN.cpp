#include <iostream>

using namespace std;

void incn(int n)
{
    if (n == 0)
    {
        return;
    }
    incn(n - 1);
    cout << n << " ";
}
int main()
{
    int n;
    cin >> n;
    incn(n);
}