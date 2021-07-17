//Find next greater number with same set of digits
//Video link : https://www.youtube.com/watch?v=LuLCLgMElus
//Practice link 1 : https://leetcode.com/problems/next-permutation/
//Practice link 2 : https://practice.geeksforgeeks.org/problems/next-permutation5226/1#

// --> Easy Approach
    
    void nextPermutation(vector<int>& nums) {
        int n=nums.size()-1;
        for(int k=n-2;k>=0;k--)
        {
            if(nums[k]<nums[k+1])
            {
                break;
            }
        }
        if(k<0)
        {
            reverse(nums.begin(),nums.end());
        }
        else
        {
            for(int l=n-1;l>=0;l--)
            {
                if(nums[l]>nums[k])
                {
                    break;
                }
            }
            swap(nums[k],nums[l]);
            reverse(nums.begin()+k+1,nums.end());
        }
    }




//----------------------------------------------------------------------------------------------------------------------

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
        int i=s-2; //first breakpoint might lie at the second last index
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
TC:O(N)
SC:O(1)
*/