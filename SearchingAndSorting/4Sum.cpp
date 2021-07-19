
//Find 4 elements in an array that sums up to a given target 'k'

//Practice Link : https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) 
    {
        // Your code goes here
        vector<vector<int>> res;
        if(arr.empty())
        {
            return res;
        }
        int n=arr.size();
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int target = k-arr[j]-arr[i];
                
                int front = j+1;
                int back = n-1;
                
                while(front < back)
                {
                    int two_sum = arr[front]+arr[back];
                    if(two_sum<target)
                    {
                        front++;
                    }
                    else if(two_sum>target) 
                    {
                        back--;
                    }
                    else
                    {
                        vector<int> quadrplet(4,0);
                        quadrplet[0]=arr[i];
                        quadrplet[1]=arr[j];
                        quadrplet[2]=arr[front];
                        quadrplet[3]=arr[back];
                        res.push_back(quadrplet);
                        
                        while(front<back and arr[front]==quadrplet[2]) 
                        {
                            front++;
                        }
                        while(front<back and arr[back]==quadrplet[3]) 
                        {
                            back--;
                        }
                    }
                }
                while(j+1<n and arr[j+1]==arr[j])
                {
                    j++;
                }
            }
            while(i+1<n and arr[i+1]==arr[i])
            {
                i++;
            }
        }
        return res;
    }
};