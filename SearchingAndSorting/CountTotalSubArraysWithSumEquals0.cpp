//You are given an array arr[] of size n. Find the total count of sub-arrays having their sum equal to 0.

//GFG Practice link : https://practice.geeksforgeeks.org/problems/zero-sum-subarrays1825/1#

class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) {
        //code here
        ll res = 0;
        ll sum = 0;
        unordered_map<long long,long long> m;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            if(sum==0)
            {
                res++;
            }
            res+=m[sum];
            m[sum]++;
        }
        return res;
    }
};