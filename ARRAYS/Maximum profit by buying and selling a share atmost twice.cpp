//Maximum profit by buying and selling a share atmost twice
//Problem link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
//Video Solution : https://www.youtube.com/watch?v=wuzTpONbd-0&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=34

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0) return 0;
        int oneBuy=INT_MAX,twoBuy=INT_MAX,oneBuyOneSell=0,twoBuyTwoSell=0;
        for(int i=0;i<n;i++)
        {
            int price=prices[i];
            oneBuy=min(oneBuy,price);
            oneBuyOneSell=max(oneBuyOneSell,price-oneBuy);
            twoBuy = min(twoBuy, price-oneBuyOneSell);
            twoBuyTwoSell = max(twoBuyTwoSell, price-twoBuy);
        }
        return twoBuyTwoSell;
    }
};
