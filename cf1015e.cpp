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
struct Z
{
    int a, b, c;
};
int m, n;
char s[mn][mn];
int c[mn][mn], h[mn][mn], cs[mn][mn], hs[mn][mn];


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

void enter()
{
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; ++ i)
    for (int j = 1; j <= n; ++ j)
    cin >> s[i][j];
    for (int i = 1; i <= m; ++ i)
    for (int j = 1; j <= n; ++ j)
    {
        c[i][j] = c[i][j - 1];
        if (s[i][j] == '*') ++ c[i][j];
    }
    for (int j = 1; j <= n; ++ j)
    for (int i = 1; i <= m; ++ i)
    {
        h[i][j] = h[i - 1][j];
        if (s[i][j] == '*') ++ h[i][j];
    }
    vector<Z> v;
    for (int i = 1; i <= m; ++ i)
    for (int j = 1; j <= n; ++ j)
    if (s[i][j] == '*')
    {
        int inf = 0, sup = m, sol;
        while (inf <= sup)
        {
            int mid = (inf + sup) >> 1;
            if (!(i - mid >= 1 && i + mid <= m && j - mid >= 1 && j + mid <= n)) 
            {
                sup = mid - 1;
                continue;
            }
            if (c[i][j + mid] - c[i][j - mid - 1] != 2 * mid + 1) 
            {
                sup = mid - 1;
                continue;
            }
            if (h[i + mid][j] - h[i - mid - 1][j] != 2 * mid + 1) 
            {
                sup = mid - 1;
                continue;
            }
            sol = mid;
            inf = mid + 1;
        }
        if (!sol) continue;
        ++ cs[i][j - sol];
        -- cs[i][j + sol + 1];
        ++ hs[i - sol][j];
        -- hs[i + sol + 1][j];
        v.push_back({i, j, sol});
    }
    for (int i = 1; i <= m; ++ i)
    for (int j = 1; j <= n; ++ j)
    {
        cs[i][j] += cs[i][j - 1];
        hs[i][j] += hs[i - 1][j];
        if (((s[i][j] == '*') && (!cs[i][j] && !hs[i][j])))
        {
            cout << - 1;
            return;
        }
    }
    cout << v.size() << "\n";
    for (auto k : v)
    cout << k.a << " " << k.b << " " << k.c << "\n";

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