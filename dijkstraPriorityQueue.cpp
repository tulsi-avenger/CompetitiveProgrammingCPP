#include<bits/stdc++.h>

using namespace std;

#define  rep(i,k,n) for(int i=k;i<=n;i++)
typedef  vector<int> vi;
typedef  pair<int,int> pii;
typedef  vector<pii> vii;
#define  INF 0x3f3f3f3f
vii *g;
vi dist;


/*======================*/
//time complexity O(ElogV)

void dijkstra(int source,int n)
{
    priority_queue<pii,vii,greater<pii>>q;
    dist.assign(n,INF);
    dist[source]=0;
    q.push({0,source});
    while(!q.empty())
    {
        int u=q.top().second;
        q.pop();
        for(auto &c : g[u])
        {
            int v=c.first;
            int w=c.second;
            if(dist[v]>dist[u]+w)
            {
                 dist[v]=dist[u]+w;
                 q.push({dist[v],v});
            }
        }
    }
}

/*==========================*/

int main()
{
    int n,m,u,v,w;
    cin>>n>>m;

    g=new vii[n];
    rep(i,0,m-1)
    {
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    int source;
    cin>>source;
    dijkstra(source,n);
    rep(i,0,n-1)
    cout<<dist[i]<<" ";
    cout<<endl;

}