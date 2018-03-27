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
*/
bool cycleutil(bool * visited,int u,int parent)
{
        visited[u]=1;
        for(auto & c: g[u])
        {
            if((!visited[c]))
            {
                if(cycleutil(visited,c,u))
            return true;
            }
            else if(visited[c]&&(c!=parent))
            return true;
        }
    
    return false;
}

bool detectCycle()
{
    bool * visited=new bool [n]{0};
    memset(visited,0,sizeof(visited));
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        if(cycleutil(visited,i,-1))
        return true;
    }
    return false;
}
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
   cout<<detectCycle();
    
}