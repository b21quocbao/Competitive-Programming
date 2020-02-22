#include <bits/stdc++.h>

#define fn "test"
#define fn1 "NOEL"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
long long f[70][70][70][2];
string s;
int n;
int e[70][2];
int km[70];

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

long long F (int i, int id, int k, bool ok)
{
    if (id < i && k == (int)(s.size() - 1)) return 0;
    if ((id == i) && ok) return (k == (s.size() - 1));
    if (f[i][id][k][ok] != - 1) return f[i][id][k][ok];
    int Id = (id + 1) % n;
    f[i][id][k][ok] = 0;
    for (int j = 0; j < 2; ++ j)
    f[i][id][k][ok] += F (i, Id, e[k][j], 1);
    return f[i][id][k][ok];
}

void enter()
{
    cin >> n;
    cin >> s;
    s = '#' + s;
    int r = 0;
    km[1] = 0;
    for (int i = 2; i < s.size(); ++ i)
    {
        while (r && s[r + 1] != s[i])
        r = km[r];
        if (s[r + 1] == s[i])
        ++ r;
        km[i] = r;
    }
    for (int i = 0; i < s.size(); ++ i)
    for (int j = 0; j < 2; ++ j)
    {
        int r = i;
        if (i == s.size() - 1) r = km[r];
        while (r && (s[r + 1] - '0') != j)
        r = km[r];
        if ((s[r + 1] - '0') == j) ++ r;
        e[i][j] = r;
    }
    
    memset (f, - 1, sizeof (f));
    long long sol = 0;
    for (int i = 0; i < n; ++ i)
    {
        sol += F (i, i, s.size() - 1, 0);
    }
    cout << sol;
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