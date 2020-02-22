#include<bits/stdc++.h>
using namespace std;
int n,dem[6][1000],tt[1000];
char c[6][1000];
void ReadInPut()
{
    cin>>n;
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>c[i][j];
            if(c[i][j]=='X')dem[1][j]++;
            if(c[i][j]=='.')dem[2][j]++;
            if(c[i][j]=='?')dem[3][j]++;
        }
    }
}
void tim(int i)
{
    int a=0,b=0,c=0;
    if(i>2)
    {
        if(tt[i-1]!=0&&tt[i-2]!=0&&tt[i-1]==tt[i-2])a=3-tt[i-2];
    }
    if(i>1&&i<n)
    {
        if(tt[i-1]!=0&&tt[i+1]!=0&&tt[i-1]==tt[i+1])b=3-tt[i-1];
    }
    if(i<n-1)
    {
        if(tt[i+1]!=0&&tt[i+2]!=0&&tt[i+1]==tt[i+2])c=3-tt[i+1];
    }
    if(a==0&&b==0&&c==0)
    {
        if(i<n-1&&tt[i+1]!=0&&tt[i+2]!=0){cout<<"UNDETERMINABLE";exit(0);}
        if(i>=n-1){cout<<"UNDETERMINABLE";exit(0);}
        if(tt[i+1]==0)tim(i+1);
        else if(tt[i+2]==0)tim(i+2);
        if(tt[i+1]!=0&&tt[i+2]!=0&&tt[i+2]==tt[i+1])tt[i]=3-tt[i+1];
        else {cout<<"UNDETERMINABLE";exit(0);}
    }
    else{
        if(b!=0){tt[i]=c;return;}
        if(a==0&&b==0&&c!=0){tt[i]=c;return;}
        if(b==0&&c==0&&a!=0){tt[i]=a;return;}
        if(c!=0&&a!=0){
            if(a==c){tt[i]=a;return ;}
            else {cout<<"UNDETERMINABLE";exit(0);}
        }
    }
}
void Solve()
{
    for(int i=1;i<=n;i++)
    {
        if(dem[1][i]!=0&&dem[2][i]!=0){cout<<"UNDETERMINABLE";exit(0);}
        if(dem[1][i]!=0)tt[i]=1;
        if(dem[2][i]!=0)tt[i]=2;
    }
    if(n<=2)
    {
        if(n==1)
        {
            if(tt[1]==0){cout<<"UNDETERMINABLE";exit(0);}
            else cout<<0;
        }
        if(n==2)
        {
            if(tt[1]==0||tt[2]==0){cout<<"UNDETERMINABLE";exit(0);}
            if(tt[1]==tt[2])cout<<1;
            else cout<<0<<0;
        }
        exit(0);
    }
    for(int i=1;i<=n-2;i++)
    {
        if(tt[i]!=0&&tt[i]==tt[i+1]&&tt[i+1]==tt[i+2]){cout<<"UNDETERMINABLE";exit(0);}
    }
    for(int i=1;i<=n;i++)
    {
        if(tt[i]==0){tim(i);}
    }
    for(int i=1;i<=n;i++)
    {
        if(tt[i]==tt[i+1]){cout<<1;i++;}
        else cout<<0;
    }
}
main()
{
    freopen("PTIT121F.INP","r",stdin);
    ReadInPut();
    Solve();
}
