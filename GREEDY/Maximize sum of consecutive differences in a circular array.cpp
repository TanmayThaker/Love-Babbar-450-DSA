//link : https://practice.geeksforgeeks.org/problems/swap-and-maximize5859/1
//Video link: https://www.youtube.com/watch?v=l1N1o7-Ufds

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int maxSum(int arr[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;++i)
			cin>>arr[i];
		cout<<maxSum(arr,n)<<endl;
	}
	return 0;
}// } Driver Code Ends


long long int maxSum(int arr[], int n)
{
    long long int sum=0;
    sort(arr,arr+n);
    long long int l=0;
    long long int r=n-1,k=0;
    int arr1[n];
    while(l<r)
    {
        arr1[k++]=arr[l++];
        arr1[k++]=arr[r--];
    }
     //If there are odd numbers
    if(n%2==1)
    {
        arr1[k]=arr[l];
    }
    
    for(int i=0;i<n-1;i++)
    {
        sum+=abs(arr1[i+1]-arr1[i]);
    }
    
    sum+=arr1[n-1]-arr1[0];
    
    return sum;
}

/*
 Time Complexity: O(N*logN)
 Auxiliary Space: O(1)
*/