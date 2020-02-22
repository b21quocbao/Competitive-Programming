/*
Code by b21
Time: 11:06 Sun 13/10/2019
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
   else if (ifstream("vnpc19c.inp"))
    {
        freopen("vnpc19c.inp", "r", stdin);
        freopen("vnpc19c.out", "w", stdout);
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

int r[110], s[110];
int t[110][110][110];
bool ok[110];

void enter()
{
    int m, n, p;
    cin >> m >> n >> p;
    for (int i = 1; i <= m; ++ i)
    cin >> s[i];
    for (int i = 1; i <= n; ++ i)
    cin >> r[i];
    for (int i = 1; i <= m; ++ i)
    if (p % s[i]) s[i] = p / s[i] + 1;
    else s[i] = p / s[i];
    sort (s + 1, s + m + 1, greater<int>());
    sort (r + 1, r + n + 1);
    int sol = 0;
    long long inf = 1, sup = (long long)(1e15); 
    // inf = sup = 29;
    while (inf <= sup)
    {
        long long mid = (inf + sup) >> 1;
        int cnt = 0, re;
        for (int i = 1; i <= m; ++ i)
        {
            int res = mid;
            int N = 0, dc, dd;
            for (int j = n; j >= 1; -- j)
            if (!ok[j])
            {
                if ((!N) && (r[j] + s[i] > res)) continue;
                if (!N) 
                {
                    N = j;
                    dc = r[j] + s[i];
                    dd = r[j];
                    ok[j] = 1;
                    ++ cnt;
                    re = r[j];
                    continue;
                }
                if (r[j] + s[i] > dd && dc + r[j] + s[i] - dd <= res)
                {
                    dc += r[j] + s[i] - dd;
                    dd = r[j];
                    ok[j] = 1;
                    ++ cnt;
                }
                else if (r[j] + s[i] <= dd)
                {
                    dd = r[j];
                    res = re;
                    dc = r[j] + s[i];
                    ok[j] = 1;
                    ++ cnt;
                }
                else
                {
                    res = re;
                    N = 0;
                }
                re = r[j];
            }
        }
        for (int i = 1; i <= n; ++ i)
        ok[i] = 0;
        if (cnt == n)
        {
            sol = mid;
            sup = mid - 1;
        }
        else inf = mid + 1;
    }
    cout << sol - 1;
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