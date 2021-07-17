//Best Time to Buy and Sell Stocks with Transaction Fee and Infinite Transactions
//Video Solution : https://www.youtube.com/watch?v=pTQB9wbIpfU&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=32

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
    int fee;
    cin>>fee;

    //In buy state profit we take one more stock so that we can see it later and make profit from it if feasible

    int bsp=-arr[0]; //First buy state profit (basically it represents old buy state profit)
    int ssp=0; //first sale state profit is always zero (basically it represents old sell state profit)
    
    for(int i=1;i<n;i++)
    {
        int nbsp=0;
        int nssp=0;

        if(ssp-arr[i]>bsp)
        {
            nbsp=ssp-arr[i];
        }
        else{
            nbsp=bsp;
        }
        if(bsp+arr[i]-fee>ssp)
        {
            nssp=bsp+arr[i]-fee;
        }
        else{
            nssp=ssp;
        }
        bsp=nbsp;
        ssp=nssp;
    }
    cout<<ssp<<endl;
    return 0;
}