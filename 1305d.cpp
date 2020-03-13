/*
Code by b21
Time: 22:31 Tue 03/03/2020
*/

#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i=a;i<b;++i)
#define ROR(i,b,a) for (int i=b;i>a;--i)
#define FOE(i,a,b) for (int i=a;i<=b;++i)
#define ROE(i,b,a) for (int i=b;i>=a;--i)

using namespace std;

const int mn = 2 * (int)(1e3) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
void docfile()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (ifstream("test.inp"))
    {
       freopen("test.inp", "r", stdin);
       if (!aNs) freopen("test.out", "w", stdout);
       else freopen ("test.ans", "w", stdout);
    }
   else if (ifstream("1305d.inp"))
    {
        freopen("1305d.inp", "r", stdin);
        freopen("1305d.out", "w", stdout);
    }
}

template <typename T>
void read(T& x)
{
    x = 0; T f = 1;
    char ch = getchar();
    while (!isdigit(ch)) f = ch == '-' ? - f : f, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    x *= f;
}

template <typename T>
void write (T a)
{
    if (a < 0)
    {
        putchar ('-');
        write (-a);
        return;
    }
    if (a < 10)
    {
        putchar ('0' + a);
        return;
    }
    write (a / 10);
    putchar ((char)('0' + (a % 10)));
}

typedef long long ll;
typedef pair<int,int> ii;
typedef unsigned long long ull;

#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define ep emplace_back
#define EL printf("\n")
#define sz(A) (int) A.size()
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FOD(i,r,l) for (int i=r;i>=l;i--)
#define fillchar(a,x) memset(a, x, sizeof (a))
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


const int   N = 2e3;
int         n, m, r, u, v, k, q, up[N][100], times;
ii          t[N];
vector<int> a[N];
char        ch;

void reset() {
	m = 0;
	for (int i=n; i/2>0; i/=2) m++;
	for (int i=1; i<=n; i++) {
		a[i].clear();
		t[i].X = t[i].Y = 0;
		for (int j=0; j<=m; j++) up[i][j] = 0;
	}
	r = 1;
	times = 0;
}

void dfs(int u, int v) {
	t[v].X = ++times;
	up[v][0] = u;
	for (int j=1; j<=m; j++) up[v][j] = up[up[v][j-1]][j-1];
	for (int i=0; i<a[v].size(); i++) {
		int k = a[v][i];
		if (k == u) continue;
		dfs(v,k);
	}
	t[v].Y = ++times;
}

bool upper(int u, int v) {
	return (t[u].X <= t[v].X and t[v].Y <= t[u].Y);
}

int lca(int u, int v) {
	if (upper(u,v)) return u;
	if (upper(v,u)) return v;
	for (int j=m; j>=0; j--)
		if (up[u][j] > 0 and !upper(up[u][j],v)) u = up[u][j];
	return up[u][0];
}

int get(int r, int u, int v) {
	if (upper(r,u) or upper(r,v)) return r;
	for (int j=m; j>=0; j--)
		if (up[r][j] > 0 and !upper(up[r][j],u) and !upper(up[r][j],v)) r = up[r][j];
	return up[r][0];
}


void enter()
{
    
}

void solve()
{

}

int H[mn];
set<int> e[mm];
set<int> se;

void clearNode (int u) {
    for (int v : e[u])
    e[v].erase(u);
    e[u].clear();
}

void dfs1 (int u) {
    for (int v : e[u])
    if (!H[v]) {
        H[v] = H[u] + 1;
        dfs1 (v);
    }
}

int dfs2 (int u) {
    memset (H, 0, sizeof (H));
    H[u] = 1;
    dfs1 (u);
    int U = u;
    for (int u = 1; u <= n; ++ u)
    if (H[u] > H[U])
    U = u;
    se.erase (U);
    return U;
}

void print_result()
{
    cin >> n;
    reset();
    for (int i = 1; i < n; ++ i) {
        int u, v;
        cin >> u >> v;
        e[u].emplace(v);
        e[v].emplace(u);
        a[u].pb(v);
        a[v].pb(u);
    }
    dfs(0,1);
    vector<int> l;
    for (int i = 1; i <= n; ++ i)
    l.emplace_back(i);
    for (int i = 1; i <= n; ++ i)
    se.emplace(i);
    for (int i = 1; i <= n / 2; ++ i)
    {
        int U = dfs2 (*se.begin());
        int V = dfs2 (U);
        clearNode(U);
        clearNode(V);
        cout << "? " << U << " " << V << endl;
        int x;
        cin >> x;
        vector<int> L;
        for (int i : l)
        {
            r = i;
            int k = lca(U,V);
			if (k == r or !upper(k,r)) {
			}
            else
			k = get(r,U,V);
            if (k == x) 
            L.emplace_back(r);
        }
        if (L.size())
        l.swap(L);
    }
    cout << "! " << l[0] << endl;
}

main()
{
    // docfile();
    //cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}