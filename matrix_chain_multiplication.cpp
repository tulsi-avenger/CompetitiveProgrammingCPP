#include<bits/stdc++.h>
//https://ide.codingblocks.com/#/s/7538
using namespace std;
#define rep(i,k,n) for(int i=k;i<=n;i++)

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<vector<int> > vvi;
#define inf 0x3f3f3f3f
void printorder( vvi& pivot,int i,int j)
{
   if(i==j)
   printf("A%d",i);
   else{
       cout<<"(";
       printorder(pivot,i,pivot[i][j]);
       printorder(pivot,pivot[i][j]+1,j);
       cout<<")";
   }
   

}
int main()
{
    int n;
    cin>>n;
    vvi mat(n+1,vi(2));
    rep(i,1,n)
    {
        cin>>mat[i][0]>>mat[i][1];
    }
    vvi table(n+1,vi(n+1));
    vvi pivot(n+1,vi(n+1));
    rep(i,1,n)
    table[i][i]=0;
    

    rep(i,1,n-1)
    {
        rep(j,1,n-i)
        {
            int left=j;
            int right=j+i;
             table[left][right]=inf;
            rep(k,left,right-1)
            {
                int mm=table[left][k]+table[k+1][right]+mat[left][0]*mat[k][1]*mat[right][1];
                if(table[left][right]>mm)
                {
                table[left][right]=min(table[left][right],mm);
                    pivot[left][right]=k;
                }

            }
           
        }
    }
    rep(i,1,n)
    {
        rep(j,1,n)
        {
            //cout<<table[i][j]<<" ";
            printf("%4d",table[i][j]);
        }
        cout<<endl;
    }
    printorder(pivot,1,n);
    cout<<endl;
    
  


}