#include <iostream>
#include <stack>
#include <math.h>

using namespace std;

int postfix(string s)
{
    stack<int> st;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            st.push(s[i] - '0');
        }
        else
        {
            int opt2 = st.top();
            st.pop();
            int opt1 = st.top();
            st.pop();

            switch (s[i])
            {
            case '+':
                st.push(opt1 + opt2);
                break;
            case '-':
                st.push(opt1 - opt2);
                break;
            case '*':
                st.push(opt1 * opt2);
                break;
            case '/':
                st.push(opt1 / opt2);
                break;
            case '^':
                st.push(pow(opt1, opt2));
                break;
            default:
                break;
            }
        }
    }

    return st.top();
}

int main()
{
    cout << postfix("46+2/5*7+");
}