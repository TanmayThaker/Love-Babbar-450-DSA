//Problem link : https://practice.geeksforgeeks.org/problems/product-array-puzzle4525/1
//Leetcode link : https://leetcode.com/problems/product-of-array-except-self/submissions/
//Video Solution : https://www.youtube.com/watch?v=gREVHiZjXeQ

// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here
        vector<long long int> ans;
        if(n<1) return ans;
        long long int product=1;
        for(int i=0;i<n;i++)
        {
            product*=nums[i];
            ans.push_back(product);
        }
        
        long long int pro=1;
        long long int temp=ans[n-2];
        for(int i=n-1;i>0;i--)
        {
            ans[i]=ans[i-1]*pro;
            pro*=nums[i];
        }
        ans[0]=pro;
        return ans;
    }
};


// { Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends