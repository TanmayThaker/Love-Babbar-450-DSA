// Maximize array sum after K negations 
//Practice Link : https://practice.geeksforgeeks.org/problems/maximize-sum-after-k-negations1149/1
//Video Explanation : https://www.youtube.com/watch?v=8GDHYgbxTN4&list=PLDdcY4olLQk3cAxZPJXMbxqrM3PlNkmO8&index=11

class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        // Your code goes here
        sort(a,a+n);
        long long int sum = 0;
        for(int i=0;i<n;i++)
        {
            if(a[i]<0 and k>0)
            {
                a[i]=-a[i];
                k--;
            }
        }
        for(int i=0;i<n;i++)
        {
            sum+=a[i];
        }
        int min_ele  = *min_element(a,a+n);
        if(k&1) sum=sum-2*min_ele; //(k&1) means our K is odd
        return sum;
    }
};

//Time Complexity : O(NlogN) //for sorting

//Space Complexity : O(1)