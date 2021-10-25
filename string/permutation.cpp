#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void permute(string s, int i, vector<string> &ans)
{
    if (i == s.size())
    {
        ans.push_back(s);
        return;
    }
    else
    {
        for (int k = i; k < s.size(); k++)
        {
            swap(s[k], s[i]);
            permute(s, i + 1, ans);
            swap(s[k], s[i]);
        }
    }
}

int main()
{
    string a = "abc";
    vector<string> ans;
    permute(a, 0, ans);
    sort(a.begin(), a.end());
    for (auto i : ans)
    {
        cout << i << " ";
    }
}