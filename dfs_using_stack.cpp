#include<bits/stdc++.h>

using namespace std;

#define rep(i,k,n) for(int i=k;i<=n;i++)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int n,m;
void dfs_stack(vi g[],int s)
{
    bool  * visited=new bool[n];
    visited[s]=1;
    stack<int>  ss;
    ss.push(s);
    while(!ss.empty())
    {
        int node=ss.top();
        cout<<node<<" ";
        ss.pop();
        for( auto & c: g[node])
        {
            if(!visited[c])
            {
                visited[c]=1;
                ss.push(c);
            }
        }
    }
}
/*



8
11
0 1
0 2
2 3
6 2
6 7
5 6
4 7
4 5
1 4
1 5
3 6
dfs is -:
0 2 3 6 7 1 5 4
*/
int main()
{
    int u,v;
    cin>>n>>m;
    vi g[n];
    rep(i,0,m-1)
    {
        cin>>u>>v;
        g[u].push_back(v);
    }
    dfs_stack(g,0);
}