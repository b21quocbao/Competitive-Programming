#include <bits/stdc++.h>

#define fn "test"
#define fn1 "HAITI"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int h[100], ids[100], id[100];
pair<int, int> f[32][32][10010];
long long sol = 0;
long long s[110];

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

// 6 7 7
// 20 3
// 2 9 9
// 20 / 3
// 9

void ph (int a, int b, int m, long long& sol, bool ok, bool Ok)
{
    if (a == b) return;
    int n = b - a;
    int I = f[a][b][m].first;
    int K = f[a][b][m].second;
    long long rsol = (long long )(1e15);
    if (!K && !I)
    {
        for (int i = 0; i < n; ++ i)
        for (int k = m / (n - i); k && (k * i >= m - (n - i) * k); -- k)
        {
            long long res = 0;
            ph (a, a + i, m - (n - i) * k, res, 0, 0);
            res += 1ll * (s[a + i] - s[a]) * (b - a - i);
            if (res <= rsol)
            {
                rsol = res;
                I = i;
                K = k;
            }
        }
        f[a][b][m] = {I, K};
    }
    if (Ok) 
    {
        ph (a, b, m, sol, 1, 0);
        return;
    }
    if (!ok) 
    {
        sol += rsol;
        return;
    }
    for (int i = I; i <= I; ++ i)
    for (int k = K; k <= K; ++ k)
    {
        ph (a, a + i, m - (n - i) * k, sol, 1, 0);
        sol += 1ll * (s[a + i] - s[a]) * (b - a - i);
        for (int j = a + i; j < b; ++ j)
        ids[id[j]] = k;
    }
}

void enter()
{
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; ++ i)
    {
        cin >> h[i];
        id[i] = i;
    }
    sort (id, id + m, [](int i, int j)
         {
             return h[i] < h[j];
         });
    for (int i = 1; i <= m; ++ i)
    s[i] = s[i - 1] + h[id[i - 1]];
    ph (0, m, n, sol, 0, 1);   
    cout << sol << "\n";
    for (int i = 0; i < m; ++ i)
    cout << ids[i] << " ";
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