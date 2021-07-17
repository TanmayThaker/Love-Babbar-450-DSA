//Minimum_Swaps_For_Bracket_Balancing
//Practice kink : https://practice.geeksforgeeks.org/problems/minimum-swaps-for-bracket-balancing2704/1
//Video Solution : https://www.youtube.com/watch?v=Ylz6mwghDrU

class Solution{   
public:
    int minimumNumberOfSwaps(string S){
        // code here 
        int n=S.length();
        int open=0;
        int close=0;
        int fault=0;
        int ans=0;
        for(int i=0;i<=n;i++)
        {
            if(S[i]==']')
            {
                close++;
                fault=close-open;
            }
            else
            {
                open++;
                if(fault>0)
                {
                    ans+=fault;
                    fault--;
                }
            }
        }
        return ans;
    }
};



/*
TC:O(N)
SC:O(1)
*/