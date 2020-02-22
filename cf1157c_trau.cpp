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
int a[oo];
char res[oo];
void ReadInPut()
{
    cin>>n;
    F(i,1,n)a[i]=read();
}
int tim(int i,int j,int l,int r)
{
    if(l>r)return i-1;
    //cout<<i<<" "<<j<<" "<<l<<" "<<r<<'\n';
    if(a[l]<a[r])
    {
        if(a[l]>j){res[i]='L';return tim(i+1,a[l],l+1,r);}
        else {
            if(a[r]>j){res[i]='R';return tim(i+1,a[r],l,r-1);}
            else return i-1;
        }
    }
    if(a[l]>a[r])
    {
        if(a[r]>j){res[i]='R';return tim(i+1,a[r],l,r-1);}
        else {
            if(a[l]>j){res[i]='L';return tim(i+1,a[l],l+1,r);}
            else return i-1;
        }
    }
    if(a[l]==a[r])
    {
        if(a[l]<=j)return i-1;
        int v=(tim(i+1,a[l],l+1,r));
        int v1=(tim(i+1,a[r],l,r-1));
        res[i]='R';
        if(v>v1)
        {
            res[i]='L';
            return tim(i+1,a[l],l+1,r);
        }
        else return v1;
    }
}
void Solve()
{
    int i=1,j=n;
    int t=tim(1,-1,1,n);
    cout<<t;
    EL;
    F(i,1,t)cout<<res[i];

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