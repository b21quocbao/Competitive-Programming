#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F(i,a,b) for(int i=a;i<=b;i++)
#define FD(i,a,b) for(int i=a;i>=b;i--)
#define pii pair<int,int>
#define reset(x) memset(x, 0,sizeof(x))
#define MIN(x,y) if (x > (y)) x = (y)
#define MAX(x,y) if (x < (y)) x = (y)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define oo 10000007
int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();}
    while (c >= '0' && c <= '9') {x = x * 10 + c - '0'; c = getchar();}
    return x * f;
}
void write(int x)
{
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}
int snt[oo],f[oo][9];
void sangnt()
{
    for(int i=2;i<=sqrt(oo);i++)
    {
        if(snt[i]==0)
        {
            snt[i]=i;
            int j=i*i;
            while(j<oo)
            {
                snt[j]=i;
                j+=i;
            }
        }
    }
    snt[1]=1;
    for(int i=1;i<oo;i++)
    {
        if(snt[i]==0)snt[i]=i;
    }
}
int A,B,K;
void ReadInPut()
{
    cin>>A>>B>>K;
}
void Creat()
{
    sangnt();
    f[1][0]=1;
    for(int i=2;i<oo;i++)
    {
        for(int k=0;k<=8;k++)f[i][k]=f[i-1][k];
        int x=i,sl=0;
        while(x>1)
        {
            sl++;
            int t=snt[x];
            while(x%t==0)x/=t;
        }
        f[i][sl]++;
    }
}
void Solve()
{
    if(K>8){cout<<0;return;}
    if(A>B){cout<<0;return;}
    cout<<f[B][K]-f[A-1][K]<<'\n';
}
main()
{
    freopen("test.inp", "r", stdin);
    freopen("test.ans", "w", stdout);
    int T;
    cin>>T;
    Creat();
    for(int i=1;i<=T;i++)
    {
        ReadInPut();
        cout<<"Case #"<<i<<":"<<" ";
        Solve();
    }
}
