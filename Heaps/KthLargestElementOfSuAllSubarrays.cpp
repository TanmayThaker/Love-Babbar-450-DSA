#include<bits/stdc++.h>
using namespace std;

int kthLargestSum(int a[],int n,int k){
    int sum[n+1];
    sum[0]=0;
    sum[1]=a[0];
    for(int i=2;i<=n;i++)
    {
        sum[i]=sum[i-1]+a[i-1]; //calculating the prefix sum
    }
    priority_queue<int,vector<int>,greater<int>> Q;

    //calculating the contiguous subarray
    for(int i=1;i<=n;i++)
    {
         // loop to traverse all positions that
        // form contiguous subarray
        for(int j=i;j<=n;j++)
        {
            int x = sum[j]-sum[i-1];

            if(Q.size()<k)
            {
                Q.push(x);
            }

            else
            {
                if(Q.top()<x)
                {
                    Q.pop();
                    Q.push(x);
                }
            }
        }
    }
    return Q.top();
}

int main()
{
    int a[] = { 10, -10, 20, -40 };
    int n = sizeof(a) / sizeof(a[0]);
    int k = 6;
 
    // calls the function to find out the
    // k-th largest sum
    cout << kthLargestSum(a, n, k);
    return 0;
}

/*
Time complexity: O(n^2 log (k)) 
Auxiliary Space : O(k) for min-heap and we can store the sum array in the array itself as it is of no use.
*/