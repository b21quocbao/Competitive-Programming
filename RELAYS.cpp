#include <bits/stdc++.h>

#define fn "test"
#define fn1 "RELAYS"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int u[mm], v[mm], w[mm];
vector<int> V;

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

class Mat
{
    public:
    int m, n;
    vector<vector<int> > a; 
    Mat (int M, int N)
    {
        m = M;
        n = N;
        a.resize(m, vector<int> (n, (int)(1e9)));
    }
    ~Mat()
    {
        a.clear();
    }

    friend Mat operator * (Mat a, Mat b)
    {
        Mat c (a.m, b.n);
        //c.a = b.a;
        for (int i = 0; i < a.m; ++ i)
        for (int j = 0; j < b.n; ++ j)
        for (int k = 0; k < a.n; ++ k)
        {
            c.a[i][j] = min (c.a[i][j], a.a[i][k] + b.a[k][j]);
        }
        return c;
    }

    friend Mat po (Mat a, int n)
    {
        if (n == 1) return a;
        auto b = po (a, n >> 1);
        b = b * b;
        return (n % 2 ? b * a : b);
    }
};

void enter()
{
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    V.emplace_back(s); V.emplace_back(t);
    for (int i = 0; i < m; ++ i)
    {
        cin >> w[i] >> u[i] >> v[i];
        V.emplace_back(u[i]);
        V.emplace_back(v[i]);
    }
    sort(V.begin(), V.end());
    V.resize(unique(V.begin(), V.end()) - V.begin());
    Mat ch (V.size(), V.size());
    Mat g (V.size(), 1);
    g.a[lower_bound(V.begin(), V.end(), s) - V.begin()][0] = 0;
    for (int i = 0; i < m; ++ i)
    {
        u[i] = lower_bound(V.begin(), V.end(), u[i]) - V.begin();
        v[i] = lower_bound(V.begin(), V.end(), v[i]) - V.begin();
        if (u[i] == v[i]) continue;
        ch.a[u[i]][v[i]] = min (ch.a[u[i]][v[i]], w[i]);
        ch.a[v[i]][u[i]] = min (ch.a[v[i]][u[i]], w[i]);
    }
    ch = po (ch, n);
    g = ch * g;
    cout << g.a[lower_bound(V.begin(), V.end(), t) - V.begin()][0];
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