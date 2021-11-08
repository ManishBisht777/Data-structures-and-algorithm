int kthElement(int arr1[], int arr2[], int n, int m, int k)
{
    int i = 0, j = 0;
    int count = 0;
    while (i < n and j < m)
    {
        if (arr1[i] > arr2[j])
        {
            count++;
            if (count == k)
            {
                return arr2[j];
            }
            j++;
        }
        else
        {
            count++;
            if (count == k)
            {
                return arr1[i];
            }
            i++;
        }
    }

    while (i < n)
    {
        count++;
        if (count == k)
        {
            return arr1[i];
        }
        i++;
    }
    while (j < m)
    {
        count++;
        if (count == k)
        {
            return arr2[j];
        }
        j++;
    }
}