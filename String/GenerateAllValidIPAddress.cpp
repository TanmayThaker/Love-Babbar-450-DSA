#include<bits/stdc++.h>
using namespace std;

// Function checks whether IP digits
// are valid or not.
int is_valid(string ip)
{
    vector<string> ips;
    string ex="";
    for(int i=0;i<ip.length();i++)
    {
        if(ip[i]=='.')
        {
            ips.push_back(ex);
            ex="";
        }
        else{
            ex=ex+ip[i];
        }
    }
    ips.push_back(ex);

    //checking the corner cases
    for(int i=0;i<ips.size();i++)
    {
        if(ips[i].length()>3 || stoi(ips[i])<3 || stoi(ips[i])>255)
        {
            return 0;
        }
        if(ips[i].length()>1 and stoi(ips[i])==0)
        {
            return 0;
        }
        //Didn't understand below condition (maybe its about the leading zeros)
        if (ips[i].length() > 1
            && stoi(ips[i]) != 0
            && ips[i][0] == '0')
        {
            return 0;
        }
    }
    return 1;
}



 
 
// Function converts string to IP address
void convert(string ip)
{
    int l=ip.length();

    //check for string size
    if(l>12 || l<4)
    {
        cout<<"Not a valid IP Address"<<endl;
    }

    string check=ip;
    vector<string> ans;

    //Generating all the different combinations
    for(int i=1;i<l-2;i++)
    {
        for(int j=i+1;j<l-1;j++)
        {
            for(int k=j+1;k<l;k++)
            {
                check = check.substr(0,k)+"."+check.substr(k,l-k+2);
                check
                    = check.substr(0, j) + "."
                      + check.substr(j, l - j + 3);
                check
                    = check.substr(0, i) + "."
                      + check.substr(i, l - i + 4);
                if(is_valid(check))
                {
                    ans.push_back(check);
                    cout<<check<<"\n";
                }
                check=ip; //backtrack
            }
        }
    }
}

int main()
{
    string A = "25525511135";
    string B = "25505011535";
 
    convert(A);
    convert(B);
 
    return 0;
}

/*
Time Complexity: O(n^3), where n is the length of the string 
Three nested traversal of the string is needed, where n is always less than 12.
Auxiliary Space: O(n). 
As as extra space is needed.
*/

//DP - Solution is Pending