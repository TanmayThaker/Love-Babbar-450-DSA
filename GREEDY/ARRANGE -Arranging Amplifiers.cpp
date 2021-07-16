#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int ones = 0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==1)
            {
                ones++;
            }
        }
        sort(a,a+n,greater<int>());
        for(int i=0;i<ones;i++)
        {
            cout<<"1 "<<endl;
        }
        if((n-ones)==2 and a[0]==3 and a[1]==2)
        {
            cout<<"2 3"<<endl;
        }
        else
        {
            for(int i=0;i<(n-ones);i++)
            {
                cout<<a[i]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}