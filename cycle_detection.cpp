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
int cycleutil(bool * visited,bool * recstack,int u)
{
    if(!visited[u])
    {
        visited[u]=1;
        recstack[u]=1;
        for(auto & c:g[u])
        {
            if(recstack[c])
            {
                return true;
            }
            else if(!visited[c] && cycleutil(visited,recstack,c))
            {
                return true;
            }
        }
    }
    recstack[u]=false;
    return false;
}
int detectCycle()
{
    bool * visited=new bool[n]{0};
    bool * recstack=new bool[n]{0};
    for(int i=0;i<n;i++)
    {
        if(cycleutil(visited,recstack,i))
        {
            return true;
        }
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

    }
   cout<<detectCycle();
    
}