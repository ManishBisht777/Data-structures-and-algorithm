#include <iostream>

using namespace std;

void decn(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << n << " ";
    decn(n - 1);
}
int main()
{
    int n;
    cin >> n;
    decn(n);
}