/*
A simple solution is to generate all subsets, find product of every subset and return maximum product.
A better solution is to use the below facts.

If there are even number of negative numbers and no zeros, result is simply product of all
If there are odd number of negative numbers and no zeros, result is product of all except the negative integer with the least absolute value.
If there are zeros, result is product of all except these zeros with one exceptional case. The exceptional case is when there is one negative number and all other elements are 0. In this case, result is 0.


*/

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//Maximum product subset of an array

//Here there are three corner cases

//Example 1: 0 0 0 -3
// --> Here we have to take 0 because 0 > -3

//Example 2 : 1 0 0 0 
// --> Here we cannot take 0 because it will make overall product 0. Hence 1 will be our answer

//Example 3 : -1 -2 - 3 -4 -5
// --> Here we have to remove highest number i.e. (-1) and we have to take even negatibe numbers so that (-)*(-) = (+) 
// --> We can do this by taking abs(i) for each value


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int zero_count=0;
    int negative_count=0;
    int prod=1;
    int max_negative=INT_MIN;
    for(int i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            zero_count++;
            continue;
        }
        if(a[i]<0)
        {
            negative_count++;
            max_negative=max(max_negative,a[i]);
        }
        prod=prod*a[i];
    }
    //Corner Cases
    if(zero_count==n)
    {
        cout<<"0"<<endl;
        return 0;
    }
    else if(negative_count==1 and zero_count+negative_count==n)
    {
        cout<<"0"<<endl;
        return 0;

    }
    else if(negative_count&1)
    {
        prod=prod/max_negative;
    }
    cout<<prod<<endl;
    return 0;
}

/*
	Time Complexity: O(n)
	Auxiliary Space: O(1)
*/