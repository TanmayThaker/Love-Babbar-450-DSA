//Practice link : https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1
//Video Link : https://www.youtube.com/watch?v=LCMX9lzIHx0

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n=grid.size();
	    int m=grid[0].size();
	    vector<vector<int>> ans(n,vector<int>(m,INT_MAX-1));
	    queue<pair<int,int>> q;
	    
	    for(int i=0;i<grid.size();i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(grid[i][j]==1)
	            {
	                q.push({i,j});
	                ans[i][j]=0;
	            }
	        }
	    }
	    
	    while(!q.empty())
	    {
	        int x=q.front().first;
	        int y=q.front().second;
	        q.pop();
	        int dx[4]={-1,1,0,0};
	        int dy[4]={0,0,1,-1};
	        
	        for(int j=0;j<4;j++)
	        {
	            int nx=x+dx[j];
	            int ny=y+dy[j];
	            
	            if(nx>=0 and ny>=0 and nx<n and ny<m)
	            {
	                if(ans[nx][ny]>ans[x][y]+1)
	                {
	                    ans[nx][ny]=1+ans[x][y];
	                    q.push({nx,ny});
	                }
	            }
	        }
	    }
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends


//--------------------------------------------------------------------------------------------------------------------------------------------------
//Approach 2

vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n=grid.size();
	    int m=grid[0].size();
	    vector<vector<int>> ans(n,vector<int>(m,INT_MAX-1));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    ans[i][j]=0;
                }
            }
        }


        //This is top left to bottom right
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]!=1)
                {
                    if(j-1>=0)
                    {
                        ans[i][j]=min(ans[i][j],ans[i][j-1]+1);
                    }
                    if(i-1>=0)
                    {
                        ans[i][j]=min(ans[i][j],ans[i-1][j]+1);
                    }
                    if(j+1<m)
                    {
                        ans[i][j]=min(ans[i][j],ans[i][j+1]+1);
                    }
                    if(i+1<n)
                    {
                        ans[i][j]=min(ans[i][j],ans[i+1][j]+1);
                    }
                }
            }
        }

        //this is for bottom right t0 top left because when we are coming from
        //top left to bottom right then there might be a possibility that they may not be visited
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(grid[i][j]!=1)
                {
                    if(j-1>=0)
                    {
                        ans[i][j]=min(ans[i][j],ans[i][j-1]+1);
                    }
                    if(i-1>=0)
                    {
                        ans[i][j]=min(ans[i][j],ans[i-1][j]+1);
                    }
                    if(j+1<m)
                    {
                        ans[i][j]=min(ans[i][j],ans[i][j+1]+1);
                    }
                    if(i+1<n)
                    {
                        ans[i][j]=min(ans[i][j],ans[i+1][j]+1);
                    }
                }
            }
        }
        return ans;
    }