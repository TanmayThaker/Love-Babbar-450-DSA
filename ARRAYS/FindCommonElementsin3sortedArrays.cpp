
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n1, n2, n3;
    cin >> n1, n2, n3;
    int a1[n1], a2[n2], a3[n3];
    for (int i = 0; i < n1; i++)
        cin >> a1[i];
    for (int i = 0; i < n2; i++)
        cin >> a2[i];
    for (int i = 0; i < n3; i++)
        cin >> a3[i];

    unordered_map<int, int> m1, m2, m3;
    for (int i = 0; i < n1; i++)
        m1[a1[i]]++;
    for (int i = 0; i < n2; i++)
        m2[a2[i]]++;
    for (int i = 0; i < n3; i++)
        m3[a3[i]]++;

    vector<int> v;
    for (int i = 0; i < n1; i++)
    {
        if (m1[a1[i]] and m2[a2[i]] and m3[a3[i]])
        {
            v.push_back(a1[i]);
            m1[a1[i]] = 0; //This is to remove duplicate elements
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}

/*
TIme complexity : O(n1 + n2 + n3)
Space complexity : O(n1 + n2 + n3)
*/

Another Approach :

class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            //code here.
            int i=0,j=0,k=0;
            vector<int> v;
            while(i<n1 and j<n2 and k<n3)
            {
                if(A[i]==B[j] and B[j]==C[k])
                {
                    v.push_back(A[i]);
                    i++;
                    j++;
                    k++;
                }
                else if(A[i]<B[j])
                {
                    i++;
                }
                else if(B[j]<C[k])
                {
                    j++;
                }
                else
                {
                    k++;
                }
                int xx = A[i-1];
                while(xx==A[i])
                {
                    i++;
                }
                int yy=B[j-1];
                while(yy==B[j])
                {
                    j++;
                }
                int zz=C[k-1];
                while(zz==C[k])
                {
                    k++;
                }
            }
            return v;
        }

};

/*
Expected Time Complexity: O(n1 + n2 + n3)
Expected Auxiliary Space: O(1)
*/