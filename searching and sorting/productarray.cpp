vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
{
    long long int p = 1, p2 = 1;
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
            c++;

        if (nums[i] != 0)
            p2 = p2 * nums[i];

        p = p * nums[i];
    }
    vector<long long> v;
    if (p == 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (c >= 2)
            {
                v.push_back(0);
                continue;
            }
            if (nums[i] != 0)
                v.push_back(0);
            else
            {
                v.push_back(p2);
            }
        }
        return v;
    }

    for (int i = 0; i < n; i++)
        v.push_back(p / nums[i]);

    return v;
}