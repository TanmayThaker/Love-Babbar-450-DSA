//Count pairs with given sum

//Practice link : https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1#

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        // code here
        /*sort(arr,arr+n);
        int i=0;
        int j=n-1;
        int count=0;
        while(i<n and j>0)
        {
            if(arr[i]+arr[j]==k)
            {
                count++;
                i++;
                j--;
            }
            else if(arr[i]+arr[j]<k)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return count;
        */
        
        unordered_map<int,int> hash;
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(hash.find(k-arr[i])!=hash.end())
            {
                count+=hash[k-arr[i]];
            }
            if(hash.find(arr[i])!=hash.end())
            {
                hash[arr[i]]++;
            }
            else
            {
                hash.insert({arr[i],1});
            }
        }
        return count;
    
    }
};


/*
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
*/