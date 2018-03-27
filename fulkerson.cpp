#include<bits/stdc++.h>

using namespace std;

#define rep(i,k,n) for(int i=k;i<=n;i++)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpi;

int n,m;

bool bfs(int s,int t,vvi & gg,vi & parent)
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
      rep(c,0,n-1)
        {
            

            if((!visited[c])&& (gg[node][c])>0)
            {
                visited[c]=1;
                q.push(c);
                parent[c]=node;
            }
        }
    
    }
        return (visited[t]==true);
}
int  FordFulkerson(int s,int t,vvi & g)
{
   
    vi parent(n);
    vvi gg(n,vi(n));
    rep(i,0,n-1)
    {
        rep(j,0,n-1)
        {
            gg[i][j]=g[i][j];
        }
    }
    int max_flow=0;
   while(bfs(s,t,gg,parent))
   {
        int flow=188888998;
        for(int v=t;v!=s;v=parent[v])
        {
            int u=parent[v];
            flow=min(flow,gg[u][v]);
        }
        for(int v=t;v!=s;v=parent[v])
        {
            int u=parent[v];
            gg[u][v]-=flow;
            gg[v][u]+=flow;
        }
        max_flow+=flow;
    }
    return max_flow;
}
/*
4 4
0 1 1
1 2 2
2 3 1
0 3 5
0 3
 ans->6

*/
int main()
{
    int u,v,w;
    cin>>n>>m;
    vvi g(n,vi(n));
    rep(i,0,m-1)
    {
        
        cin>>u>>v>>w;
        g[u][v]=w;
    }
    int s,t;
    cin>>s>>t;
 
  int p=FordFulkerson(s,t,g);
  cout<<p;
    
}