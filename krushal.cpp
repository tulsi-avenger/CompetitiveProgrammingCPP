#include<bits/stdc++.h>

using namespace std;

#define rep(i,k,n) for(int i=k;i<=n;i++)
#define inf 0x3f3f3f3f
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vii;
const int MAX = 1e4 + 5;
int *id=new int [MAX],n,m,k=0;
int root(int i)
{
    
    if(id[i]!=i)
    {
        id[i]=id[id[i]];
        i=id[i];
    }
    return i;
}
void union1(int x,int y)
{
    int p=root(x);
    int q=root(y);
    id[p]=id[q];
}
void initilize()
{
    
    rep(i,0,MAX-1)
    id[i]=i;
}
int kruskal(pair<int,pair<int,int> >  mm[],pair<int,pair<int,int> >  mst[])
{
    int x,y,cost,minimumcost=0;
    for(int i=0;i<m;i++)
    {
        x=mm[i].second.first;
        y=mm[i].second.second;
        cost=mm[i].first;

        if(root(x)!=root(y))
        {
            minimumcost+=cost;
            mst[k++]=make_pair(cost,make_pair(x,y));
            union1(x,y);
         }
        
    }
     return minimumcost;
}
int main()
{
   int u,v,w;
   cin>>n>>m;
   //vector< pair<int ,pair<int,int> >mm(m);
   pair<int,pair<int,int > > mm[m],mst[m];

   initilize();
   rep(i,0,m-1)
   {
       cin>>u>>v>>w;
       mm[i]=make_pair(w,make_pair(u,v));

   }
   
   sort(mm,mm+m);

   int minimumcost=kruskal(mm,mst);
   cout<<minimumcost<<endl;
   rep(i,0,k-1)
   cout<<mst[i].first<<" "<<mst[i].second.first<<" "<<mst[i].second.second<<endl;

    
}
/*



6
7
1 2 1
2 4 3
1 3 2
2 3 1
4 5 4
3 6 2
5 6 3
*/