#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 5 * (int)(1e5) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int tg[mm][26], tg1[mm][26];
int s[26], s1[26];
int te2[mm];
int ne[mm][26];
int a[mm];
int ti, cn;
string S[mn];
int r, r1, sol;

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

void ad (string s)
{
    int r = 0;
    ++ a[0];
    for (char c : s)
    {
        if (!ne[r][c - 'a'])
        ne[r][c - 'a'] = cn ++;
        r = ne[r][c - 'a'];
        ++ a[r];
    }
}

void process (int u)
{
    for (int j = 0; j < 26; ++ j)
    {
        if (ne[u][j]) 
        process (ne[u][j]);
        if (!j) s[j] = 0;
        else 
        {
            s[j] = s[j - 1] + (ne[u][j - 1] ? a[ne[u][j - 1]] : 0);
            tg[u][j] = s[j];
        }
    }
    for (int j = 25; j >= 0; -- j)
    {
        if (j == 25) s1[j] = 0;
        else 
        {
            s1[j] = s1[j + 1] + (ne[u][j + 1] ? a[ne[u][j + 1]] : 0);
            tg1[u][j] = s1[j];
        }
    }
}

void dfs (int u, string s, int j)
{
    if (j == s.size()) return;
    dfs (ne[u][s[j] - 'a'], s, j + 1);
    r += tg[u][s[j] - 'a'];
    r1 += tg1[u][s[j] - 'a'];
    sol = min (sol, r + j + 1);
    sol = min (sol, r1 + 1 + j + 1);
}

void init (int u)
{
    a[u] = 0;
    for (int i = 0; i < 26; ++ i)
    if (ne[u][i])
    {
        init (ne[u][i]);
        ne[u][i] = 0;
    }
}

void enter()
{
    ++ ti;
    cn = 1;
    int n;
    cin >> n;
    init (0);
    getline (cin, S[0]);
    for (int i = 0; i < n; ++ i)
    {
        getline (cin, S[i]);
        ad (S[i]);
    }
    process (0);
    for (int i = 0; i < n; ++ i)
    {
        r = 0, r1 = 0, sol = INT_MAX;
        dfs (0, S[i], 0);
        cout << sol << " ";
    }
    cout << "\n";
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
    cin>>ntest;
    getline (cin, S[0]);
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}