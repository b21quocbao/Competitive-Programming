#include <bits/stdc++.h>

#define fn "test"
#define fn1 "LIONDANCE"

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

vector<int> b;

inline bool lh (const int& i, const int& j)
{
    if (b[i] != b[j]) return (b[i] > b[j]);
    return (i > j);
}

void enter()
{
    int n, d;
    cin >> n >> d;
    vector<int> a (n), f (n);
    b.resize(n);
    vector<vector<int> > tr (n, vector<int>(n));
    for (int& i : a) cin >> i;
    for (int& i : b) cin >> i;
    reverse (a.begin(), a.end());
    reverse (b.begin(), b.end());
    int sol = - 1;
    for (int j = 0; j < n; ++ j)
    {
        f[j] = (a[0] == b[j]);
        tr[0][j] = - 1;
        if (sol == - 1 || f[j] > f[sol]) sol = j;
    }
    for (int i = 1; i < n; ++ i)
    {
        int ma = - 1, D = 1;
        for (int j = 0; j < n; ++ j)
        {
            int x = f[j] + 1;
            if (a[i] == b[j])
            {
                f[j] = D;
                tr[i][j] = ma;
                if (f[j] > f[sol] || (f[j] == f[sol] && lh (j, sol)))
                sol = j;
            }
            if (abs (b[j] - a[i]) <= d)
            if (ma == - 1 || (x > D || (x == D && lh (j, ma))))
            {
                ma = j;
                D = x;
            }
        }
    }
    cout << f[sol] << "\n";
    for (int i = n - 1; i >= 0; -- i)
    {
        if (a[i] == b[sol])
        {
            cout << a[i] << " ";
            sol = tr[i][sol];
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