#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pair< int ,int> > vpi;
typedef vector<vector<int ,int> > vvi;
#define rep(i,k,n) for(int i=k;i<=n;i++)
void dfs(bool * visited,vi  g[],vi & array,int u)
{
    visited[u]=true;
    for( auto & c:g[u])
    {
        if(!visited[c])
        {
            dfs(visited,g,array,c);
        }
        
    }
   // cout<<u<<"\n";
    array.push_back(u);
}
void topological(bool * visited,vi  g[], vi & array,int n)
{
        bool *visited=new bool[n]{0};
    rep(i,0,n-1)
    {
        if(!visited[i])
        {
            dfs(visited,g,array,i);

        }
    }
}

int main()
{
    int n,m,u,v;
    cin>>n>>m;
    vi *g=new vi[m];
    vi array;

    
    rep(i,0,m-1)
    {
        cin>>u>>v;
        g[u].push_back(v);
        
    }
    
    topological(g,array,n);
    cout<<"linear ordering is->\n";
    for(int i=n-1;i>=0;i--)
    cout<<array[i]<<" ";
    cout<<endl;

    /*
10 13
0 5
0 1
6 0
6 1
1 7
6 2
3 2
3 7
3 8
8 2
3 4
4 8
9 4

ans 9 6 3 4 8 2 0 1 7 5 
*/

    


}