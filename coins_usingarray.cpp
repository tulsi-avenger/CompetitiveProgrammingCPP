#include<bits/stdc++.h>

using namespace std;
#define rep(i,k,n) for(int i=k;i<=n;i++)
typedef vector<int> vi;
typedef vector<vi> vvi;
int main()
{
    int n,amt;
    cout<<"enter no of coins available\n";
    cin>>n;
    cout<<"enter values\n";
    vi coin(n);
    rep(i,0,n-1)
    cin>>coin[i];
    cin>>amt;
    vi countCoin(amt+1,INT_MAX);
    countCoin[0]=0;
    vi index(amt+1,-1);
    rep(i,0,n-1)
    {
        rep(j,1,amt)
        {
            if(j>=coin[i]&&(countCoin[j-coin[i]]!=INT_MAX))
            {
                    if(countCoin[j]>1+countCoin[j-coin[i]])
                    {
                       countCoin[j]= 1+countCoin[j-coin[i]];
                       index[j]=i;
                    }

                
            }
        }
    }
    rep(i,0,amt)
    cout<<countCoin[i]<<" ";
    cout<<endl;
    cout<<"ans is "<<countCoin[amt]<<endl;
    int i=amt;
    while(countCoin[i]!=0)
    {
        cout<<coin[index[i]]<<",";
        i=i-coin[index[i]];
    }
    cout<<endl;
}