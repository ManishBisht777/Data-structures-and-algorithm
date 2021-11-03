ll findSubarray(vector<ll> arr, int n)
{
    //code here
    long long cnt = 0;
    unordered_map<long long, int> m;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0)
        {
            cnt++;
        }
        if (m.find(sum) != m.end())
        {
            cnt += m[sum];
        }
        m[sum]++;
    }
    return cnt;
}