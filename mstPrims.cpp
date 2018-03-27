#include<bits/stdc++.h>

using namespace std;

#define rep(i,k,n) for(int i=k;i<=n;i++)
#define INF 0x3f3f3f3f
typedef  vector<int> vi;
typedef pair<int , int> pii;
typedef vector<pii> vii;

vii *g;


int main()
{
    int n,m,u,v,w;
    cin>>n>>m;
    g=new vii[n+1];
    rep(i,0,m-1)
    {
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    int source ;
    cin>>source;

   int parent[n],key[n];bool inmst[n];
   rep(i,0,n-1)
   {
       parent[i]=-1;
        inmst[i]=0;
        key[i]=INF;
    }
    priority_queue<pii,vii,greater<pii > > pq;
    key[source]=0;
    pq.push({0,source});//push (0,source)
   
    
    while(!pq.empty())
    {
        int u=pq.top().second;
        inmst[u]=true;
        pq.pop();
        for(auto &c: g[u])
        {
            int v=c.first;
            int w=c.second;
            if((!inmst[v])&&w<key[v])
            {
                parent[v]=u;
                key[v]=w;
                pq.push({w,v});
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(i==source)
        {
            continue;
        }
        else 
        {
            cout<<parent[i]<<" "<<i<<" "<<key[i]<<endl;
        }
    }


}