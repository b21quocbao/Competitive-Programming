#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int n;
int cnt;
vector<int> e[20];
bool pr[100];
int cid;
int Id[(1 << 18) + 10];
int ax[(1 << 18) + 10];
int a[30];
bool ok[30];
int d[5 * 10000][20][20];

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

void process (int id)
{
    if (id == n)
    {
        int s = 0;
        for (int j = 0; j < n; ++ j)
        s ^= (1 << a[j]);
        if (!Id[s]) 
        {
            Id[s] = ++ cid;
            ax[cid] = s;
        }\
        ++ d[Id[s]][a[0]][a[n - 1]];
        return;
    }
    for (int j = 0; j < 2 * n; ++ j)
    if (!ok[j])
    {
        if (id && !pr[a[id - 1] + j + 2]) continue;
        ok[j] = 1;
        a[id] = j;
        process (id + 1);
        ok[j] = 0;
    }
}

void process2 (int id)
{
    if (id == 2 * n)
    {
        if (!pr[a[2 * n - 1] + a[0] + 2]) return;
        if (++ cnt > 10000) exit (0);
        for (int i = 0; i < 2 * n; ++ i)
        cout << a[i] + 1 << " ";
        cout << "\n";
        return;
    }
    for (int i = 0; i < 2 * n; ++ i)
    {
        if (ok[i]) continue;
        if (id && !pr[a[id - 1] + i + 2]) continue;
        ok[i] = 1;
        a[id] = i;
        process2 (id + 1);
        ok[i] = 0;
    }
}

void enter()
{
    cin >> n;
    pr[2] = pr[3] = pr[5] = pr[7] = pr[11] = pr[13] = pr[17] = pr[19] = 1;
    pr[23] = pr[29] = pr[31] = pr[37] = 1;
    for (int i = 0; i < 2 * n; ++ i)
    for (int j = 0; j < 2 * n; ++ j)
    if ((i != j) && (pr[i + j + 2]))
    e[i].emplace_back(j);
    process (0);
    long long sol = 0;
    for (int i = 1; i <= cid; ++ i)
    if (ax[i] & 1)
    {
        int rv = Id[(1 << (2 * n)) - 1 - ax[i]];
        for (int j = 1; j < 2 * n; ++ j)
        for (int k : e[j])
        for (int t : e[0])
        sol += 1ll * d[i][0][j] * d[rv][k][t];
    }
    a[0] = 0;
    ok[0] = 1;
    cout << sol << "\n";
    process2 (1);
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