/*
Code by b21
Time: 20:08 Sun 16/06/2019
*/

#include <bits/stdc++.h>

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mod1 = 1064368031;
const int mod2 = 960687317;
const int KZ = 1;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
void docfile()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (ifstream("test.inp"))
    {
       freopen("test.inp", "r", stdin);
       if (!aNs) freopen("test.out", "w", stdout);
       else freopen ("test.ans", "w", stdout);
    }
   else if (ifstream("808b.inp"))
    {
        freopen("808b.inp", "r", stdin);
        freopen("808b.out", "w", stdout);
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

int Id (int u, int v)
{
    return u * 5000 + v;
}

int id[2010];
int ma1[2010][2010];
int ma2[2010][2010];
long long ma3[2010][2010];
int ma4[2010][2010];
int ma5[2010][2010];
int ma6[2010][2010];
long long ma7[2010][2010];
int ma8[2010][2010];
int ma9[2010][2010];
long long ma10[2010][2010];
long long ma11[2010][2010];

struct Z
{
    int a, b, d, e, f, x, y;
    long long g, i, j, c;
    Z (){}
    Z (int A, int B, long long C, int D, int E, int F, long long G, int X, int Y, long long I, long long J)
    {
        a = A; b = B; c = C; d = D; e = E; f = F; g = G; x = X; y = Y;
    }
    bool operator < (const Z& h) const
    {
        if (a != h.a) return (a < h.a);
        if (b != h.b) return (b < h.b);
        if (c != h.c) return (c < h.c);
        if (d != h.d) return (d < h.d);
        if (e != h.e) return (e < h.e);
        if (f != h.f) return (f < h.f);
        if (g != h.g) return g < h.g;
        if (x != h.x) return x < h.x;
        if (y != h.y) return y < h.y;
        if (i != h.i) return i < h.i;
        return j < h.j;
    }
};


void enter()
{
    int n;
    cin >> n;
    map<int, int > mu, cnt;
    long long sol = 0;
    for (int i = 0; i < n; ++ i)
    {
        int u, v;
        cin >> u >> v;
        if (u > v) swap (u, v);
        if (!mu.count (Id (u, v))) mu[Id (u, v)] = mu.size() + KZ;
        sol += cnt [Id (u, v)];
        ++ cnt[Id (u, v)];
        id[i] = mu[Id (u, v)];
    }
    for (int i = 0; i < n; ++ i)
    {
        ma1[i][i] = id[i];
        ma2[i][i] = id[i];
        ma3[i][i] = 1ll * id[i] * id[i] * id[i] * id[i];
        ma4[i][i] = id[i];      
        ma5[i][i] = id[i];
        ma6[i][i] = id[i];
        ma7[i][i] = id[i];
        ma8[i][i] = id[i];
        ma9[i][i] = id[i];
        ma10[i][i] = id[i] * id[i];
        ma11[i][i] = 1ll * id[i] * id[i] * id[i];
    }
    for (int k = 1; k < n; ++ k)
    {
        map<Z, int> mu;
        for (int i = 0; i + k < n; ++ i)
        {
            int j = i + k;
            ma1[i][j] = ma1[i][j - 1] + id[j];
            ma2[i][j] = (1ll * id[j] * ma2[i][j - 1]) % mod;
            ma3[i][j] = ma3[i][j - 1] + (1ll * id[j] * id[j] * id[j] * id[j]);
            ma4[i][j] = (id[j] ^ ma4[i][j - 1]);
            ma5[i][j] = (1ll * id[j] * ma5[i][j - 1]) % mod2;
            ma6[i][j] = (1ll * id[j] * ma6[i][j - 1]) % mod1;
            ma7[i][j] = ma7[i][j - 1] * id[j];
            ma8[i][j] = max ( ma8[i][j - 1], id[j]);
            ma9[i][j] = min ( ma9[i][j - 1], id[j]);
            ma10[i][j] = ma10[i][j] + id[j] * id[j];
            ma11[i][j] = ma11[i][j] + (1ll * id[j] * id[j] * id[j]);
            sol += mu[Z (ma1[i][j], ma2[i][j], ma3[i][j], ma4[i][j], ma5[i][j], ma6[i][j], ma7[i][j], ma8[i][j], ma9[i][j], ma10[i][j], ma11[i][j])];
            ++ mu[Z (ma1[i][j], ma2[i][j], ma3[i][j], ma4[i][j], ma5[i][j], ma6[i][j], ma7[i][j], ma8[i][j], ma9[i][j], ma10[i][j], ma11[i][j])];
        }
    }
    cout << sol << "\n";
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
    cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}