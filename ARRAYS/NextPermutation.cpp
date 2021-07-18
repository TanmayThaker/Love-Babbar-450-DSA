// Practice Link : https://leetcode.com/problems/next-permutation/submissions/

// See Video : https://www.youtube.com/watch?v=LuLCLgMElus
class Solution {
public:
    void swap(vector<int> &nums,int i,int j)
    {
        int temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }
    
    void reverse(vector<int> &nums,int i,int j)
    {
        while(i<j)
        {
            swap(nums,i++,j--);
        }
    }
    
    void nextPermutation(vector<int>& nums) {
        if(nums.size()==0 or nums.size()==1) return;
        int s = nums.size();
        int i=s-2; //first breakpoint might liw at the second last index
        while(i>=0 and nums[i]>=nums[i+1])
        {
            i--;
        }
        if(i>=0)
        {
            int j=s-1;
            while(nums[j]<=nums[i])
            {
                j--;
            }
            swap(nums,i,j);
        }
        reverse(nums,i+1,s-1);
    }
    
   
};

/*
 TC : O(N)
 SC : O(1)
*/