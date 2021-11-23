# include<iostream>
# include <algorithm>
# include <vector>
# include <set>

using namespace std;

vector<vector<int>> foursum(int arr[], int n , int k)
{
    sort(arr,arr+n);
    set<vector<int>> s;

    for(int i=0; i<n ;i++)
    {
        for(int j=i+1;j<n ;j++)
        {
            int start=j+1;
            int end=n-1;
            while(start<end)
            {
                int sum=arr[i]+arr[j]+arr[start]+arr[end];

                if(sum==k)
                {
                    vector<int> temp={arr[i],arr[j],arr[start],arr[end]};
                    s.insert(temp);
                    start++;
                    end--;
                }
                else if(start>k)
                {
                    end--;
                }
                else{
                    start++;
                }
            }
        }
    }

    vector<vector<int>> ans (s.begin(),s.end());

    return ans;
}

int main()
{

}