//GFG Practice link : https://practice.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

int maxLen(int A[], int n)
{
    // Your code here
    int sum=0;
    int maxs=0;
    unordered_map<int,int> m;
    for(int i=0;i<n;i++)
    {
        sum+=A[i];
        if(sum==0)
        {
            maxs=i+1;
        }
        else
        {
            if(m.find(sum)!=m.end())
            {
                maxs=max(maxs,i-m[sum]);
            }
            else{
                m[sum]=i;
            }
        }
    }
    return maxs;
    
}


