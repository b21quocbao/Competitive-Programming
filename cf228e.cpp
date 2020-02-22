#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e2) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;

void docfile()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (ifstream(fn".inp"))
    {
        freopen(fn".inp", "r", stdin);
        if (!aNs) freopen(fn".out", "w", stdout);
		else freopen (fn".ans", "w", stdout);
    }else if (ifstream(fn1".inp"))
    {
        freopen(fn1".inp", "r", stdin);
        freopen(fn1".out", "w", stdout);
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

bool Ok;
bool ok[mn];
int ds[mn][mn];
int c[mn][mn];
int id[mn];
int b[mn];
vector<int> V;
int M;
vector<int> e[mn];
bitset<100> k;
vector<bitset<100>> a;
bool sol[mn * mn];

void dfs (int u)
{
    ok[u] = 1;
    for (int v : e[u])
    if (!ok[v])
    {
        if (!c[u][v]) Ok = 1;
        dfs (v);
    }
}

void dfs2 (int u)
{
    V.emplace_back(u);
    id[u] = V.size() - 1;
    ok[u] = 1;
    for (int v : e[u])
    {
        if (!ok[v])
        dfs2 (v);
        if (!ds[id[u]][id[v]]) 
        {
            // cerr << u << " " << v << "\n";
            ds[id[u]][id[v]] = ++ M;
            ds[id[v]][id[u]] = ds[id[u]][id[v]];
            a.emplace_back(k);
        }
        a[ds[id[u]][id[v]] - 1][id[u]] = 1;
        sol[ds[id[u]][id[v]] - 1] = (!c[u][v]);
        // if (u == 2 && v == 6) cerr << ds[id[u]][id[v]] - 1 << " " << sol[ds[id[u]][id[v]] - 1] << "\n";
    }
}

bool o44 = 0;

void enter()
{
    int n, m, cn = 0;
    cin >> n >> m;
    for (int i = 0; i < m; ++ i)
    {
        int u, v;
        cin >> u >> v;
        if (!i && u == 33 && v == 22) o44 = 1;
        cin >> c[u][v];
        c[v][u] = c[u][v];
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    int u = - 1;
    for (int i = 1; i <= n; ++ i)
    if (!ok[i])
    {
        Ok = 0;
        dfs (i);
        if (Ok) 
        {
            ++ cn;
            u = i;
        }
    }
    if (cn >= 2) 
    {
        if (o44)
        {
            cout << "dmm\n";
            cout << cn << "\n";
        }
        cout << "Impossible";
        return;
    }
    if (!cn)
    {
        cout << 0;
        return;
    }
    memset (ok, 0, sizeof (ok));
    dfs2 (u);
    int N = V.size();
    if (o44)
    // cerr << u << "\n";
    cerr << N << " " << M << "\n";
    // for (int i = 0; i < M; ++ i)
    // cout << a[i] << " " << sol[i] << "\n";
    // cout << "\n";
    for (int i = 0; i < N; ++ i)
    {
        for (int j = i; j < M; ++ j)
        if (a[j][i])
        {
            swap (a[j], a[i]);
            swap (sol[j], sol[i]);
            break;
        }
        if (!a[i][i]) continue;
        for (int j = i + 1; j < M; ++ j)
        if (a[j][i])
        {
            a[j] ^= a[i];
            sol[j] ^= sol[i];
        }
    }
    // for (int i = 0; i < M; ++ i)
    // cout << a[i] << " " << sol[i] << "\n";
    // cout << "\n";
    if (M == N - 1)
    {
        for (int j = 0; j < 2; ++ j)
        {
            b[N - 1] = j;
            bool Ok = 1;
            for (int i = N - 2; i >= 0; -- i)
            {
                bool r = 0;
                for (int j = i; j < N; ++ j)
                if (a[i][j] && b[j]) r = (!r);
                if (!a[i][i]) 
                {
                    if (r != sol[i]) Ok = 0; else b[i] = 0;
                }
                else 
                {
                    b[i] = (r ^ sol[i]);
                }
            }
            if (Ok)
            {
                int cn = 0;
                for (int i = 0; i < n; ++ i)
                if (b[i]) ++ cn;
                cout << cn << "\n";
                for (int i = 0; i < n; ++ i)
                if (b[i])
                cout << V[i] << " ";
                cout << "\n";
                return;
            }
        }
        cout << "Impossible";
        return;
    }
    for (int i = N - 1; i >= 0; -- i)
    for (int j = 0; j < i; ++ j)
    if (a[j][i])
    {
        a[j] ^= a[i];
        sol[j] ^= sol[i];
    }
    if (o44)
    {
        for (int i = 0; i < M; ++ i)
        cout << a[i] << " " << sol[i] << "\n";
    }
    for (int i = N; i < M; ++ i)
    if (sol[i])
    {
        cout << "Impossible";
        return;
    }
    for (int j = N - 1; j >= 0; -- j)
    if (!a[j][j])
    {
        if (sol[j]) 
        {
            cout << "Impossible\n";
            return;
        }
        else b[j] = 0;
    }
    else
    b[j] = sol[j];
    if (ok)
    {
        int cn = 0;
        for (int i = 0; i < n; ++ i)
        if (b[i]) ++ cn;
        cout << cn << "\n";
        for (int i = 0; i < n; ++ i)
        if (b[i])
        cout << V[i] << " ";
        cout << "\n";
    }
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
    //cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}