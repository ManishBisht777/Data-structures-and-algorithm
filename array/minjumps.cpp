#include <iostream>

using namespace std;

int minJumps(int arr[], int n)
{
    // Your code here
    int jump = 0;
    int count = 0;
    int i = 0;
    while (i < n - 1)
    {
        jump = arr[i];
        if (jump == 0)
        {
            return -1;
        }
        i = i + jump;
        count++;
    }
    return count;
}

int main()
{
    int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    cout << minJumps(arr, 11);
}