//Find a specific pair in Matrix
//Link : https://www.geeksforgeeks.org/find-a-specific-pair-in-matrix/

//Brute Force Approach
#include <bits/stdc++.h>
using namespace std;
#define N 5

int findMaxValue(int mat[][N]){
    int maxValue = INT_MIN;
    for(int a=0;a<N-1;a++)
    {
        for(int b=0;b<N-1;b++)
        {
            for(int d = a+1;d<N;d++)
            {
                for (int e = b + 1; e < N; e++){
                    if(maxValue<mat[d][e]-mat[a][b])
                    {
                        maxValue=mat[d][e]-mat[a][b];
                    }
                }
            }
        }
    }
    return maxValue;
}

int main()
{
int mat[N][N] = {
                { 1, 2, -1, -4, -20 },
                { -8, -3, 4, 2, 1 },
                { 3, 8, 6, 1, 3 },
                { -4, -1, 1, 7, -6 },
                { 0, -4, 10, -5, 1 }
            };
    cout << "Maximum Value is "
        << findMaxValue(mat);
 
    return 0;
}

/*
TC : O(n^4)
SC : O(1)
*/

//Optimised Solution
#include <bits/stdc++.h>
using namespace std;
#define N 5

int findMaxValue(int mat[][N])
{
    int maxValue = INT_MIN;

    //maxArr[i][j] stores the max of elements in matrix
    //from (i,j) to (N-1,N-1)
    int maxArr[N][N];

    // last element of maxArr will be same's as of
    // the input matrix
    maxArr[N-1][N-1]=mat[N-1][N-1];

    //preprocess the last row
    int maxv = mat[N-1][N-1]; //Initialize the max

    for(int j=N-2;j>=0;j--)
    {
        if(mat[N-1][j]>maxv)
        {
            maxv = mat[N-1][j];
        }
        maxArr[N-1][j]=maxv;
    }

    //Preprocess the last column
     maxv = mat[N - 1][N - 1];  // Initialize max
    for (int i = N - 2; i >= 0; i--)
    {
        if (mat[i][N - 1] > maxv)
            maxv = mat[i][N - 1];
        maxArr[i][N - 1] = maxv;
    }

    // preprocess rest of the matrix from bottom
    
}

int main()
{
    int mat[N][N] = {
                      { 1, 2, -1, -4, -20 },
                      { -8, -3, 4, 2, 1 },
                      { 3, 8, 6, 1, 3 },
                      { -4, -1, 1, 7, -6 },
                      { 0, -4, 10, -5, 1 }
                    };
    cout << "Maximum Value is "
         << findMaxValue(mat);
 
    return 0;
}