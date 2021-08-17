//Sum of minimum and maximum of all subarrays of size of k
//link : https://www.geeksforgeeks.org/sum-minimum-maximum-elements-subarrays-size-k/
//Video Solution : https://www.youtube.com/watch?v=mUeaCLDdtnM

// C++ program to find sum of all minimum and maximum
// elements Of Sub-array Size k.
#include<bits/stdc++.h>
using namespace std;

int SumOfKsubArray(int arr[] , int n , int k)
{
    int sum=0;
    deque<int> S(k), G(k);
    for(int i=0;i<k;i++)
    {
        while(!S.empty() and arr[S.back()]>=arr[i])
        {
            S.pop_back(); 
        }
        while((!G.empty()) and arr[G.back()]<=arr[i])
        {
            G.pop_back();
        }
        G.psuh_back(i);
        S.push_back(i);
    }

    for(int i=0;i<n;i++)
    {
        while ( !S.empty() && S.front() <= i - k)
            S.pop_front();
        while ( !G.empty() && G.front() <= i - k)
            G.pop_front();

        while ( (!S.empty()) && arr[S.back()] >= arr[i])
            S.pop_back(); // Remove from rear
 
        // remove all previous smaller that are elements
        // are useless
        while ( (!G.empty()) && arr[G.back()] <= arr[i])
            G.pop_back(); // Remove from rear
 
        // Add current element at rear of both deque
        G.push_back(i);
        S.push_back(i);
    }

    sum += arr[S.front()] + arr[G.front()];
 
    return sum;
}


int main()
{
    int arr[] = {2, 5, -1, 7, -3, -1, -2} ;
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    cout << SumOfKsubArray(arr, n, k) ;
    return 0;
}