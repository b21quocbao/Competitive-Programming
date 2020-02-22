#include <bits/stdc++.h>

#define int int64_t
#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int x[mm], y[mm];
struct Z
{
    long long x;
    int y, z;
    long long t;
};
int n;


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

bool operator < (Z a, Z b)
{
    if (a.x != b.x)
    return (a.x < b.x);
    if (a.y != b.y)
    return (a.y < b.y);
    if (a.z != b.z)
    return (a.z < b.z);
    return (a.t < b.t);
}

long long sqr (int n)
{
    return 1ll * n * n;
}

void enter()
{
    cin >> n;
    for (int i = 0; i < n; ++ i)
    {
        cin >> x[i] >> y[i];
    }   
    vector<Z> v;
     
    for (int i = 0; i < n; ++ i)
    for (int j = 0; j < i; ++ j)
    {
        int a = y[i] - y[j];
        int b = x[j] - x[i];
        int r = __gcd(a, b);
        a /= r;
        b /= r;
        if (b < 0)
        {
            a = - a;
            b = - b;
        }
        Z re;
        re.x = sqr (y[i] - y[j]) + sqr (x[j] - x[i]);
        re.y = a;
        re.z = b;
        re.t = -1ll * a * x[i] - 1ll * b * y[i];
        v.push_back(re);
    }
    int cn = 1;
    long long sol = 0;
    sort (v.begin(), v.end());
    for (int i = 0; i < v.size(); ++ i)
    {
        if (!i) continue;
        if (v[i].x == v[i - 1].x && v[i].y == v[i - 1].y && v[i].z == v[i - 1].z)
        {
            sol += cn;
            if (cn)
            if (v[i].t == v[i - 1].t) -- sol;
            ++ cn;
        }
        else cn = 1;
    }
    cout << sol / 2 << "\n";
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
    cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}