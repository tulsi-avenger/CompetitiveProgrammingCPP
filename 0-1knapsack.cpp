#include<bits/stdc++.h>

using namespace std;

#define rep(i,k,n) for(int i=k;i<=n;i++)
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector< pii > vpi;
typedef vector<vector<int> > vvi;

int main()
{
    int n,w;
    cout<<"enter no of items\n";
    cin>>n;
    vvi item(n,vector<int>(2));
   
    rep(i,0,n-1)
    {
        cin>>item[i][0]>>item[i][1];
    }
    cout<<"enter knapsack capacity\n";
    cin>>w;
    vvi table(n+1,vector<int>(w+1));

    rep(i,0,n)
    {
        table[i][0]=0;
        table[0][i]=0;
    }
    
    
    rep(i,1,n)
    {
        rep(j,1,w)
        {
            if(item[i-1][0]>j)
            {
                table[i][j]=table[i-1][j];
            }else
            {
                table[i][j]=max(table[i-1][j],item[i-1][1]+table[i-1][j-item[i-1][0]]);
                
            }
        }
    }
    cout<<table[n][w];
    cout<<"\n items are\n";
    rep(i,0,n)
    {
        rep(j,0,w)
    {
        cout<<table[i][j]<<" ";
    }
    cout<<endl;
    }
    int choice[n];
    int k=0;
    for(int i=n,j=w;i>0&&j>0;i--)
    {
        if(table[i][j]!=table[i-1][j])
        {
            
         choice[k++]=i-1;
        j=j-item[i-1][0];
        
            
        }
     }
     rep(i,0,k-1)
    cout<<choice[i]<<" "<<item[choice[i]][0]<<" "<<item[choice[i]][1]<<"\n";
    
}