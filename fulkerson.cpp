#include<bits/stdc++.h>

using namespace std;
int n,m;
#define rep(i,k,n) for(int i=k;i<=n;i++)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpi;
bool bfs(int s,int t,vpi gg[],vi & parent)
{
    parent[s]=-1;
    queue<int>  q;
    q.push(s);
    bool * visited=new bool[n];
    visited[s]=1;
    while(!q.empty())
    {
        int  node= q.front();
        q.pop();
        for(auto &c: gg[node])
        {
            int v=c.first;

            if((!visited[v])&& c.second>0)
            {
                visited[v]=1;
                q.push(v);
                parent[v]=node;
            }
        }
    
    }
        return (visited[t]==true);
}
int  FordFulkerson(int s,int t,vpi g[])
{
    vi parent(n);
    vpi gg[n];
    rep(i,0,n-1)
    {
        for( auto & c: g[i])
        {
            gg[i].push_back(c);
        }
    }
    int max_flow=0;
    while(bfs(s,t,gg,parent))
    {
        int flow=INT_MAX;
        for(int v=t;v!=s;v=parent[v])
        {
            int u=parent[v];
            flow=min(flow,gg[u][v].second);
        }
        for(int v=t;v!=s;v=parent[v])
        {
            int u=parent[v];
            gg[u][v].second-=flow;
            gg[v][u].second+=flow;
        }
        max_flow+=flow;
    }
    return max_flow;
}
int main()
{
    int u,v,w;
    cin>>n>>m;
    vpi g[n];
    rep(i,0,m-1)
    {
        cin>>u>>v>>w;
        g[u].push_back({v,w});
    }
    int s,t;
    cin>>s>>t;
    cout<<FordFulkerson(s,t,g);
    
}