#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int arr[] = {12, 3, 7, 1, 6, 9};
    sort(arr, arr + 6);
    int target = 24;
    bool ans = false;
    for (int i = 0; i < 6; i++)
    {
        int low = i + 1;
        int high = 5;
        while (low < high)
        {
            int curr = arr[i] + arr[low] + arr[high];
            if (curr == target)
            {
                ans = true;
            }
            if (curr < target)
            {
                low++;
            }
            else
            {
                high--;
            }
        }
    }
    cout << ans;
}