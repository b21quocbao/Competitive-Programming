#include <bits/stdc++.h>

#define fn "test"
#define fn1 "LAMPS2"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
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

int b[3000];
bitset<1> sol[3000];

void enter()
{
    int n, t = 1, m;
    cin >> n >> m;
    bitset<100> a[m];
    for (int i = 0; i < m; ++ i)
    {
        int u, v;
        bool c;
        cin >> u >> v >> c;
        -- u; -- v;
        a[i][v] = 1;
        a[i][u] = 1;
        sol[i][0] = (!c);
    }
    for (int i = 0; i < n; ++ i)
    {
        for (int j = i; j < m; ++ j)
        if (a[j][i])
        {
            swap (a[j], a[i]);
            swap (sol[j], sol[i]);
            break;
        }
        if (!a[i][i]) continue;
        for (int j = i + 1; j < m; ++ j)
        if (a[j][i])
        {
            a[j] ^= a[i];
            sol[j] ^= sol[i];
        }
    }
    for (int i = m - 1; i >= 0; -- i)
    for (int j = 0; j < i; ++ j)
    if (a[j][i])
    {
        a[j] ^= a[i];
        sol[j] ^= sol[i];
    }
    for (int i = 0; i < 1; ++ i)
    {
        bool ok = 1;
        for (int j = n - 1; j >= 0; -- j)
        if (!a[j][j])
        {
            if (sol[j][i]) 
            {
                cout << "Impossible\n";
                ok = 0;
                break;
            }
            else b[j] = 0;
        }
        else
        b[j] = sol[j][i];
        if (ok)
        {
            int cn = 0;
            for (int i = 0; i < n; ++ i)
            if (b[i]) ++ cn;
            cout << cn << " ";
            for (int i = 0; i < n; ++ i)
            if (b[i])
            cout << i + 1 << " ";
            cout << "\n";
        }
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