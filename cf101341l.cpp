#include <bits/stdc++.h>
#define int long long
#define double long double

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

#define pd pair<double, double>

inline bool Kt (const pd& a, const pd& b, const pd& c) 
{
    return (a.second - b.second) / (b.first - a.first) > (b.second - c.second) / (c.first - b.first);
}

double S (int x, const pd& a)
{
    return x * a.first + a.second;
}

int id[mn], id1[mn], x[mn], sol[mn], c[mn];

void enter()
{
    int n = 0, m, N;
    cin >> N;
    vector<pd> v(N + 1);
    int r = - 1, I;
    vector<int> V;
    double mo = 1;
    for (int i = 1; i <= N; ++ i)
    {
        int a, b;
        cin >> a >> b;
        if (a == b)
        {
            if (a > r)
            {
                r = a;
                I = i;
            }
            continue;
        }
        ++ n;
        id[n] = n;
        v[n] = {- mo / (b - a), mo * b / (b - a)};
        c[n] = i;
    }
    sort (id + 1, id + n + 1, [&](int i, int j)
         {
             return v[i] < v[j];
         });
    for (int j = 1; j <= n; ++ j)
    {
        int i = id[j];
        while (V.size() >= 2 && Kt (v[V[V.size() - 2]], v[V.back()], v[i]))
        V.pop_back();
        V.emplace_back(i);
    }
    cin >> m;
    for (int i = 0; i < m; ++ i)
    {
        cin >> x[i];
        id1[i] = i;
    }
    sort (id1, id1 + m, [](int i, int j)
         {
             return x[i] < x[j];
         });
    int cur = 0;
    for (int j = 0; j < m; ++ j)
    {
        int i = id1[j];
        if (r >= x[i])
        {
            sol[i] = I;
            continue;
        }
        if (!V.size())
        {
            sol[i] = 1;
            continue;
        }
        while (cur + 1 < V.size() && S (x[i], v[V[cur + 1]]) > S (x[i], v[V[cur]])) ++ cur;
        sol[i] = c[V[cur]];
    }
    for (int i = 0; i < m; ++ i)
    {
        cout << sol[i] << " ";
    }
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