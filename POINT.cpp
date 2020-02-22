#include <bits/stdc++.h>

#define fn "test"
#define fn1 "POINT"

using namespace std;

const int mn = 2 * (int)(1e3) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
pair<int, int> a[mn];

struct Z
{
    int kc, x, y, i, j;
};

Z v[mn * mn], v1[mn * mn];
int f[mn];

bool cmp1 (Z a, Z b)
{
    if (a.i != b.i)
    return (a.i < b.i);
    if (a.x != b.x) 
    return (a.x < b.x);
    if (a.y != b.y)
    return (a.y < b.y);
    return (a.kc < b.kc);
}

bool cmp2 (Z a, Z b)
{
    return (a.kc > b.kc);
}

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

int sqr (int x)
{
    return x * x;
}

int Kc (int i, int j)
{
    return (sqr (a[i].first - a[j].first) + sqr (a[i].second - a[j].second));
}

void enter()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++ i)
    cin >> a[i].first >> a[i].second;
    sort (a, a + n);
    int cn = 0, cn1 = 0;
    for (int i = 0; i < n; ++ i)
    for (int j = i + 1; j < n; ++ j)
    {
        Z k;
        k.i = i; k.j = j;
        k.x = a[i].first - a[j].first;
        k.y = a[i].second - a[j].second;
        int g = __gcd (k.x, k.y);
        k.x /= g; k.y /= g;
        if (k.x < 0)
        {
            k.x = - k.x;
            k.y = - k.y;
        }
        k.kc = Kc (i, j);
        v[cn ++] = k;
    }
    sort (v, v + cn, cmp1);
    for (int i = 0; i < cn; ++ i)
    if (!i || (!(v[i].x == v[i - 1].x && v[i].y == v[i - 1].y && v[i].i == v[i - 1].i)))
    v1[cn1 ++] = v[i];
    sort (v1, v1 + cn1, cmp2);
    vector<pair<int, int> > V;
    int sol = 0;
    for (int i = 0; i < n; ++ i)
    f[i] = 1;
    for (int i = 0; i < cn1; ++ i)
    {
        V.push_back(make_pair(v1[i].i, f[v1[i].j] + 1));
        V.push_back(make_pair(v1[i].j, f[v1[i].i] + 1));
        if ((i == cn1 - 1) || (v1[i].kc != v1[i + 1].kc))
        {
            for (int i = 0; i < V.size(); ++ i)
            {
                f[V[i].first] = max (f[V[i].first], V[i].second);
                sol = max (sol, f[V[i].first]);
            }
            V.clear();
        }
    }
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