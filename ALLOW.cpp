#include <bits/stdc++.h>

#define fn "test"
#define fn1 "ALLOW"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int v[mn], b[mn], B[mn], V[mn], id[mn];

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
    int n, c;
    cin >> n >> c;
    int sol = 0;
    for (int i = 0; i < n; ++ i)
    {
        cin >> v[i] >> b[i];
        V[i] = v[i]; B[i] = b[i];
        id[i] = i;
        if (v[i] >= c)
        {
            sol += b[i];
            -- i;
            -- n;
        }
    }
    sort (id, id + n, [](int i, int j)
         {
             return V[i] < V[j];
         });
    for (int i = 0; i < n; ++ i)
    v[i] = V[id[i]], b[i] = B[id[i]];
    for (int i = (1 << n) - 1; i > 0 ; -- i)
    {
        int r = 0;
        for (int j = 0; j < n; ++ j)
        if ((i >> j) & 1) r += v[j];
        if (!r) continue;
        if (c % r) continue;
        int mi = - 1;
        for (int j = 0; j < n; ++ j)
        if ((i >> j) & 1) 
        if (mi == - 1 || b[mi] > b[j]) mi = j;
        sol += b[mi] / (c / r);
        int d = b[mi] - b[mi] % (c / r);
        for (int j = 0; j < n; ++ j)
        if ((i >> j) & 1)
        b[j] -= d;
    }
    for (int i = n - 1; i >= 0; -- i)
    if (!b[i])
    {
        b[i] = b[-- n];
        v[i] = v[n];
    }
    while (1)
    {
        int r = - 1, k = 0;
        for (int i = 0; i < (1 << n); ++ i)
        {
            int s = 0;
            for (int j = 0; j < n; ++ j)
            if ((i >> j) & 1)
            s += v[j];
            if (s >= c && (r == - 1 || s < r))
            {
                r = s;
                k = i;
            }
        }
        if (r == - 1) break;
        int sl = - 1;
        for (int i = 0; i < n; ++ i)
        if ((k >> i) & 1)
        if (sl == - 1 || b[i] < b[sl]) sl = i;
        sol += b[sl];
        for (int i = 0; i < n; ++ i)
        if ((k >> i) & 1)
        b[i] -= b[sl];
        b[sl] = b[-- n];
        v[sl] = v[n];
    }
    for (int i = 0; i < n; ++ i)
    sol += b[i] / (c / v[i] + 1);
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