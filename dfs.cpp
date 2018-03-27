#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
#define rep(i,k,n) for(int i=k;i<=n;i++)

void dfs(bool * visited,vi g[],int u,vi & array)
{
    visited[u]=true;
    for(auto &c: g[u])
    {
        if(!visited[c])
        {
            dfs(visited,g,c,array);

        }
    }
    array.push_back(u);

}

int main()
{
    int n,m,u,v,bidir;
    cin>>n>>m;
    vi * g=new vi[n];
    cout<<"if bidir type 1 else 0";
    cin>>bidir;
    rep(i,0,m-1)
    {
        cin>>u>>v;
        g[u].push_back(v);
        if(bidir)
        {
            g[v].push_back(u);
        }
    }
    vi array;
    bool * visited=new bool [n]{0};
     dfs(visited,g,0,array);

     for(int i=n-1;i>=0;i--)
     {
         cout<<array[i]<<" ";

     }
     cout<<endl;
}