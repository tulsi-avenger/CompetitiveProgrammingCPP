#include<bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

#define rep(i,k,n) for(int i=k;i<=n;i++)

void union1(int a,int b,vi& array,int n)
{
    int temp=array[a];

    rep(i,0,n-1)
    {
        if(array[i]==temp)
        {
            array[i]=array[b];
        }
    }
}


bool find(int a,int b,vi array)
{
    if(array[a]==array[b])
    return true;
    else return false;
}
int main(){
    int n,ele;
    cin>>n;
    vi array(n);
    map<int,int> mm;
    rep(i,0,n-1)
    {
        cin>>ele;
        array[i]=i;
        mm[ele]=i;
    }

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
            union1(max(mm[a],mm[b]),min(mm[a],mm[b]),array,n);
        }else
        {
            //cout<<"enter keys for finding that they are in same set\n";
            cin>>a>>b;
            cout<<find(mm[a],mm[b],array)<<"\n";
        }
    }






}