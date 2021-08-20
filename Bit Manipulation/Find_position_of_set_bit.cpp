//Practice link : https://practice.geeksforgeeks.org/problems/find-position-of-set-bit3706/1
//Video Solution : https://www.youtube.com/watch?v=CwbYI5yoaCM

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  bool isPowerOfTwo(int n)
  {
      if(n==0) return false;
      return (n&(n-1))==0;
      
  }
    int findPosition(int N) {
        // code here
        if(isPowerOfTwo(N)==false) return -1;
        int count=0;
        while(N!=0)
        {
            N=N>>1;
            count++;
            
        }
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}  // } Driver Code Ends