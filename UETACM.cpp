#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = (1 << 16) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int n, k;
long long ma[mn], ma2[mn];
long long s[mn];
int lo[mn], a[mm][20];

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

void run (int i, int id, int x)
{
    if (id == k)
    {
        ma2[x | i] = max (ma2[x | i], ma[x] + ma[i]);
        return;
    }
    run (i, id + 1, x);
    if ((i >> id) & 1) return;
    run (i, id + 1, x | (1 << id));
}

void enter()
{
    cin >> n >> k;
    int r = 0;
    for (int i = 1; i <= (1 << k); i <<= 1)
    lo[i] = r ++;
    for (int i = 1; i <= n; ++ i)
    {
        for (int j = 0; j < k; ++ j)
        cin >> a[i][j];
        memset (s, 0, sizeof (s));
        for (int l = 1; l < (1 << k); ++ l)
        {
            s[l] = s[l - (l & - l)] + a[i][lo[l & - l]];
            ma[l] = max (ma[l], s[l]);
        }
    }
    for (int i = 0; i < (1 << k); ++ i)
    run (i, 0, 0);
    long long sol = 0;
    for (int i = 0; i < (1 << k); ++ i)
    sol = max (sol, ma2[i] + ma [(1 << k) - 1 - i]);
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