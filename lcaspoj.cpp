#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i=a;i<b;++i)
#define ROR(i,b,a) for (int i=b;i>a;--i)
#define FOE(i,a,b) for (int i=a;i<=b;++i)
#define ROE(i,b,a) for (int i=b;i>=a;--i)
#define X first
#define Y second
#define fn "test"
#define fn1 ""
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll,ll> pl;
typedef vector<ii> vii;
typedef vector<pl> vll;
const int mn=int(1e3)+10;
int n;
int cnt;
vi e[mn];
int nc[mn], h[mn], fa[mn], he[mn], nch, chin[mn];
void docfile()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (ifstream(fn".inp"))
    {
        freopen(fn".inp","r",stdin);
        freopen(fn".out","w",stdout);
    }else if (ifstream(fn1".inp"))
    {
        freopen(fn1".inp","r",stdin);
        freopen(fn1".out","w",stdout);
    }
}
int read()
{
    int x=0,f=1;
    char c=getchar();
    while (!isdigit(c)) f=c=='-'?-f:f,c=getchar();
    while (isdigit(c)) x=x*10+c-'0',c=getchar();
    return x*f;
}
void writeInt(int a)
{
    int i=0;
    char S[20];
    if (a == 0) {putchar('0');return;}
    while(a>0)
    {
        S[i++]=a%10+'0';
        a=a/10;
    }
    --i;
    while(i>=0)
    putchar(S[i--]);
}

class LCA
{
    public:
    vector<int> nc, h, fa, he, chin;
    int nch, n, cnt;
    vector<vector<int>> e;
    LCA (int n)
    {
        nc.resize(n + 1);
        h.resize(n + 1);
        fa.resize(n + 1);
        he.resize(n + 1);
        chin.resize(n + 1);
        e.resize(n + 1);
    }

    void Init()
    {
        cnt = nch = 0;
        chil(1);
        hld(1);
        dfs(1, 0);
    }

    void AddEdge (int u, int v)
    {
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    int chil(const int& di)
    {
        nc[di] = 1;
        for (const int& v: e[di])
        {
            if (!nc[v])
            {
                nc[di] += chil(v);
                fa[v] = di;
            }
        }
        return nc[di];
    }
    void hld(const int& u)
    {
        if (!he[nch]) he[nch] = u;
        chin[u] = nch;
        int re = -1;
        for (const int& v : e[u])
        {
            if (fa[u] != v)
            if (re == -1 || nc[v] > nc[re]) re = v;
        }
        if (re != -1) hld(re);
        for (const int& v : e[u])
        if (fa[u] != v && v != re)
        {
            ++nch;
            hld(v);
        }
    }
    void dfs(const int& di, const int& cs)
    {
        h[di] = cs;
        for (const int& v : e[di])
        {
            if (v != fa[di])
            dfs(v, cs + 1);
        }
    }
    int lca (int u, int v)
    {
        while (chin[u] != chin[v])
        if (h[he[chin[u]]] > h[he[chin[v]]])
        u = fa[he[chin[u]]];
        else v = fa[he[chin[v]]];
        if (h[u] > h[v]) return v;
        return u;
    }
};
void enter()
{
    n = read();
    LCA l (n);
    FOE (i, 1, n)
    {
        int c;
        c = read();
        FOR (j, 0, c)
        {
            int u;
            u = read();
            l.AddEdge(i, u);
        }
    }
    l.Init();
    int q;
    printf("%s", "Case ");writeInt(++cnt);puts(":");
    q = read();
    FOR (i, 0, q)
    {
        int a = read(), b = read();
        writeInt(l.lca (a, b)); putchar('\n');
    }
}

void querylca()
{
    
}
void solve()
{
    
}
void print_result()
{
 
}
int main()
{
    docfile();
    int t=1;
    t = read();
    FOR(tt,0,t)
    {
        enter();
        solve();
        print_result();
    }
}