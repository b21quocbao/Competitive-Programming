#include <bits/stdc++.h>

#define int int64_t
#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 34;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;
const int M = (int)(1e9) + 2;

int tt, ntest = 1;
map<int, int> g;
bool ok[mn], Ok[mn];
vector<int> v;
int V[mn];

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

int po (int n, int k)
{
    if (!k) return 1;
    int r = po (n, k >> 1);
    if (M / r < r) return M;
    r = r * r;
    if (k % 2 == 0) return r;
    return (M / r < n ? M : r * n);
}

int G (int x)
{
    if (!x) return 0;
    if (g.count(x)) return g[x];
    int n;
    int vc = 0;
    for (int i = 1; (1 << (i - 1)) <= x; ++ i)
    n = i;
    vector<int> V;
    for (int i = 1; (1 << (i - 1)) <= x; ++ i)
    {
        if ((x >> (i - 1)) % 2 == 0) continue;
        int X = x;
        for (int j = i; j <= n; j += i)
        X &= (~(1 << (j - 1)));
        V.emplace_back(G (X));
    }
    int i = 0;
    sort (V.begin(), V.end());
    for (int i = 1; i < V.size(); ++ i)
    if (V[i] > V[i - 1] + 1)
    return (g[x] = V[i - 1] + 1);
    return (g[x] = V.back() + 1);
}

void enter()
{
    int n;
    cin >> n;
    cout << ((n == 2 || n == 8) ? "Kunkka" : "Tide");
    cout << "\n";
    return;
    int re = n;
    int s = G (1);
    for (int i = 1; (1 << i) <= n; ++ i)
    {
        int inf = 2, sup = n, sol1 = - 1, sol2 = - 1;
        while (inf <= sup)
        {
            int mid = (inf + sup) >> 1;
            if (po (mid, i) <= n)
            {
                sol1 = mid;
                inf = mid + 1;
            }
            else sup = mid - 1;
        }
        inf = 2, sup = sol1;
        while (inf <= sup)
        {
            int mid = (inf + sup) >> 1;
            if (po (mid, i + 1) > n)
            {
                sol2 = mid;
                sup = mid - 1;
            }
            else inf = mid + 1;
        }
        if (sol2 == - 1) continue;
        int r = (sol1 - sol2 + 1);
        int c = (int)(upper_bound (v.begin(), v.end(), sol1) - v.begin());
        int d = (int)(lower_bound (v.begin(), v.end(), sol2) - v.begin());
        r -=  (c - d);
        if (r & 1)
        s ^= G ((1 << i) - 1);
    }
    cout << (s ? "Tide" : "Kunkka") << "\n";
}

void solve()
{

}

void print_result()
{

}

int32_t main()
{
    docfile();
    for (int i = 2; i * i <= M; ++ i)
    for (long long j = i * i; j <= M; j *= i)
    v.emplace_back(j);
    sort (v.begin(), v.end());
    v.resize(unique (v.begin(), v.end()) - v.begin());
    cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}