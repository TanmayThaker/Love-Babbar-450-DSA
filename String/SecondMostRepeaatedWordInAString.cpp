//Second most repeated string in a sequence
//Practice link : https://practice.geeksforgeeks.org/problems/second-most-repeated-string-in-a-sequence0534/1#

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        //code here.
        /*
        map<string,int> m;
        for(int i=0;i<n;i++)
        {
            m[arr[i]]++;
        }
        int max1=INT_MIN;
        int max2=INT_MIN;
        
        string s1="",s2="";
        
        for(auto it:m)
        {
            if(max1<it.second)
            {
                s2=s1;
                max2=max1;
                max1=it.second;
                s1=it.first;
            }
            else if(max2<it.second)
            {
                s2=it.first;
                max2=it.second;
            }
        }
        return s2;
    }
    */
        map<string,int> m;
        for(int i=0;i<n;i++) { m[arr[i]]++;} 
        vector<int>v;
        for(auto i:m)
        {
            v.push_back(i.second);
        }
        sort(v.begin(),v.end(),greater<int>());
        int f=v[1];
        for(auto i:m)
        {
            if(i.second==f)
            {
                return i.first;
            }
        }
    }
};

/*
TC:O(N)
SC:O(N)
*/