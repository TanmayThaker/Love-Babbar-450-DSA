//Problem link : https://practice.geeksforgeeks.org/problems/trailing-zeroes-in-factorial5134/1
// Video Solution : https://www.youtube.com/watch?v=fx8rUY_iIms

// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    int trailingZeroes(int N)
    {
        // Write Your Code here
        int res=0;
        int p=5;
        while((N/p)!=0)
        {
            res+=(N/p);
            p*=5;
        }
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        int ans  = ob.trailingZeroes(N);
        cout<<ans<<endl;
    }
    return 0;
}  // } Driver Code Ends