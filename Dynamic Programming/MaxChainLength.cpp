#include<bits/stdc++.h>
using namespace std;

class Pair
{
    public:
    int a,b;
};
// This function assumes that arr[] 
// is sorted in increasing order 
// according the first (or smaller) values in Pairs.
int maxChainLength(Pair arr[],int n)
{
    int i,j,max=0;
    int *mcl = new int[sizeof(int) *n];
    //Initializing maximum chain length for all the indexes
    for(int i=0;i<n;i++)
    {
        mcl[i]=1;
    }
    for(i=1;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(arr[i].a>=arr[j].b and mcl[i]<=mcl[j]+1)
            {
                mcl[i]=mcl[j]+1;
            }
        }
    }
    // mcl[i] now stores the maximum chain length ending with Pair i 
    //Pick up maximum of all MCl values
    for(int i=0;i<n;i++)
    {
       if(max<mcl[i])
       {
           max=mcl[i];
       }
    }
    return max;
}

int main() 
{ 
	Pair arr[] = { {5, 24}, {15, 25}, 
						{27, 40}, {50, 60} }; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	cout << "Length of maximum size chain is " << maxChainLength( arr, n ); 
	return 0; 
} 