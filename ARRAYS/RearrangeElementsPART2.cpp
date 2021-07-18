// Practice link : https://practice.geeksforgeeks.org/problems/-rearrange-array-alternately-1587115620/1#

/*
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1)
*/

/*
Question:
Given a sorted array of positive integers. Your task is to rearrange  the array elements alternatively i.e first element should be 
max value, second should be min value, third should be second max, fourth should be second min and so on.
*/


class Solution{
    public:
    // This function wants you to modify the given input
    // array and no need to return anything
    // arr: input array
    // n: size of array
    //Function to rearrange  the array elements alternately.
    void rearrange(long long *arr, int n) 
    { 
    	
    	// Your code here
    	int max = arr[n-1]+1;
    	int max_index = n-1;
    	int min_index = 0;
    	for(int i=0;i<n;i++)
    	{
    	    if(i%2==0)
    	    {
    	        arr[i]=(arr[max_index]%max)*max + arr[i]; //arr[max_index]%max will give us new values and arr[i] will give us old values
    	        max_index--;
    	    }
    	    else
    	    {
    	        arr[i]=(arr[min_index]%max)*max + arr[i];  //arr[min_index]%max will give us new values and arr[i] will give us old values
    	        min_index++;
    	    }
    	}
    	for(int i=0;i<n;i++)
    	{
    	    arr[i]/=max;
    	}
    }
};