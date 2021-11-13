bool threesum(int arr[], int n, int m)
{
    sort(arr, arr + n);

    for (int i = 0; i < n; i++)
    {
        int start = i + 1;
        int end = n - 1;

        while (start < end)
        {
            int sum = arr[i] + arr[start] + arr[end];

            if (sum == k)
                return true;
            else if (sum < k)
                start++;
            else
                end--;
        }
    }
    return false;
}