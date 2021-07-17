//Practice link : https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1#
//Video link : https://www.youtube.com/watch?v=2pH6E9th0EY

class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        if(n==1) return 0;
        priority_queue<long long,vector<long long> , greater<long long>> pq;
        for(int i=0;i<n;i++)
        {
            pq.push(arr[i]); //This operation will take time O(NlogN)
        }
        long long ans=0;
        while(pq.size()>1)
        {
            long long x=pq.top();
            pq.pop(); //O(logN)
            long long y=pq.top();
            pq.pop();
            ans+=(x+y);
            pq.push(x+y);//O(logN)
        }
        return ans;
    }
};
/*
TC:O(NlogN)
SC: O(N)

*/