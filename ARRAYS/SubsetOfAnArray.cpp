//Array Subset of another array
// Practice link : https://practice.geeksforgeeks.org/problems/array-subset-of-another-array2317/1#



string isSubset(int a1[], int a2[], int n, int m) {
    int count=0;
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        mp[a1[i]]++;
    }
    for(int j=0;j<m;j++)
    {
        if(mp[a2[j]])
        {
            count++;
        }
    }
    if(count!=m)
    {
        return "No";
    }
    else
    {
        return "Yes";
    }
}

/*
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)
*/