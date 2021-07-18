//Practice link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
//Video link : https://www.youtube.com/watch?v=pTQB9wbIpfU&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=32

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int obsp=-prices[0];
        int ossp=0;
        int ocsp=0;
        
        for(int i=1;i<prices.size();i++)
        {
            int nbsp=0;
            int nssp=0;
            int ncsp=0;
            
            if(ocsp-prices[i]>obsp)
            {
                nbsp=ocsp-prices[i];
            }
            else
            {
                nbsp=obsp;
            }
            
            if(obsp+prices[i]>ossp)
            {
                nssp=obsp+prices[i];
            }
            else
            {
                nssp=ossp;
            }
            
            if(ossp>ocsp)
            {
                ncsp=ossp;
            }
            else
            {
                ncsp=ocsp;
            }
            
            obsp=nbsp;
            ossp=nssp;
            ocsp=ncsp;
        }
        return ossp;
    }
};