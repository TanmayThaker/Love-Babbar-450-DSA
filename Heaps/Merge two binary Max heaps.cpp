//Merge two binary Max heaps
//Link : https://practice.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1

// { Driver Code Starts
// Initial Template for C++

// C++ program to merge two max heaps.

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    void heapify(vector<int> &merged,int i,int n)
    {
        //if(i>=n) return;
        int parent=i;
        int leftChild=2*i+1;
        int rightChild=2*i+2;
        
        if(leftChild<=n and merged[leftChild]>merged[parent])
        {
            parent=leftChild;
        }
        if(rightChild<=n and merged[rightChild]>merged[parent])
        {
            parent=rightChild;
        }
        
        if(i!=parent)
        {
            swap(merged[i],merged[parent]);
            heapify(merged,parent,n);
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        /*
        vector<int> merged(n+m);
        for(int i=0;i<n;i++)
        {
            merged[i] = a[i];
        }
        for(int i=0;i<m;i++)
        {
            merged[i+n] = b[i];
        }
        
        int firstNonLeafNode = (n+m)/2-1;
        
        for(int i=firstNonLeafNode;i>=0;i--)
        {
            heapify(merged,i,n+m);
        }
        return merged;
        */
        for(auto x:b) a.push_back(x);
        n=n+m;
        for(int i=n/2-1;i>=0;i--)
        {
            heapify(a,i,n-1);
        }
        return a;
    }
};



// { Driver Code Starts.

bool isMerged(vector<int> &arr1, vector<int> &arr2, vector<int> &merged){
    if (arr1.size() + arr2.size() != merged.size()){
        return false;
    }
    arr1.insert(arr1.end(),arr2.begin(),arr2.end());
    sort(arr1.begin(),arr1.end());
    vector<int> mergedCopy =merged;
    sort(mergedCopy.begin(),mergedCopy.end());
    if (arr1 != mergedCopy){
        return false;
    }
    for(int i = 1; i<merged.size(); i++){
        if(merged[i] > merged[(i-1)/2])
            return false;
    }
    return true;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        vector<int> a(n,0),b(m,0);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (i = 0; i < m; i++) {
            cin >> b[i];
        }
        vector<int> merged, copyA = a, copyB = b;
        Solution obj;
        merged = obj.mergeHeaps(a, b, n, m);
        bool flag = isMerged(copyA, copyB, merged);
        if(flag == false) cout<<0<<endl;
        else cout<<1<<endl;
    }
    return 0;
}
  // } Driver Code Ends

  /*
Time Complexity: O(n.Logn)
Auxiliary Space: O(1
  */