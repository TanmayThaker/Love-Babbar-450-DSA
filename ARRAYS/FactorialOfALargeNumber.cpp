
//Practice link : https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1#

class Solution {
public:
    void multiply(int x,vector<int> &res)
    {
        int carry = 0;
        for(int i=0;i<res.size();i++)
        {
            int product = res[i]*x + carry;
            res[i] = product % 10;
            carry = product /10;
        }
        while(carry)
        {
            res.push_back(carry%10);
            carry=carry/10;
        }
    }
    vector<int> factorial(int N){
        // code here
        vector<int> res;
        res.push_back(1);
        for(int x=2;x<=N;x++)
        {
            multiply(x,res);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

/*
Expected Time Complexity : O(N2)
Expected Auxilliary Space : O(1)
*/