
//RABIN KARP ALGORITHM for String Pattern matching
#include<bits/stdc++.h>
#include<stdio.h>
#include<iostream>
using namespace std;

#define ll long long int
#define prime 119

ll createHashValue(string str,int n){
    ll result=0;
    for(int i=0;i<n;i++){
        result+=(ll)(str[i]*(ll)pow(prime,i));
    }
    return result;
}


ll recalculateHash(string str,int oldIndex,int newIndex, ll oldHash,int patLength){
    ll newHash=oldHash-str[oldIndex];
    newHash=newHash/prime;
    newHash+=(ll)(str[newIndex]*(ll)(pow(prime,patLength-1)));
    return newHash;
}

bool checkEqual(string str1,string str2,int start1,int end1,int start2,int end2)
{
    if(end1-start1!=end2-start2){
        return false;
    }
    else{
        while(start1<=end1 && start2<=end2){
            if(str1[start1]!=str2[start2]){
                return false;
            }
            start1++;
            start2++;
        }
    }
    return true;
}



int main(){
    string str="ababcabdab";
    string pat="abd";
    ll patHash = createHashValue(pat,pat.length());
    ll strHash=createHashValue(str,str.length());
    for(int i=0;i<=str.length()-pat.length();i++){
        if(patHash==strHash and checkEqual(str,pat,i,i+pat.length()-1,0,pat.length()-1)){
            cout<<i<<endl;
            return 0;
        }
        if(i<str.length()-pat.length()){
            strHash = recalculateHash(str,i,i+pat.length(),strHash,pat.length()-1);
        }
    }
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
using std::vector;

// Rabin Karp algorithm
#define ll long long
#define prime 119 // code also works for 2

ll createHash(string str, int n) // O(m)
{
    ll value = 0;

    for (int i = 0; i < n; i++)
    {
        value += str[i] * (ll)pow(prime, i);
    }

    return value;
}

ll reHash(string str, int oldIndex, int newIndex, ll oldValue, int patLength)
{
    ll newVal = 0; // new hash value
    newVal += oldValue - str[oldIndex];
    newVal /= prime;
    newVal += str[newIndex] * (ll)pow(prime, patLength - 1);

    return newVal;
}

bool check_If_equal(string s1, string s2, int start1, int end1, int start2, int end2)
{
    if (end1 - start1 != end2 - start2) // if string lengths are not equal, then return false without comparison
    {
        return false;
    }

    while (start1 <= end1 && start2 <= end2)
    {
        if (s1[start1] != s2[start2])
        {
            return false;
        }
        start1++;
        start2++;
    }

    return true;
}

int strStr(const string A, const string B)
{
    int n = A.size();
    int m = B.size();
    if (n == 0 || m == 0)
    {
        return -1;
    }
    ll hashStr = createHash(A, m);
    ll hashPat = createHash(B, m);
    for (int i = 0; i <= n - m; i++)
    {
        if (hashStr == hashPat && check_If_equal(A, B, i, i + m - 1, 0, m - 1))
        {
            return i;
        }
        if (i < n - m)
        {
            hashStr = reHash(A, i, i + m, hashStr, m);
        }
    }

    return -1;
}

int main()
{
    string A = "ababababadb"; // main string
    string B = "adb";                                           // pattern
    cout << strStr(A, B);
}
*/c;