// ----------------------------------------------------------------------------------------------------------------------- //
// Naive solution
int maxSubarrayProduct(int arr[], int n)
{
    // Initializing result
    int result = arr[0];

    for (int i = 0; i < n; i++)
    {
        int mul = arr[i];
        // traversing in current subarray
        for (int j = i + 1; j < n; j++)
        {
            // updating result every time
            // to keep an eye over the maximum product
            result = max(result, mul);
            mul *= arr[j];
        }
        // updating the result for (n-1)th index.
        result = max(result, mul);
    }
    return result;
}
/*
TC:O(N^2)
SC:O(1)
*/

//-------------------------------------------------------------------------------------------------------------------------------------------------


/*
APPROACH : 2

So there can be 3 cases:
1. all elements are +ve -> answer = product of all elements
2. number of -ve elements is even -> answer = product of all elements
3. number of -ve elements are odd-> 
Use modified Kandane's algorithm[1 and 2 also included]
consider three factors at every point of iteration:
a. arr[i]
b. minimum_so_far
c. maximum_so_far

you need to consider minimum_so_far because it may become maximum at any point[eg: -26*-1 = 26]
similarly, maximum_so_far may become minimum at any point may become minimum...and this later may become our answer...

so just considering a. and c. will not work for an array containing negative numbers.
for better understanding try this out->
[1, -6, -1, 3, 4, -1, 0]

if you do not consider, minimum_so_far, the answer will be 12 but the answer should be -1*-6*3*4 = 72
*/

class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(int *arr, int n) {
	    // code here
	    long long omax=arr[0]; Putting INT_MIN doesn't work
	    long long curMax=arr[0];
	    long long curMin=arr[0];
	    
	    for(int i=1;i<n;i++)
	    {
	        if(arr[i]==0)
	        {
	            curMax=1;
	            curMin=1;
	            continue;
	        }
	        
	        long long temp=(long long)arr[i]*curMax;
	        curMax=max((long long)arr[i],max((long long)arr[i]*curMax,(long long)arr[i]*curMin));
	        curMin=min((long long)arr[i],min(temp,(long long)arr[i]*curMin));
	        
	        if(omax<curMax)
	        {
	            omax=curMax;
	        }
	    }
	    return omax;
	}
};

//3rd Approach

long long maxProduct(int* arr, int n) {
        // Variables to store maximum and minimum
        // product till ith index.
    long long minVal = arr[0];
    long long maxVal = arr[0];

    long long maxProduct = arr[0];

    for (int i = 1; i < n; i++) {

        // When multiplied by -ve number,
        // maxVal becomes minVal
        // and minVal becomes maxVal.
        if (arr[i] < 0) swap(maxVal, minVal);

        // maxVal and minVal stores the
        // product of subarray ending at arr[i].
        maxVal = max((long long)arr[i], maxVal * arr[i]);
        minVal = min((long long)arr[i], minVal * arr[i]);

        // Max Product of array.
        maxProduct = max(maxProduct, maxVal);
    }

    // Return maximum product found in array.
    return maxProduct;
}