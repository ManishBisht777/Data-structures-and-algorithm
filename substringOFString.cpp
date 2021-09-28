#include <iostream>

using namespace std;

void substring(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << "\n";
        return;
    }

    char ch = s[0];

    string ros = s.substr(1);
    substring(ros, ans);
    substring(ros, ans + ch);
}

int main()
{
    string s = "ABC";
    substring(s, "");
}