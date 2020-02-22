#include <bits/stdc++.h>
#define MAXN 5001
#define sz(a) static_cast<long long>(a.size())
#define pb push
#define mp make_pair
using namespace std;

typedef pair<int,int> pp;
int n,m,a[MAXN][MAXN],xs,ys,xf,yf;
bool ok[MAXN][MAXN],vis[MAXN][MAXN];
int dist[MAXN][MAXN];
pair<pp,int> p;
queue<pair<pp,int> > q;

template<typename T>
void Read(T &x)
{
    bool Neg = false;
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-') Neg = !Neg;
    x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (Neg) x = -x;
}

template<typename T>
void Write(T x)
{
    if (x < 0)
    {
        putchar('-');
        Write(-x);
        return;
    }
    if (x > 9) Write(x / 10);
    putchar(x % 10 + '0');
}

void loang(){
	int x,y,xx,yy;
	q.pb(mp(mp(xs,ys),0));
	vis[xs][ys]=true; dist[xs][ys]=0;
	while (!q.empty()){
		p=q.front(); q.pop();
		x=p.first.first; y=p.first.second;
		if (x==xf&&y==yf) return;
		if (x>1&&y>1&&!vis[x-1][y-1]){
			xx=x-1; yy=y-1;
			while (!vis[xx][yy]){
				if (!xx || !yy || ok[xx][yy]) break;
				vis[xx][yy]=true; dist[xx][yy]=dist[x][y]+1;
				q.pb(mp(mp(xx,yy),dist[xx][yy]));
				--xx; --yy;
			}
		}
		if (x>1&&y<n&&!vis[x-1][y+1]){
			xx=x-1; yy=y+1;
			while (!vis[xx][yy]){
				if (!xx || yy>n || ok[xx][yy]) break;
				vis[xx][yy]=true; dist[xx][yy]=dist[x][y]+1;
				q.pb(mp(mp(xx,yy),dist[xx][yy]));
				--xx; ++yy;
			}
		}
		if (x<n&&y<n&&!vis[x+1][y+1]){
			 xx=x+1; yy=y+1;
			while (!vis[xx][yy]){
				if (xx>n || yy>n || ok[xx][yy]) break;
				vis[xx][yy]=true; dist[xx][yy]=dist[x][y]+1;
				q.pb(mp(mp(xx,yy),dist[xx][yy]));
				++xx; ++yy;
			}
		}
		if (x<n&&y>1&&!vis[x+1][y-1]){
			 xx=x+1; yy=y-1;
			while (!vis[xx][yy]){
				if (xx>n || !yy || ok[xx][yy]) break;
				vis[xx][yy]=true; dist[xx][yy]=dist[x][y]+1;
				q.pb(mp(mp(xx,yy),dist[xx][yy]));
				++xx; --yy;
			}
		}
	}
}
main(){
    //freopen("inp.txt","r",stdin); //freopen("out.txt","w",stdout);
	//freopen(".INP","r",stdin); freopen(".OUT","w",stdout);
	Read(n);    Read(m);
	Read(xs);   Read(ys);   Read(xf);   Read(yf);
	int i,j,k;
	for( i=1;i<=m;++i){
		Read(j);
		Read(k);
		ok[j][k]=true;
	}
	loang();
	if (!vis[xf][yf]) Write(-1);
	else Write(dist[xf][yf]);
}