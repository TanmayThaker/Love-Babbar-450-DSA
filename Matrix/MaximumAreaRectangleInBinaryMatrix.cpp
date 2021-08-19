//Maximum size rectangle
//Link : 
//Video Solution :// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        if(n==0) return 0;
        
        vector<vector<int>> dp(n+1,vector<int>(m));
       int mx=0;
       for(int i=1;i<=n;i++)
       {
           int leftBound = -1;
           stack<int> st;
           vector<int> left(n);
           for(int j=0;j<m;j++)
           {
               if(M[i][j]==1)
               {
                   M[i][j]=1+M[i-1][j];
                   while(!st.empty() and M[i][st.top()]>=M[i][j])
                   {
                       st.pop();
                   }
                   int val = leftBound;
                   if(!st.empty())
                   {
                       val = max(val,st.top());
                   }
                   left[j]=val;
               }
               else{
                   leftBound = j;
                   
               }
           }
           while(!st.empty())
           {
               st.pop();
           }
           int rightBound = m;
           for(int j=m-1;j>=0;j--)
           {
               if(M[i][j]==1)
               {
                   while(!st.empty() and M[i][st.top()]>=M[i][j])
                   {
                       st.pop();
                   }
                   int val = rightBound;
                   if(!st.empty())
                   {
                       val = min(val,st.top());
                   }
                   dp[i][j]=M[i][j]*((val-1)-(left[j]+1)+1);
                   mx = max(mx,dp[i][j]);
                   st.push(j);
               }
               else
               {
                   dp[i][j]=0;
                   rightBound = j;
               }
           }
        }
        return mx;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends