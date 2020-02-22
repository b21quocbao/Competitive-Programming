#include <bits/stdc++.h>

#define fn "test"
#define fn1 "BALANCE"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
bool ok[mn];
int gt[mn];
int sol, a[mn], n, x[mn];
int f[5 * mm][(1 << 14) + 2];
map<int, int> ma;

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

void attemp (int id)
{
    if (id > n)
    {
        for (int j = 0; j < (1 << n); ++ j)
        {
            bool ok = 1;
            long long s1 = 0, s2 = 0;
            for (int i = 1; i <= n; ++ i)
            {
                if ((j >> (i - 1)) & 1)
                s1 += a[x[i]];
                else
                s2 += a[x[i]]; 
                if (s1 > s2)
                {
                    ok = 0;
                    break;
                }
            }
            if (ok) ++ sol;
        }
    }
    for (int i = 1; i <= n; ++ i)
    if (!ok[i])
    {
        x[id] = i;
        ok[i] = 1;
        attemp (id + 1);
        ok[i] = 0;
    }
}

void process1()
{
    attemp (1);
}

int F (int s, int t)
{
    if (s < 0) return 0;
    if (t == (1 << n) - 1) return 1;
    if (ma.find (s) == ma.end())
    ma[s] = ma.size() - 1;
    int k = ma[s];
    if (f[k][t] != - 1) return f[k][t];
    f[k][t] = 0;
    for (int i = 0; i < n; ++ i)
    if (((t >> i) & 1) == 0)
    {
        f[k][t] += F (s - a[i + 1], t ^ (1 << i));
        f[k][t] += F (s + a[i + 1], t ^ (1 << i));
    }
    return f[k][t];
}

void process2()
{
    memset (f, - 1, sizeof (f));
    sol = F (0, 0);
}

void process3()
{

}

void enter()
{
    cin >> n;
    for (int i = 1; i <= n; ++ i)
    {
        cin >> a[i];
    }
    // process2();
    if (n <= 7) process1 ();
    else if (n <= 14) process2 ();
    else process3 ();
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