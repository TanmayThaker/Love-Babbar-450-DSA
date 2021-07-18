#include<bits/stdc++.h>
uisng namespace std;

//Using Kadane's Algorithm

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(nt i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int max_till_now=0;
    int max=INT_MIN;
    for(int i=0;i<n;i++)
    {
        max_till_here=max_till_here+arr[i];
        if(max_till_now>max)
        {
            max=max_till_now;
        }
        if(max_till_now<0)
        {
            max_till_now=0;
        }
    }
    cout<<max<<endl;
    return 0;
}

/*
TC:O(N)
SC:O(1)
*/