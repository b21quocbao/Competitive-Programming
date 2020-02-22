#include <bits/stdc++.h>
#include <time.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int f[(1 << 12) + 10][14];
int lo[(1 << 12) + 10];
pair<int, int> a[20];
int x[15], y[15];
vector<int> ax[(1 << 12) + 10];

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

inline int G (int x[], int cn)
{
    sort (x, x + cn);
    int r = (int)cn / 2, s = 0;
    for (int i = 0; i < cn; ++ i)
    s += abs (x[i] - x[r]);
    return s;
}

int F (int id, int k)
{
    if (!id) return 0;
    if (f[id][k] != - 1) return f[id][k]; 
    if (k == 1)
    {
        int cx = 0, cy = 0;  
        for (; id; id -= id & - id)
        {
            x[cx ++] = (a[lo[id & - id]].first);
            y[cy ++] = (a[lo[id & - id]].second);  
        }
        return f[id][k] = G (x, cx) + G (y, cy);
    }
    f[id][k] = INT_MAX;
    if (k & 1)
    {
        for (const int& i : ax[id])
        f[id][k] = min (f[id][k], F (i, 1) + F (id ^ i, k - 1));
    }
    else
    {
        for (const int& i : ax[id])
        {
            if (i > (id ^ i)) break;
            f[id][k] = min (f[id][k], F (i, k >> 1) + F (id ^ i, k >> 1));
        }
    }
    return f[id][k];
}

void enter()
{
    clock_t st = clock();
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++ i)
    {
        cin >> a[i].first >> a[i].second;
    }
    for (int i = 0; i <= 12; ++ i)
    lo[1 << i] = i;
    memset (f, - 1, sizeof (f));
    int s = 0;
    for (int i = 0; i <= (1 << n); ++ i)
    for (int j = 0; j <= i; ++ j)
    if ((j | i) == i)
    ax[i].emplace_back(j);
    cout << F ((1 << n) - 1, k);
    // cerr << fixed << setprecision(5) << (double)(clock() - st) / CLOCKS_PER_SEC;
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