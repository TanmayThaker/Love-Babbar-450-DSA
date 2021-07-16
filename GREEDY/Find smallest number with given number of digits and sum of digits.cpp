//Find smallest number with given number of digits and sum of digits 

//Practice Link : https://practice.geeksforgeeks.org/problems/smallest-number5829/1#

class Solution{   
public:
    string smallestNumber(int S, int D){
        // code here 
        if(S>9*D) return "-1";
        string ans="";
        for(int i=D-1;i>=0;i--)
        {
            if(S>9)
            {
                ans = "9" + ans;
                S = S-9;
            }
            else
            {
                if(i==0)
                {
                    ans = to_string(S) + ans;
                }
                else
                {
                    ans = to_string(S-1) + ans;
                    i--;
                    while(i>0)
                    {
                        ans = "0" + ans;
                        i--;
                    }
                    ans = "1" + ans;
                    break;
                }
            }
        }
        return ans;
    }
};

/*

Expected Time Complexity: O(D)
Expected Auxiliary Space: O(1)

 
*/