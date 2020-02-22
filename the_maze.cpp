#include <bits/stdc++.h>
 
#define fn "test"
#define fn1 ""
 
using namespace std;
 
const int mn = 1 * (int)(1e5) + 10;
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
 
string s[60];
double r[mn], u[mn], l[mn], d[mn];
vector<pair<int, int> > S, T; 
bool ok[52][52];
int hx[4] = {0, 0, 1, - 1};
int hy[4] = {1, - 1, 0, 0};
int n;
 
bool kt (int x, int y)
{
    return (x >= 0 && y >= 0 && x < n && y < n && s[x][y] != 'X');
}
 
bool Bfs ()
{
    auto qu = S;
    memset (ok, 0, sizeof (ok));
    for (auto x : qu)
    ok[x.first][x.second] = 1;
    while (qu.size())
    {
        int x = qu.back().first, y = qu.back().second;
        qu.pop_back();
        if (s[x][y] == 'B') continue;
        for (int h = 0; h < 4; ++ h)
        {
            int X = x + hx[h], Y = y + hy[h];
            if (!kt (X, Y)) continue;
            if (ok[X][Y]) continue;
            ok[X][Y] = 1;
            qu.emplace_back(X, Y);
        }
    }
    for (auto x : T)
    if (!ok[x.first][x.second]) return 0;
    return 1;
}

#define ll long long

const ll rm = RAND_MAX + 1;

ll Ran (ll a, ll b)
{
    ll x = a + ((ll)rand() * rm * rm * rm + (ll)rand() * rm * rm + (ll)rand() * rm + (ll)rand()) % (b - a + 1);
    return x;
}
 
void enter()
{
    int X, Y;
    srand(time(nullptr));
    cin >> n >> X >> Y;
    X = Ran (0, X);
    cin.ignore();
    for (int i = 0; i < n; ++ i)
    getline (cin, s[i]);
    vector<pair<int, int> > v;
    for (int i = 0; i < n; ++ i)
    for (int j = 0; j < n; ++ j)
    if (s[i][j] == '.') 
    v.emplace_back(i, j);
    else if (s[i][j] == 'A')
    S.emplace_back(i, j);
    else if (s[i][j] == 'B')
    T.emplace_back(i, j);
    random_shuffle (v.begin(), v.end());
    for (int i = 0; i < 100000; ++ i)
    cin >> r[i] >> u[i] >> l[i] >> d[i];
    for (auto x : v)
    if (X)
    {
        s[x.first][x.second] = 'X';
        -- X;
        
    }
    for (int i = 0; i < n; ++ i)
    cout << s[i] << "\n";
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
