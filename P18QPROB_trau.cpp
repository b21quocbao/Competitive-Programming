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
#define inf 0x3f3f3f3f
#define ppi pair<int,pii>
#define oo
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
int n,m;
ll L[105][10004],Max;
ll f[105];
vector<ppi>a[105];
void ReadInPut()
{
    n=read();m=read();
    for(int i=1;i<=m;i++)
    {
        int u,v,c,t;
        u=read();v=read();t=read();c=read();
        a[u].pb(mp(v,mp(c,t)));
        a[v].pb(mp(u,mp(c,t)));
    }
}
void Djkstra()
{
    priority_queue<ppi,vector<ppi>,greater<ppi> >pq;
    memset(L,10,sizeof(L));
    memset(f,10,sizeof(f));
    L[1][0]=0;
    Max=L[1][1];
    pq.push(mp(0,mp(1,0)));
    while(pq.size())
    {
        int c=pq.top().fi;
        int i=pq.top().se.fi;
        int t=pq.top().se.se;
        pq.pop();
        f[i]=min(f[i],(ll)c*t);
        if(L[i][t]!=c)continue;
        for(int z=0;z<a[i].size();z++)
        {
            int t1=t+a[i][z].se.se;
            int v=a[i][z].fi;
            int c1=a[i][z].se.fi;
            if(L[v][t1]>L[i][t]+c1&&f[v]>((L[i][t]+c1)*t1))
            {
                L[v][t1]=L[i][t]+c1;
                pq.push(mp(L[v][t1],mp(v,t1)));
            }
        }
    }
}
void Solve()
{
    Djkstra();
    for(int i=2;i<=n;i++){
        if(f[i]==Max){cout<<-1<<'\n';continue;}
        cout<<f[i]<<'\n';
    }
}
main()
{
  //  freopen("P18B.INP","r",stdin);
  //  freopen(".OUT","w",stdout);
  freopen("test.inp", "r", stdin);
freopen("test.ans", "w", stdout);
    ReadInPut();
    Solve();
}
