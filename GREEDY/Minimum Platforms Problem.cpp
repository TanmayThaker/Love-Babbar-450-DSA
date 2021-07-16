//Practice link : 

//My GFG Solution
//TC: O(N * logN)
//SC: O(1)

//Note that : This problem can also be done using priority queue ,
//In that case the TC: O(N * logN)
//SC: O(N)
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	int pt_no = 1;
    	int j=0;
    	int i=1;
    	while(i<n)
    	{
    	    if(arr[i]<=dep[j])
    	    {
    	        pt_no++;
    	    }
    	    else
    	    {
    	        j++;
    	    }
    	    i++;
    	}
    	return pt_no;
    }
};



// ----------------------------------------------------------------------------------------------------------------------- //
/*
	TC: O(N * logN)
	SC: O(1)
*/

// Program to find minimum number of platforms
// required on a railway station
#include <algorithm>
#include <iostream>

using namespace std;

// Returns minimum number of platforms reqquired
int findPlatform(int arr[], int dep[], int n)
{
	// Sort arrival and departure arrays
	sort(arr, arr + n);
	sort(dep, dep + n);

	// plat_needed indicates number of platforms
	// needed at a time
	int plat_needed = 1, result = 1;
	int i = 1, j = 0;

	// Similar to merge in merge sort to process
	// all events in sorted order
	while (i < n && j < n) {
		// If next event in sorted order is arrival,
		// increment count of platforms needed
		if (arr[i] <= dep[j]) {
			plat_needed++;
			i++;
		}

		// Else decrement count of platforms needed
		else if (arr[i] > dep[j]) {
			plat_needed--;
			j++;
		}

		// Update result if needed
		if (plat_needed > result)
			result = plat_needed;
	}

	return result;
}

// Driver code
int main()
{
	int arr[] = { 900, 940, 950, 1100, 1500, 1800 };
	int dep[] = { 910, 1200, 1120, 1130, 1900, 2000 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Minimum Number of Platforms Required = "
		<< findPlatform(arr, dep, n);
	return 0;
}