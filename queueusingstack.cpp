#include <iostream>
#include <stack>

using namespace std;

class que
{
    stack<int> s1;
    stack<int> s2;

public:
    void push(int x)
    {
        s1.push(x);
    }

    int pop()
    {
        if (s1.empty() && s2.empty())
        {
            cout << "\n\t QUEUE EMPTY";
            return -1;
        }

        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s2.top();
            }
        }

        int topval = s2.top();
        s2.pop();
        return topval;
    }

    bool isempty()
    {
        if (s1.empty() && s2.empty())
        {
            return true;
        }

        return false;
    }
};

int main()
{
    que q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    cout << q.pop() << "\n";
    cout << q.pop() << "\n";
    cout << q.pop() << "\n";
    cout << q.pop() << "\n";
    cout << q.pop() << "\n";
    cout << q.pop() << "\n";
    cout << q.pop() << "\n";
}