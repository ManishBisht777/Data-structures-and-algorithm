#include <iostream>
#include <stack>

using namespace std;

class que
{
    stack<int> s1;

public:
    void push(int x)
    {
        s1.push(x);
    }

    int pop()
    {
        if (s1.empty())
        {
            cout << "\n\t QUEUE EMPTY";
            return -1;
        }

        int x = s1.top();
        s1.pop();
        if (s1.empty())
        {
            return x;
        }

        int item = pop();
        s1.push(x);
        return item;
    }

    bool isempty()
    {
        if (s1.empty())
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