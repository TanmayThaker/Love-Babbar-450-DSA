//Bishu and Soldiers
//Problem link : https://www.hackerearth.com/problem/algorithm/bishu-and-soldiers-227/
//Video Solution : https://www.youtube.com/watch?v=hT1sOIcenBA

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int q;
    cin>>q;
    sort(arr,arr+n);
    int pre[n+1];
    pre[0]=0;

    for(int i=1;i<=n;i++)
    {
        pre[i]=pre[i-1]+arr[i-1];
    }

    while(q--)
    {
        int x;
        cin>>x;
        int idx=upper_bound(arr,arr+n,x)-arr;
        cout<<idx<<" "<<pre[idx]<<endl;
    }
    return 0;
   
}