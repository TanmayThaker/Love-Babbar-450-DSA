/*
Problem link : https://leetcode.com/problems/trapping-rain-water/submissions/
Video link : https://www.youtube.com/watch?v=m18Hntz4go8
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int res=0;
        int n=height.size();
        int left=0,right=n-1;
        int maxleft=0,maxright=0;
        
        while(left<=right)
        {
            if(height[left]<=height[right])
            {
                if(height[left]>=maxleft) maxleft=height[left];
                else res+=maxleft-height[left];
                left++;
            }
            else
            {
                if(height[right]>=maxright) maxright=height[right];
                else res+=maxright-height[right];
                right--;
            }
        }
        return res;
    }
};

/*
 TC : O(N) //for using two pointer approach
 SC : O(1)
*/

