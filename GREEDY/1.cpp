//Find Duplicate characters in a string

#include<stdio.h>
using namespace std;
#include<bits/stdc++.h.>

int main(){
    string s="Tanmay loves to code";
    map<char,int> m;

    for(int i=0;i<s.length();i++){
        m[s[i]]++;
    }

    for(auto it:m){
        if(it.second>1){
            cout<<it.first<<" "<<"count= "<<it.second<<endl;
        }
    }
    return 0;
}