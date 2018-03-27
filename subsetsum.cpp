#include<iostream>

using namespace std;
#define rep(i,k,n) for(int i=k;i<=n;i++)
int main()
{
    int n;
    cout<<"enter no of element in set\n";
    cin>>n;
    cout<<"date input\n";
    int set[n];
    rep(i,0,n-1)
    cin>>set[i];
    int sum=0;
    cout<<"input sum \n";
    cin>>sum;
    char table[n+1][sum+1];
    rep(i,0,sum)
    table[0][i]='F';
    rep(i,0,n)
    table[i][0]='T';
    rep(i,1,n)
    {
        rep(j,1,sum)
        {
            if(table[i-1][j]=='T')
            table[i][j]='T';
            else if(set[i-1]<=j)
            {
                table[i][j]=table[i-1][j-set[i-1]];
            }
            else table[i][j]='F';

        }
    }
    rep(i,0,n)
    {
        rep(j,0,sum)
        {
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }
    if(table[n][sum]=='T')
    {
        cout<<"yes! it is possible in following way!\n";
        for(int i=n,j=sum;j>=1&&i>=1;)
        {
            if(table[i-1][j]=='T')
            {
                i--;
            }
            else 
            {
                //cout<<i<<" "<<j<<endl;
                cout<<set[i-1]<<"\n";
                  j=j-set[i-1];
                i--;
              
            }
        }
    }
    
}