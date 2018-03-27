#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef  vector<vector<int>> vvi;
#define rep(i,k,n) for(int i=k;i<=n;i++)
#define INF 0x3f3f3f3f

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int l1=s1.length(),l2=s2.length();

    vvi table(l2+1,vi(l2+1));
    rep(i,0,l1)
    table[i][0]=0;
    rep(i,0,l2)
    table[0][i]=0;
    rep(i,1,l1)
    {
        rep(j,1,l2)
        {
            if(s1[i-1]==s2[j-1])
            {
                table[i][j]=1+table[i-1][j-1];
            }else
            {
                table[i][j]=max(table[i-1][j],table[i][j-1]);

            }
        }
    }
    rep(i,0,l1)
    {
        rep(j,0,l2)
        {
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }
    int k=0;
    char commonchar[min(l1,l2)];
    for(int i=l1,j=l2;i>0&&j>0;)
    {
        if(table[i][j]==table[i-1][j])
        {
            i--;
        }else if(table[i][j]==table[i][j-1])
        {
            j--;
        }
        else{
            commonchar[k++]=s1[i-1];
            i--;
            j--;
        }
    }
    for(int j=k-1;j>=0;j--)
    {
        cout<<commonchar[j]<<",";
    }
    


}