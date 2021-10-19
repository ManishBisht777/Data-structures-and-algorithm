#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s = "aaaaaaa";
    int i = 0, j = 1, ans = 0;
    int k;

    for (j = 0; j < s.size(); j++)
    {
        k = i;
        while (k < j)
        {
            if (s[k] == s[j])
            {
                i = j;
                break;
            }
            k++;
        }
        ans = max(ans, j - i + 1);
    }
    cout << ans;
}