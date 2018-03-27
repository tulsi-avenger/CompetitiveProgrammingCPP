#include<bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

#define rep(i,k,n) for(int i=k;i<=n;i++)
int root(int i,vi array)
{
        int temp=i;
       while(array[temp]!=temp)
       {
           temp=array[temp];
       }
       //path compressor
       while(array[i]!=i)
       {
           int t=array[i];
           array[i]=temp;
           i=t;
       }
    return i;
}
void initialize(vi& array,vi& size,int n)
{
    rep(i,0,n-1)
    {
        size[i]=1;
        array[i]=i;
    }
}
void weightedunion1(int a,int b,vi& array,vi& size)
{
    

    int root_A=root(a,array);
    int root_B=root(b,array);
   if(size[root_A]<size[root_B])
   {
       array[root_A]=array[root_B];
       size[root_B]+=size[root_A];
   }else{
        array[root_B]=array[root_A];
       size[root_A]+=size[root_B];
   }
}


bool find(int a,int b,vi array)
{
    if(root(a,array)==root(b,array))
    return true;
    else return false;
}
int main(){
    int n,ele;
    cin>>n;
    vi array(n),size(n);
    map<int,int> mm;
    rep(i,0,n-1)
    {
        cin>>ele;
        mm[ele]=i;
    }
    initialize(array,size,n);

    int m,choice,a,b;
    
    cout<<"enter no of operation\n";
    cin>>m;
    cout<< "for union\n2 for find\n followed by two value\n";
    rep(i,0,m-1)
    {
        cin>>choice;
        if(choice==1)
        {
           // cout<<"enter value for union\n";
            cin>>a>>b;
            weightedunion1(max(mm[a],mm[b]),min(mm[a],mm[b]),array,size);
        }else
        {
            //cout<<"enter keys for finding that they are in same set\n";
            cin>>a>>b;
            cout<<find(mm[a],mm[b],array)<<"\n";
        }
    }






}