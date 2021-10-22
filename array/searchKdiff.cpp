int search(int arr[], int n, int k, int x)
{
    while (i < n)
    {
        if (arr[i] == x)
        {
            return i;
        }

        i = i + max(abs(arr[i] - x) / k);
    }
}