#include <bits/stdc++.h>

#define fn "test"
#define fn1 "SIMILARITY"

using namespace std;

const int mn = 1 * (int)(1e3) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;
const int N = 5;

int tt, ntest = 1;
int n, a[mn], b[mn], m;
struct vi
{
    int a[N];
};
vi ha, v[mn];
struct cmp
{
    bool operator () (vi a, vi b)
    {
        for (int i = 0; i < N; ++ i)
        if (a.a[i] != b.a[i]) return (a.a[i] < b.a[i]);
        return false;
    }
} myc;

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

inline long long po (int a, int n)
{
    if (n == 1) return a;
    if (n == 2) return 1LL * a * a;
    if (n == 3) return 1LL * a * a * a;
}

void F (int& x, int a, int t)
{
    if (!t) x ^= a;
    if (t == 1) x += a;
    if (t == 2) x += a * a;
    if (t == 3) x ^= a * a;
    if (t == 4) x += a * a * a;
}

void F1 (int& x, int a, int t)
{
    if (!t) x ^= a;
    if (t == 1) x -= a;
    if (t == 2) x -= a * a;
    if (t == 3) x ^= a * a;
    if (t == 4) x -= a * a * a;
}

void enter()
{
    cin >> n;
    vector<int> v1;
    for (int i = 0; i < n; ++ i)
    {
        cin >> a[i];
        v1.push_back(a[i]);
    }
    cin >> m;
    for (int i = 0; i < m; ++ i)
    {
        cin >> b[i];
        v1.push_back(b[i]);
    }
    sort (v1.begin(), v1.end());
    v1.resize(unique (v1.begin(), v1.end()) - v1.begin());
    for (int i = 0; i < n; ++ i)
    a[i] = lower_bound (v1.begin(), v1.end(), a[i]) - v1.begin();
    for (int i = 0; i < m; ++ i)
    b[i] = lower_bound (v1.begin(), v1.end(), b[i]) - v1.begin();
    for (int i = min (m, n); i >= 1; -- i)
    {
        fill (ha.a, ha.a + N, 0);
        for (int j = 0; j < n; ++ j)
        {
            for (int t = 0; t < N; ++ t)
            F (ha.a[t], a[j], t); 
            if (j < i - 1) continue;
            v[j - i + 1] = ha;
            for (int t = 0; t < N; ++ t)
            F1 (ha.a[t], a[j - i + 1], t);
        }
        sort (v, v + (n - i + 1), myc);
        fill (ha.a, ha.a + N, 0);
        for (int j = 0; j < m; ++ j)
        {
            for (int t = 0; t < N; ++ t)
            F (ha.a[t], b[j], t);
            if (j < i - 1) continue;
            if (binary_search (v, v + (n - i + 1), ha, myc))
            {
                cout << i;
                exit (0);
            }
            for (int t = 0; t < N; ++ t)
            F (ha.a[t], b[j - i + 1], t);
        }
    }
    cout << 0;
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