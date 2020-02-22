#include <bits/stdc++.h>

#define fn "test"
#define fn1 "BANK"

using namespace std;

const int mn = 1 * (int)(1e2) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int n, m, a[mn], b[mn];
int lo[(1 << 20) + 10];
int f0[mm], f1[31][1010][1010], tr1[31][1010][1010];
int d[(1 << 10) + 10];
vector<int> e[(1 << 10) + 10];
int f2[2][(1 << 5) + 10][(1 << 10) + 10];
int tr2[2][(1 << 5) + 10][(1 << 10) + 10];
int v[32];

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

void enter()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i)
    cin >> a[i];
    for (int i = 1; i <= m; ++ i)
    cin >> b[i];
    // if (n == 1 && m <= 20)
    // {
    //     memset (f0, 0, sizeof (f0));
    //     for (int i = 0; i <= m; ++ i)
    //     lo[1 << i] = i;
    //     for (int i = 1; i < (1 << m); ++ i)
    //     {
    //         f0[i] = f0[i - (i & - i)] + b[lo[i & - i] + 1];
    //         if (f0[i] == a[1])
    //         {
    //             for (int j = 0; j < m; ++ j)
    //             cout << ((i >> j) & 1) << " ";
    //             return;
    //         }
    //     }
    //     cout << - 1;
    //     return;
    // }
    // if (n <= 2)
    // {
    //     if (n == 1) a[++ n] = 0;
    //     f1[0][0][0] = 1;
    //     for (int i = 1; i <= m; ++ i)
    //     for (int j = 0; j <= a[1]; ++ j)
    //     for (int k = 0; k <= a[2]; ++ k)
    //     {
    //         f1[i][j][k] = 0;
    //         if (f1[i - 1][j][k])
    //         {
    //             f1[i][j][k] = f1[i - 1][j][k];
    //             tr1[i][j][k] = 0;
    //         }
    //         if (j >= b[i] && f1[i - 1][j - b[i]][k])
    //         {
    //             f1[i][j][k] = 1;
    //             tr1[i][j][k] = 1;
    //         }
    //         if (k >= b[i] && f1[i - 1][j][k - b[i]])
    //         {
    //             f1[i][j][k] = 1;
    //             tr1[i][j][k] = 2;
    //         }
    //     }
    //     if (!f1[m][a[1]][a[2]])
    //     {
    //         cout << - 1;
    //         return;
    //     }
    //     int j = a[1], k = a[2];
    //     for (int i = m; i >= 1; -- i)
    //     {
    //         v[i] = tr1[i][j][k];
    //         if (tr1[i][j][k] == 1) j -= b[i]; else if (tr1[i][j][k] == 2) k -= b[i];
    //     }
    //     for (int i = 1; i <= m; ++ i)
    //     cout << v[i] << " ";
    //     return;
    // }
    if (n <= 10 && m <= 10)
    {
        int n1 = n / 2, n2 = n - n1;
        for (int i = 0; i <= max (max (n1, n2), m); ++ i)
        lo[1 << i] = i;
        for (int i = 1; i < (1 << m); ++ i)
        d[i] = d[i - (i & - i)] + b[lo[i & - i] + 1];
        for (int i = 0; i < (1 << m); ++ i)
        for (int j = 0; j <= i; ++ j)
        if ((i | j) <= i) e[i].push_back(j);
        for (int i = 0; i < (1 << n1); ++ i)
        for (int j = 0; j < (1 << m); ++ j)
        {
            if (!i && !j)
            f2[0][i][j] = 1;
            else
            f2[0][i][j] = 0;
            for (int k : e[j])
            if (d[k] == a[lo[i & - i] + 1] && f2[0][i - (i & - i)][j - k])
            {
                f2[0][i][j] = 1;
                tr2[0][i][j] = k;
            }
        }
        for (int i = 0; i < (1 << n2); ++ i)
        for (int j = 0; j < (1 << m); ++ j)
        {
            if (i == 0 && j == 0)
            f2[1][i][j] = 1;
            else
            f2[1][i][j] = 0;
            for (int k : e[j])
            if (d[k] == a[n1 + lo[i & - i] + 1] && f2[1][i - (i & - i)][j - k])
            {
                f2[1][i][j] = 1;
                tr2[1][i][j] = k;
            }
        }
        for (int j = 0; j < (1 << m); ++ j)
        for (int k = 0; k < (1 << m); ++ k)
        if (f2[0][(1 << n1) - 1][j] && f2[1][(1 << n2) - 1][k] && (j & k) == 0)
        {
            for (int i1 = (1 << n1) - 1; i1; i1 -= i1 & - i1)
            {
                for (int d = tr2[0][i1][j]; d; d -= d & - d)
                v[lo[d & - d]] = lo[i1 & - i1] + 1;
                j -= tr2[0][i1][j];
            }
            for (int i2 = (1 << n2) - 1; i2; i2 -= i2 & - i2)
            {
                for (int d = tr2[1][i2][k]; d; d -= d & - d)
                v[lo[d & - d]] = n1 + lo[i2 & - i2] + 1;
                k -= tr2[1][i2][k];
            }
            for (int i = 0; i < m; ++ i)
            cout << v[i] << " ";
            return;
        }
        cout << - 1;
        return;
    }
}

void solve()
{
    cout << "\n";
}

void print_result()
{

}

int main()
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