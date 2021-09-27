#include <iostream>

using namespace std;

int sumtilln(int n)
{
    if (n == 0)
    {
        return 0;
    }
    int prevsum = sumtilln(n - 1);
    return n + prevsum;
}

int main()
{
    int n;
    cin >> n;
    cout << sumtilln(n);
}