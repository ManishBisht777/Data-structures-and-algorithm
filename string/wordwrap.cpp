int solveWordWrap(vector<int>arr, int k) 
    { 
        int n=arr.size();
        int i, j,currlen,cost;
        int dp[n];
        dp[n-1]=0;
        for(i=n-2;i>=0;i--)
        {
            currlen=-1;
            dp[i]=INT_MAX;
            
            for(j=i; j<n ;j++)
            {
                currlen+=arr[j]+1;
                if(currlen>k)
                {
                    break;
                }
                if(j==n-1)
                {
                    cost=0;
                }
                else
                    cost=(k-currlen)*(k-currlen) + dp[j+1];
                if(cost<dp[i])
                {
                    dp[i]=cost;
                }
                
            }
        }
        return dp[0];
    } 