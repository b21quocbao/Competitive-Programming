#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e3) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int id[mn], d;
string ax[mn];
bool vs[mn];
int sc[mn][mn];
vector<int> e[mn];

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

void dfs (int u)
{
    if (vs[u]) return;
    vs[u] = 1;
    sc[u][0] = 1;
    for (int v : e[u])
    {
        dfs (v);
        for (int i = 1; i <= d; ++ i)
        if (!sc[v][i - 1]) break;
        else
        sc[u][i] += sc[v][i - 1];
    }
}

bool operator < (string a, string b)
{
    for (int i = 0; i < min (a.size(), b.size()); ++ i)
    if (a[i] != b[i])
    return (a[i] < b[i]);
    return (a.size() < b.size());
}

void enter()
{
    int n;
    cin >> n >> d;
    map<string, int> mu;
    int cnt = 0;
    cout << "Tree " << tt << ":\n";
    for (int i = 0; i < n; ++ i)
    {
        string s;
        cin >> s;
        if (mu.find (s) == mu.end())
        {
            mu[s] = ++ cnt;
            ax[cnt] = s;
        }
        int r = mu[s];
        int m;
        cin >> m;
        e[r].clear();
        for (int j = 0; j < m; ++ j)
        {
            string s1;
            cin >> s1;
            if (mu.find (s1) == mu.end()) 
            {
                mu[s1] = ++ cnt;
                ax[cnt] = s1;
            }
            e[r].emplace_back(mu[s1]);
        }
    }
    memset (vs, 0, sizeof (vs));
    memset (sc, 0, sizeof (sc));
    for (int i = 1; i <= cnt; ++ i)
    if (!vs[i])
    dfs (i);
    for (int i = 1; i <= cnt; ++ i)
    {
        id[i] = i;
        e[i].clear();
    }
    sort (id + 1, id + cnt + 1, [](int i, int j)
         {
             if (sc[i][d] != sc[j][d])
             return sc[i][d] > sc[j][d];
             return ax[i] < ax[j];
         });
    if (cnt <= 3)
    {
        for (int i = 1; i <= cnt; ++ i)
        if (sc[id[i]][d])
        {
            cout << ax[id[i]] << " " << sc[id[i]][d] << "\n";
        }
        return;
    }
    if (!sc[id[3]][d])
    {
        for (int i = 1; i <= 3; ++ i)
        if (sc[id[i]][d])
        {
            cout << ax[id[i]] << " " << sc[id[i]][d] << "\n";
        }
        return;
    }
    for (int i = 1; i <= 3; ++ i)
    {
        cout << ax[id[i]] << " " << sc[id[i]][d] << "\n";
    }
    for (int i = 4; i <= n; ++ i)
    if (sc[id[i]][d] == sc[id[3]][d])
    {
        cout << ax[id[i]] << " " << sc[id[i]][d] << "\n";
    }
}

void solve()
{
    cout << "\n";
}

void print_result()
{

}

int main()
{
    docfile();
    cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}