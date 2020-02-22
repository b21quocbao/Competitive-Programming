#include <bits/stdc++.h>

#define fn "test"
#define fn1 "FGARDEN"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e2) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

struct Z   
{
    int i, j, k, l;
    Z (){}
    Z (int I, int J, int K, int L)
    {
        i = I; j = J; k = K; l = L;
    }
};

vector<Z > v;
int tt, ntest = 1;
vector<int> x, y;
int xz, yz;
int x2[mm], y2[mm], x3[mm], y3[mm];
int ok[6][mm][mm], pr[mm][mm];
bool ok0[mm][mm][mm][mm];
int m, n, a, b, sol;

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

inline int Idx (int i)
{
    return lower_bound(x.begin(), x.end(), i) - x.begin() + 1;
}

inline int Idy (int i)
{
    return lower_bound(y.begin(), y.end(), i) - y.begin() + 1;
}

void preok()
{
    for (int i = 0; i < n; ++ i)
    {
        x2[i] = Idx (x2[i]); x3[i] = Idx (x3[i]);
        y2[i] = Idy (y2[i]); y3[i] = Idy (y3[i]);
        ++ ok[1][x2[i]][y2[i]];
        ++ ok[2][x2[i]][y3[i]];
        ++ ok[3][x3[i]][y2[i]];
        ++ ok[4][x3[i]][y3[i]];
    }
    for (int i = 1; i <= xz; ++ i)
    for (int j = 1; j <= yz; ++ j)
    {
        ok[1][i][j] += ok[1][i - 1][j] + ok[1][i][j - 1] - ok[1][i - 1][j - 1];
        ok[2][i][j] += ok[2][i - 1][j] + ok[2][i][j - 1] - ok[2][i - 1][j - 1];
        ok[3][i][j] += ok[3][i - 1][j] + ok[3][i][j - 1] - ok[3][i - 1][j - 1];
        ok[4][i][j] += ok[4][i - 1][j] + ok[4][i][j - 1] - ok[4][i - 1][j - 1];
    }
}

void ma (int a, int b, int c, int d)
{
    x.emplace_back(a);
    x.emplace_back(b);
    y.emplace_back(c);
    y.emplace_back(d);   
}

void sor()
{
    sort (x.begin(), x.end());
    x.resize(unique(x.begin(), x.end()) - x.begin());
    sort(y.begin(), y.end());
    y.resize(unique(y.begin(), y.end()) - y.begin());
}

inline bool kt1 (int i1, int j1, int i, int j, int k, int l)
{
    return (i1 >= i && i1 <= k && j1 >= j && j1 <= l);
}

void cnh (int i, int j, int k, int l, int i1, int j1, int k1, int l1)
{
    int r1 = (x[k - 1] - x[i - 1]) * (y[l - 1] - y[j - 1]);
    int r2 = (x[k1 - 1] - x[i1 - 1]) * (y[l1 - 1] - y[j1 - 1]);
    if (r1 + r2 <= sol) return;
    sol = r1 + r2;
    v.clear();
    v.emplace_back(i - 1, j - 1, k - 1, l - 1);
    v.emplace_back(i1 - 1, j1 - 1, k1 - 1, l1 - 1);
}


void cnh1 (int i, int j, int k, int l)
{
    int r1 = (x[k - 1] - x[i - 1]) * (y[l - 1] - y[j - 1]);
    if (r1 <= sol) return;
    sol = r1;
    v.clear();
    v.emplace_back(i - 1, j - 1, k - 1, l - 1);
    if (m == 2)
    v.emplace_back(0, 0, 0, 0);
}

bool kt (int i, int j, int k, int l, int i1, int j1)
{
    return ((i1 <= k && j1 >= j && j1 < l));
}

bool kt2 (int i, int j, int k, int l, int i1, int j1, int k1, int l1)
{
    if (!kt1 (i1, j1, i, j, k - 1, l - 1) && !kt1 (i1, l1, i, j + 1, k - 1, l))
    if (!kt1 (k1, j1, i + 1, j, k, l - 1) && !kt1 (k1, l1, i + 1, j + 1, k, l))
    return 1;
    return 0;
}

void dp ()
{
    for (int i = 1; i <= xz; ++ i)
    for (int j = 1; j <= yz; ++ j)
    for (int k = i + 1; k <= xz; ++ k)
    for (int l = j + 1; l <= yz; ++ l)
    {
        ok0[i][j][k][l] = 1;
        int i1 = i, j1 = j, k1 = k, l1 = l;
        for (int t = 0; t < n; ++ t)
        {
            int i = x2[t], j = y2[t], k = x3[t], l = y3[t];
            if (kt2 (i1, j1, k1, l1, i, j, k, l))
            if (kt2 (i, j, k, l, i1, j1, k1, l1))
            continue;
            ok0[i1][j1][k1][l1] = 0;
            break;
        }
    }
    cerr << kt2 (1, 1, )
    for (int i = 1; i <= xz; ++ i)
    for (int j = 1; j <= yz; ++ j)  
    for (int k = i + 1; k <= xz; ++ k)
    for (int l = j + 1; l <= yz; ++ l)
    if (ok0[i][j][k][l])
    {
        cnh1 (i, j, k, l);
        if (m == 1) continue;
        for (int i1 = i + 1; i1 <= xz; ++ i1)
        for (int j1 = 1; j1 <= yz; ++ j1)
        for (int k1 = i1 + 1; k1 <= xz; ++ k1)
        for (int l1 = j1 + 1; l1 <= yz; ++ l1)
        if (ok0[i1][j1][k1][l1])
        if (kt2 (i1, j1, k1, l1, i, j, k, l))
        if (kt2 (i, j, k, l, i1, j1, k1, l1))
        cnh (i, j, k, l, i1, j1, k1, l1);
    }
}

void enter()
{
    v.emplace_back(0, 0, 0, 0);
    if (m == 2)
    v.emplace_back(0, 0, 0, 0);
    cin >> n >> m;
    if (!m) return;
    cin >> a >> b;
    ma (0, a, 0, b);
    for (int i = 0; i < n; ++ i)
    {
        cin >> x2[i] >> y2[i];
        cin >> x3[i] >> y3[i];
        ma (x2[i], x3[i], y2[i], y3[i]);
    }
    sor();
    xz = x.size(), yz = y.size();
    dp();
}

void solve()
{
    // cerr << sol;
    for (auto i : v)
    cout << x[i.i] << " " << y[i.j] << " " << x[i.k] << " " << y[i.l] << "\n";
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