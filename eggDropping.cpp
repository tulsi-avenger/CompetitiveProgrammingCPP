#include<bits/stdc++.h>

using namespace std;
#define rep(i,k,n) for(int i=k;i<=n;i++)
//https://ide.codingblocks.com/#/s/7740 
//java solu
typedef vector<int> vi;
typedef vector<vi> vvi;
// O(noOfEgg*floor*floor)
//tries = n/b+b 
// on diferentiation n-1/b^2 double diff giv plus means minima
//on solving b=root n
// so we take root n block each time
// tries= root n+root n=2root n

int main()
{
    cout<<"enter no's of floors and egg\n";
    int n,floor;

    cin>>floor>>n;
    vvi(floor+1,vi(n+1));
    vvi table(n+1,vi(floor+1));
    rep(i,1,floor)
    {
        table[1][i]=i;
    }rep(i,1,n)
    {
        table[i][1]=1;
    }

    rep(i,2,n)
    {
        rep(j,2,floor)
        {
            if(i>j)
            table[i][j]=table[i-1][j];
            else {
            int res=INT_MAX;
            rep(k,1,j)
            {
                //int bokeneggres=(k-1>0)?table[i-1][k-1]:0;
                //int eggsurviveres=(j-k>0)?table[i][j-k]:0;
                res=min(res,1+max(table[i-1][k-1],table[i][j-k]));
               
            }
            table[i][j]=res;
            }

        }
    }

    rep(i,1,n)
    {
        rep(j,1,floor)
        {
            cout<<table[i][j]<<" ";
        }
        cout<<"\n";
    }

    cout<<"ans is "<<table[n][floor]<<endl;



}