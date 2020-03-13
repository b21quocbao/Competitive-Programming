/**
 *	 Code by b21
 *	 Time: 21:59 Sun 08/03/2020
**/

#include <bits/stdc++.h>
#define int long long

using namespace std;

const int mn = 5 * (int)(1e5) + 10;
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
   else if (ifstream("200308l.inp"))
    {
        freopen("200308l.inp", "r", stdin);
        freopen("200308l.out", "w", stdout);
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

bool ok[mn];
int n, m, c[mn], d[mn], fa[mn], k[mn];
string s[mn];


int K (int u) {
    if (!u) return 0;
    if (ok[u]) return k[u];
    ok[u] = 1;
    k[u] += K (fa[u]);
    return k[u];
}


void enter()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i)
    cin >> s[i] >> c[i] >> d[i];
    for (int i = 1; i <= m; ++ i)
    cin >> fa[i] >> k[i];
    vector<int> v;
    for (int i = 1; i <= n; ++ i) 
    v.emplace_back(d[i] + K (c[i]));
    sort (v.begin(), v.end(), greater<int>());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for (int i = 1; i <= n; ++ i)
    cout << s[i] << " " << lower_bound(v.begin(), v.end(), d[i] + K(c[i]), greater<int>()) - v.begin() + 1 << "\n";
}

void solve()
{

}

void print_result()
{

}

main()
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