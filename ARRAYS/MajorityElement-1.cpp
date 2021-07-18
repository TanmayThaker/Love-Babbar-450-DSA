//Problem link : https://leetcode.com/problems/majority-element/submissions/

//Video solution : https://www.youtube.com/watch?v=AoX3BPWNnoE

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int candidate=0;
        for(auto num:nums)
        {
            if(count==0)
            {
                candidate=num;
            }
            if(num==candidate) count+=1;
            else {
                count-=1;
            }
        }
        return candidate;
    }
}

/*
TC:O(1)

SC:O(1)
*/