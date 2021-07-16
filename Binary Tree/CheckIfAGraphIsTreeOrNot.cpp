//Code to check whether the graph is a tree or not

#include<bits/stdc++.h>
using namespace std;
#define MAX 101
vector<int> g[MAX];
int vis[MAX]={0};

bool isCycle(int u,int parent)
{
    vis[u]=1;
    for(auto x:g[u])
    {
        if(!vis[x])
        {
            if(isCycle(x,u)) return true;
        }
        else if(x!=parent) return true;
    }
    return false;
}
void connectedComponents(int u)
{
    vis[u]=1;
    for(auto it:g[u])
    {
        if(!vis[it]) connectedComponents(it);
    }
}
bool utility(int m)
{
    //Here we are passing 0 as root node and since root has no parent 
    //so we are passsing parent as -1 
    bool y = isCycle(0,-1);
    if(y) return false;
    //Mark all nodes as unvisited
    memset(vis,0,sizeof(vis));

    connectedComponents(0);
    for(int i=0;i<m;i++)
    {
        if(!vis[i]) return false;
    }
    return true;
}
int main()
{
    int n,m;
    cin>>n>>m;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bool x = utility(m);
    if(x) cout<<"Graph is a tree";
    else cout<<"Graph is not a tree";
    return 0;
}