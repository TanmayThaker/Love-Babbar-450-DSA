//Smallest number with atleastn trailing zeroes infactorial
//Problem link : https://practice.geeksforgeeks.org/problems/smallest-factorial-number5929/1#

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int zeros(int mid)
    {
        int count = 0;
        while (mid != 0)
        {
            mid = mid / 5;
            count += mid;
        }
        return count;
    }
    int findNum(int n)
    {
        //complete the function here
        int low = 1, high = n * 5, mid, ans = -1;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (zeros(mid) >= n)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.findNum(n) << endl;
    }
    return 0;
} // } Driver Code Ends