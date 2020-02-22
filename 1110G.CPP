/*
Code by b21
Time: 15:15 Sun 10/11/2019
*/

#include <bits/stdc++.h>

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
   else if (ifstream("1110G.inp"))
    {
        freopen("1110G.inp", "r", stdin);
        freopen("1110G.out", "w", stdout);
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

string team[110];
bool ok[110][110];
int cn[30], cn1[30];
int n, m;

int Id (int i, int j)
{
    return (i - 1) * n + j - 1;
}

void enter()
{
    cin >> n >> m;
    deque<int> v;
    int s = m * n;
    int NumMatch = (m - 1) * n * m * n / 2;
    int MPR = m * n / 2;
    while (NumMatch % MPR) -- MPR;
    int R = NumMatch / MPR;
    for (int i = 1; i <= m; ++ i)
    for (int j = 1; j <= n; ++ j)
    {
        team[Id (i, j)].push_back((char)('A' + (i - 1)));
        team[Id (i, j)].push_back((char)('0' + j));
    }
    for (int i = 0; i < s; ++ i)
    for (int j = 0; j < s; ++ j)
    ok[i][j] = 0;
    for (int i = 1; i <= m; ++ i)
    for (int j = 1; j <= n; ++ j)
    for (int t = 1; t <= n; ++ t)
    ok[Id (i, j)][Id (i, t)] = 1;
    for (int i = 0; i < R; ++ i)
    {
        vector<int> v;
        int k = (2 * MPR) / m;
        int d = (2 * MPR) % m;
        int ma = 0;
        for (int i = 1; i <= n; ++ i)
        cn1[i] = cn[i];
        for (int j = 1; j <= m; ++ j)
        {
            ma = max (ma, cn[j]);
            for (int l = 1; l <= cn[j]; ++ l)
            v.emplace_back(Id (j, l));
            for (int l = n; l >= n - (k - cn[j]) + 1; -- l)
            v.emplace_back(Id (j, l));
            cn1[j] = n - (k - cn[j]);
        }
        for (int j = 1; j <= m; ++ j)
        if (cn[j] == ma && d) 
        {
            v.emplace_back(Id (j, n - (k - cn[j])));
            -- cn1[j];
            -- d;
        }
        for (int j = 1; j <= m; ++ j)
        if (cn[j] != ma && d) 
        {
            v.emplace_back(Id (j, n - (k - cn[j])));
            -- cn1[j];
            -- d;
        }
        for (int i = 1; i <= m; ++ i)
        cn[i] = cn1[i];
        sort (v.begin(), v.end());
        int x = 0, y = v.size() / 2;
        for (int j = 0; j < MPR; ++ j)
        {
            cout << team[x ++] << "-" << team[y ++] << " ";
        }
        cout << "\n";
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