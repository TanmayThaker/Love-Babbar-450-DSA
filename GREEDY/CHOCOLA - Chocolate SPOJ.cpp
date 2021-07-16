#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        m--;
        n--;
        int x[m];
        int y[n];
        for(int i=0;i<m;i++)
        {
            cin>>x[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>y[i];
        }
        sort(x,x+m,greater<int> ());
        sort(y,y+n,greater<int> ());

        int horizontal_count= 1;
        int vertical_count = 1;

        int ans=0;
        int i=0,j=0;

        while(i<m and j<n)
        {
            if(x[i]>y[j]) //vertical is more than horizantal
            {
                ans += x[i]*vertical_count;
                horizontal_count++; //we increase the count for horizonatal
                i++;
            }
            else
            {
                ans +=  y[j]*horizontal_count;
                vertical_count++;
                j++;
            }
        }
        while(i<m)
        {
            ans += x[i]*vertical_count;
            horizontal_count++;
            i++;
        }
        while(j<n)
        {
            ans += y[j]*horizontal_count;
            vertical_count++;
            j++;
        }
        cout<<ans<<endl;
    }
    return 0;
}

//Time complexity : O(NlogN) //sorting
//Space complexity : O(1)