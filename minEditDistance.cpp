#include<iostream>

using namespace std;

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int l1=s1.length(),l2=s2.length();

    int table[l1+1][l2+1];
    for(int i=0;i<=l1;i++)
    {
        table[i][0]=i;
    }
    for(int i=0;i<=l2;i++)
    {
        table[0][i]=i;
    }

    for(int i=1;i<=l1;i++)
    {
        for(int j=1;j<=l2;j++)
        {
            if(s1[i-1]==s2[j-1])
            table[i][j]=table[i-1][j-1];
            else
            {
                table[i][j]=1+min(table[i-1][j-1],min(table[i-1][j],table[i][j-1]));
            }
        }
    }
    for(int i=0;i<=l1;i++)
    {
        for(int j=0;j<=l2;j++)
        cout<<table[i][j]<<" ";
        cout<<endl;
    }
    for(int i=l1,j=l2;i>=0&&j>=0;)
    {  
        if(s1[i-1]==s2[j-1])
           {
                i--;j--;
            }
        else
        {
            int val=table[i][j]-1;
            if(i>=1&&val==table[i-1][j])
            {
                cout<<"delete s1["<<i-1<<"] "<<s1[i-1]<<endl;
                i--;
            }
            else if(j>=1&&val==table[i][j-1])
            {
                cout<<"delete s2["<<j-1<<"] "<<s2[j-1]<<endl;
                j--;
            }
            else{
                cout<<"change s1["<<i-1<<"] to s2["<<j-1<<"] "<<s1[i-1]<<" to "<<s2[j-1]<<endl;
                i--;
                j--;
            }
        }
      
    }



}