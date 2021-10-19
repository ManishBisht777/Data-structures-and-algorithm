#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a[] = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;

    int count = 0, i = 0;
    int ans = 0;

    for (int j = 0; j < 11; j++)
    {
        if (a[j] == 0)
        {
            count++;
        }
        while (count > k)
        {
            if (a[i] == 0)
            {
                count--;
            }
            i++;
        }
        ans = max(ans, j - i + 1);
    }

    cout << ans;
}