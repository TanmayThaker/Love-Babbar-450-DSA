#include <bits/stdc++.h>
using namespace std;

int main()
{
   
    int n,k;
    cin>>n,k;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++)
    {
        v.push_back({a[i],i+1});
    }
    sort(v.begin(),v.end());
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int price = v[i].first;
        int stock = v[i].second;
        if(price * stock <= k)
        {
            ans+=stock;
            k=k-(price*stock);
        }
        else
        {
            ans += (k/price);
            k=k-(price)*(k/price); //    k/price is the available stock and price signifies price of one stock
        }
    }
    cout<<ans;
    return 0;
}


///Time Complexity : O(NlogN) Due to sorting
//Space Complexity : O(N) for taking a vector