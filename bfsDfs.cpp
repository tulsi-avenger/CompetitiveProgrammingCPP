#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pair<int,int> > vpi;
#define rep(i,k,n) for(int i=k;i<=n;i++)
#define  mem(a,b) memset(a,(b),sizeof(a));
vi *g;
int n;
void bfs(int source)
{
    bool * visited=new bool[n]{0};
    queue<int> q;
    q.push(source);
    visited[source]=true;
    while(!q.empty())
    {
        int node=q.front();
        cout<<node<<" ";
        q.pop();
        for(auto & c: g[node])
        {
            if(!visited[c])
            {
                q.push(c);
                visited[c]=true;
            }
        }
    }
}
void dfs(bool *visited,int u)
{
    visited[u]=1;
    cout<<u<<" ";
    for(auto & c: g[u])
    {
        if(!visited[c])
        {
            dfs(visited,c);
        }
    }
}
/*

8
10
0 1
0 2
4 5
1 5
2 5
2 3
3 6
6 1
1 3
6 7
bfs (0)
0 1 2 5 6 3 4 7
dfs (0)
0 1 5 4 2 3 6 7


*/

int main()
{
    int m,u,v;
    cin>>n>>m;
    g=new vi[n];
    rep(i,0,m-1)
    {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cout<<"bfs(0)\n";
    bfs(0);
    cout<<endl;
    bool * visited=new bool[n]{0};
   // mem(visited,0);
    cout<<"dfs(0)->"<<endl;
    dfs(visited,0);
    
}