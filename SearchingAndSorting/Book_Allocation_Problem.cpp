//Problem link : https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1#
//Video Solution : https://www.youtube.com/watch?v=2JSQIhPcHQg

// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
public:
    bool isValid(int *arr, int n, int m, int mid)
    {
        int students = 1;
        int sum = arr[0];
        for (int i = 1; i < n; i++)
        {
            sum += arr[i];
            if (sum > mid)
            {
                students++;
                sum = arr[i];
            }
            if (students > m)
                return false;
        }
        return true;
    }
    //Function to find minimum number of pages.
    int findPages(int arr[], int n, int m)
    {
        //code here
        if (n < m)
            return -1;
        int sum = 0;
        int start = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            start = max(start, arr[i]);
        }
        int st = start;
        int end = sum;
        int res = -1;
        while (st <= end)
        {
            int mid = st + (end - st) / 2;
            if (isValid(arr, n, m, mid))
            {
                res = mid;
                end = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
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
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends