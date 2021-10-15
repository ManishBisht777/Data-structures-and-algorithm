#include <iostream>

using namespace std;

int middle(int A, int B, int C)
{
    if (A > B)
    {
        if (B < C)
        {
            if (A > C)
                return C;
            return A;
        }
    }
    else if (B > C)
    {
        if (A > C)
            return A;
        return C;
    }
    return B;
}
int main()
{
    int a = 1, b = 2, c = 3;

    cout << middle(a, b, c);
}