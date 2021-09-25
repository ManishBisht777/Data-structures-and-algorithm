#include <iostream>
#define n 100

using namespace std;

class stack
{
    int *arr;
    int top = -1;

public:
    stack()
    {
        arr = new int[n];
        top = -1;
    }

    void push(int x)
    {
        if (top == n - 1)
        {
            cout << "\n\t stack overflow ";
            return;
        }

        top++;
        arr[top] = x;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "\n\t stack empty ";
            return;
        }

        top--;
    }

    int Top()
    {
        if (top == -1)
        {
            cout << "\n\t stack empty";
            return -1;
        }
        return arr[top];
    }

    bool empty()
    {
        return top == -1;
    }

    void display()
    {
        while (!empty())
        {
            cout << Top() << " ";
            pop();
        }
        cout << "\n";
    }
};

int main()
{
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    // st.display();
    cout << st.Top() << "\n";
    st.pop();
    cout << st.Top();
    cout << st.empty();
}