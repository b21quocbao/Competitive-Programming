/*
Code by b21
Time: 22:23 Thu 17/10/2119
*/

#include <bits/stdc++.h>
#define int long long

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
    if (ifstream("test.inp"))
    {
       freopen("test.inp", "r", stdin);
       if (!aNs) freopen("test.out", "w", stdout);
       else freopen ("test.ans", "w", stdout);
    }
   else if (ifstream("1710c.inp"))
    {
        freopen("1710c.inp", "r", stdin);
        freopen("1710c.out", "w", stdout);
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

bool ok[2110];
int d[2110][2110], sl[2110][2110], f[2110][2110];
int scs (int x)
{
    int cnt = 0;
    while (x)
    {
        x /= 10;
        ++ cnt;
    }
    return cnt;
}

int F (int x, int d)
{
    if (!x) return 1;
    if (d > 2100) return 0;
    if (f[x][d] != - 1) return f[x][d];
    f[x][d] = 0;
    if (!ok[d])
    f[x][d] += F (x - d, d + 1);
    f[x][d] += F (x, d + 1);
}

int Fu (int x, int d)
{
    return F (x - d, d + 1);
}

void write (int sl, int x, int d)
{
    if (!sl) return;
    if (!x) return;
    if (!d) 
    {
        cout << "[";
        -- sl;
    }
    else
    {
        vector<int> v;
        while (x)
        {
            v.emplace_back(x % 10);
            x /= 10;
        }
        reverse (v.begin(), v.end());
        for (int i : v)
        {
            cout << i;
            -- sl;
            if (!sl) return;
        }
        cout << ",";
        -- sl;
        if (!sl) return;
        cout << " ";
        -- sl;
        if (!sl) return;
    }
    if (!sl) return;
    for (int i = d + 1; i <= x; ++ i)
    if (F (x - i, i + 1))
    write (sl, x - i, i);
    if (!d)
    {
        cout << "]";
        -- sl;
    }
}

void enter()
{
    for (int i = 2; i <= trunc (sqrt (2100)); ++ i)
    if (!ok[i])
    for (int j = i * i; j <= 2100; j += i)
    ok[j] = 1;
    long long s = 0;
    long long a, b;
    cin >> a >> b;
    memset (f, - 1, sizeof (f));
    for (int i = 2; i <= 2100; ++ i)
    {
        if (!ok[i]) 
        {
            d[i][i] = scs(i) + 4;
            sl[i][i] = 1;
        }
        for (int j = 2; j < i; ++ j)
        if (!ok[j])
        {
            sl[i][j] += sl[i - j][min (i - j, j - 1)];
            d[i][j] += d[i - j][min (i - j, j - 1)] + sl[i - j][min (i - j, j - 1)] * (scs(j) + 2);
        }
        for (int j = 2; j <= i; ++ j)
        {
            d[i][j] += d[i][j - 1];
            sl[i][j] += sl[i][j - 1];
        }
        s += d[i][i];
        if (s < a) continue;
        if (s <= b) write (s - a + 1, i, 0);
        else write (b - a + 1,i, 0);
        a = s + 1;
        if (s >= b) return;
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