#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define FD(i,a,b) for(int i=(int)a;i>=(int)b;i--)
#define pii pair<int,int>
#define reset(x,y) memset(x, y,sizeof(x))
#define MIN(x,y) if (x > (y)) x = (y)
#define MAX(x,y) if (x < (y)) x = (y)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define oo 1000006
#define EL putchar('\n')
#define mod (int)(1e9+7)
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
int n;
int a[oo],b[oo],res[oo];
int dem[oo],nex[oo];
void ReadInPut()
{
    n=read();
    F(i,1,n)a[i]=read();
    F(i,1,n){b[i]=read();dem[b[i]]++;}
}
int tim(int i)
{

    if(dem[i%n]>0)return i;
    nex[i]=tim(nex[i]);
    return nex[i];
}
void Solve()
{
    F(i,0,2*n)
    {
        dem[i]=dem[i%n];
    }
    int pos=3*n;
    FD(i,2*n,0)
    {
        nex[i]=pos;
        if(dem[i%n]>0)pos=i;
    }
    F(i,1,n)
    {
        if(dem[(n-a[i])%n]>0)
        {
            dem[(n-a[i])%n]--;
            res[i]=0;
        }
        else{
          //  cout<<i<<" ";
            nex[(n-a[i])%n]=tim(nex[(n-a[i])%n]);
            res[i]=(a[i]+nex[(n-a[i])%n])%n;
            dem[nex[(n-a[i])%n]%n]--;
          //  cout<<dem[nex[(n-a[i])%n]%n<<'\n';
        }
        cout<<res[i]<<" ";
    }
}
main()
{
    freopen("test.inp", "r", stdin);
freopen("test.ans", "w", stdout);
//    freopen(".INP","r",stdin);
  //  freopen(".OUT","w",stdout);
    int sotest=1;
    //cin>>sotest;
    for(int i=1;i<=sotest;i++)
    {
        ReadInPut();
        Solve();
    }
}