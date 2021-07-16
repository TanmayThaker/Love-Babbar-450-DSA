//Smallest subset with sum greater than all other elements

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int s=0;
    int s1=0;
    for(int i=0;i<n;i++)
    {
        s=s+a[i];
    }
    int ans=0;
    int j=n-1;
    while(true)
    {
        s1+=a[j];
        s=s-a[j];
        j--;
        ans++;
        if(s1>s)
        {
            break;
        }
        
    }
    cout<<ans;
    return 0;
}
