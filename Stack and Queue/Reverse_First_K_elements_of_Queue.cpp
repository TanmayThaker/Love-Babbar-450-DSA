//Practice link : https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1
//Video Solution : https://www.youtube.com/watch?v=HAnIGZdSZ6E

// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main(){
    int t;
    cin>>t;
    while(t-->0){
        int n,k;
        cin>>n>>k;
        queue<int> q;
        while(n-->0){
            int a;
            cin>>a;
            q.push(a);
        }
        queue<int> ans=modifyQueue(q,k);
        while(!ans.empty()){
            int a=ans.front();
            ans.pop();
            cout<<a<<" ";
        }
        cout<<endl;
    }
}// } Driver Code Ends


//User function Template for C++

//Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k)
{
    //add code here.
    stack<int> st;
   for(int i=1;i<=k;i++)
    {
        st.push(q.front());
        q.pop();
    }
    while(!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    
    int n=q.size();
    for(int i=1;i<=n-k;i++)
    {
        int x = q.front();
        q.push(x);
        q.pop();
    }
    return q;
}