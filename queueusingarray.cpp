#include <iostream>
#define n 100

using namespace std;

class queue
{
    int *arr;
    int front;
    int back;

public:
    queue()
    {
        arr = new int[n];
        front = -1;
        back = -1;
    }

    void push(int x)
    {
        if (back == n - 1)
        {
            cout << "\n\t QUEUE FULL ";
        }

        back++;
        arr[back] = x;

        if (front == -1)
        {
            front++;
        }
    }

    void pop()
    {
        if (front == -1 && front > back)
        {
            cout << "empty";
        }

        front++;
    }

    int peek()
    {
        if (front == -1 && front > back)
        {
            cout << "empty";
        }

        return arr[front];
    }

    bool isempty()
    {
        if (front == -1 && front > back)
        {
            return true;
        }

        return false;
    }
};

int main()
{
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout << q.peek();
    q.pop();
    cout << q.peek();
    cout << q.isempty();
}