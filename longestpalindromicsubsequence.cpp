#include<bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpi;
#define rep(i,k,n) for(int i=k;i<=n;i++)
int main()
{
    string s1;
    cin>>s1;
    int l1=s1.length();
    vvi table(l1,vi(l1));
    rep(i,0,l1-1)
    table[i][i]=1;
  
    rep(i,1,l1-1)
    {
        rep(j,0,l1-i-1)
        {
            if(s1[j]==s1[j+i])
            {
                table[j][j+i]=2+table[j+1][j+i-1];

            }else
            {
                table[j][j+i]=max(table[j+1][j+i],table[j][j+i-1]);
            }
        }
    }
    rep(i,0,l1-1)
    {
        rep(j,0,l1-1)
        {
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }
    bool *present=new bool [l1]{0};
    cout<<"answer is "<<table[0][l1-1]<<endl;
    for(int i=0,j=l1-1;i<=j;)
    {
        if(table[i][j]==table[i+1][j])
        {
            i++;
        }else if(table[i][j]==table[i][j-1])
        {
            j--;
        }else{
            present[i]=1;
            present[j]=1;
            j--;
            i++;
        }
    }
    rep(i,0,l1-1)
    {
        if(present[i])
        cout<<s1[i]<<" ";
    }
    




}