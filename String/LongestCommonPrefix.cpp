//Practice link : https://practice.geeksforgeeks.org/problems/longest-common-prefix-in-an-array5129/1


#include<bits/stdc++.h>
using namespace std;

// A Utility Function to find the common prefix between
// strings- str1 and str2

string commonPrefixUtil(string str1, string str2)
{
    string result="";
    int n1=str1.length();
    int n2 = str2.length();
    for(int i=0,j=0;i<n1 and j<n2 ; i++,j++)
    {
        if(str1[i]!=str2[j])
        {
            break;
        }
        result.push_back(str1[i]);
    }
    return result;
}

string commonPrefix(string arr[],int n)
{
    string prefix = arr[0];
    for(int i=1;i<n;i++)
    {
        prefix = commonPrefixUtil(prefix,arr[i]);
    }
    return prefix;
}

int main()
{
    string arr[] = {"geeksforgeeks", "geeks",
                    "geek", "geezer"};
    int n = sizeof(arr) / sizeof(arr[0]);
 
    string ans = commonPrefix(arr, n);
 
    if (ans.length())
        printf ("The longest common prefix is - %s",
                 ans.c_str());
    else
        printf("There is no common prefix");
 
    return (0);
}

//Practice Solution

// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    string commonPrefixUtil(string str1,string str2)
    {
        int n1=str1.length(), n2=str2.length();
        string result;
        for(int i=0,j=0;i<=n1-1 and j<=n2-1;i++,j++)
        {
            if(str1[i]!=str2[j])
            {
                break;
            }
            result.push_back(str1[i]);
        }
        if(result.length()==0) result+="-1";
        return result;
    }
    string longestCommonPrefix (string arr[], int N)
    {
        // your code here
        if(N==0) return "-1";
        string prefix;
        prefix = arr[0];
        for(int i=1;i<=N-1;i++)
        {
            prefix = commonPrefixUtil(prefix,arr[i]);
        }
        return prefix;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}


  // } Driver Code Ends