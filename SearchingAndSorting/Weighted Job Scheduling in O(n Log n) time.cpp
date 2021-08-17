//Weighted Job Scheduling in O(n Log n) time
//Problem link : https://leetcode.com/problems/maximum-profit-in-job-scheduling/
//Video Solution : https://www.youtube.com/watch?v=V59YYFPN5KA&t=25s

//LEETCODE ACCEPTED SOLUTION : 

class Solution {
public:
    static bool compare(vector<int> v1,vector<int> v2)
    {
        return v1[1]<v2[1];
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> v;
        for(int i=0;i<startTime.size();i++)
        {
            int x,y,z;
            x=startTime[i];
            y=endTime[i];
            z=profit[i];
            v.push_back({x,y,z});
        }
        
        sort(v.begin(),v.end(),compare);
        int dp[v.size()];
        dp[0]=v[0][2];
        
        
        for(int i=1;i<v.size();i++)
        {
            int inc=v[i][2];
            int last=-1;
            int low=0;
            int hi=i-1;
            
            while(low<=hi)
            {
                int mid=(low+hi)/2;
                if(v[mid][1]<=v[i][0])
                {
                    last=mid;
                    low=mid+1;
                }
                else hi=mid-1;
            }
            if(last!=-1) inc+=dp[last];
            int exc=dp[i-1];
            dp[i]=max(inc,exc);
        }
        return dp[v.size()-1];
    }
};

//-----------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int start, finish, profit;
};

bool compare(Job s1, Job s2)
{
    return s1.finish < s2.finish;
}

int binarySearch(Job jobs[], int index)
{
    int lo = 0, hi = index - 1;
    while (low <= hi)
    {
        int mid = (lo + hi) / 2;
        if (jobs[mid].finish <= jobs[mid].start)
        {
            if (jobs[mid + 1].finish <= jobs[index].start) //No overlapping interval
            {
                lo = mid + 1;
            }
            else
            {
                return mid;
            }
        }
        else
        {
            hi = mid - 1;
        }
    }
    return -1;
}

int findMaxProfit(Job arr[], int n)
{
    sort(arr, arr + n, compare);
    //creating an array to store the answers of all the subproblems at runtime
    int *table = new int[n];
    table[0] = arr[0].profit; //base case (So that we can compare it with the next Job that which one gives us maximum profit)

    for (int i = 1; i < n; i++)
    {
        // Find profit including the current job (basically including that job)
        int incProfit = arr[i].profit;
        int l = binarySearch(arr, i);
        if (l != -1)
        {
            incProfit += table[l];
        }
        //Store maximum profit of including and excluding
        table[i] = max(incProfit, table[i - 1]); //table[i-1] is we are excluding that job
    }
    // Store result and free dynamic memory allocated for table[]
    int result = table[n - 1];
    return result;
}

int main()
{
    Job arr[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Optimal profit is " << findMaxProfit(arr, n);
    return 0;
}
