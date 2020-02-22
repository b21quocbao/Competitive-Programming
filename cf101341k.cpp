#include <bits/stdc++.h>
#define int long long

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 2 * (int)(1e5) + 10;
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

int a[mn], b[mn], c[mn], id[mn];


struct ZE
{
    int x, y, z;
    ZE (){
        x = 0; y = 0; z = 0;
    }
    ZE (int X, int Y, int Z)
    {
        x = X; y = Y; z = Z;
    }
    bool operator > (const ZE& a) const
    {
        if (x != a.x) return x > a.x;
        return y < a.y;
    }
};

ZE max (const ZE& a, const ZE& b)
{
    return (a > b ? a : b);
}

ZE bi[2 * mn];
int tr[mn];

ZE db (int x)
{
    ZE sol = {0, 0, 0};
    for (; x >= 1; x -= x & - x)
    sol = max (sol, bi[x]);
    return sol;
}

void ub (int x, ZE r)
{
    for (; x < 2 * mn; x += x & - x)
    bi[x] = max (bi[x], r);
}

void enter()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 1; i <= n; ++ i)
    {
        cin >> a[i] >> b[i] >> c[i];
        id[i] = i;
        v.emplace_back(a[i]);
        v.emplace_back(b[i]);
    }
    sort (v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for (int i = 1; i <= n; ++ i)
    {
        a[i] = lower_bound (v.begin(), v.end(), a[i]) - v.begin() + 1;
        b[i] = lower_bound(v.begin(), v.end(), b[i]) - v.begin() + 1;
    }
    sort (v.begin(), v.end());
    sort (id + 1, id + n + 1, [](int i, int j)
         {
             return b[i] < b[j];
         });
    ZE sol;
    for (int i = 1; i <= n; ++ i)
    {
        int j = id[i];
        auto r = db (a[j]);
        r.x += c[j];
        r.y += (v[b[j] - 1] - v[a[j] - 1]);
        tr[j] = r.z;
        r.z = j;
        sol = max (sol, r);
        ub (b[j], r);
    }
    int x = sol.z;
    vector<int> solv;
    while (x)
    {
        solv.emplace_back (x);
        x = tr[x];
    }
    sort (solv.begin(), solv.end());
    cout << solv.size() << " " << sol.x << " " << sol.y << " " << "\n";
    for (int i : solv)
    cout << i << " ";
}

void solve()
{

}

void print_result()
{

}

main()
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
