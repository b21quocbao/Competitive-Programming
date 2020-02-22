#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 3 * (int)(1e3) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int ok[mn], cnt;
int ma[mn];
int lv[mn];
vector<int> e[mn];
vector<int> v;
int sol = 0;
bool dx[mn];
int cn[3 * mn];
int s[mn];
int a[mn][30];
int id[30];

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
    int n;
    cin >> n;
    for (int i = 0; i < n; ++ i)
    for (int j = 0; j < 3; ++ j)
    {
        string s;
        cin >> s;
        for (char c : s)
        ++ a[i][(c - 'A') + 1];
    }
    int k;
    cin >> k;
    for (int i = 1; i <= 'Z' - 'A' + 1; ++ i)
    cn[i] = k;
    for (int i = 1; i <= 26; ++ i)
    s[i] = s[i - 1] + cn[i];
    for (int i = 0; i < n; ++ i)
    {
        v.emplace_back(i); 
        int ma = 0;
        for (int j = 1; j <= 26; ++ j) 
        ma = max (ma, a[i][j]);
        // cerr << ma << "\n";
        for (int j = 1; j <= 26; ++ j)
        if (a[i][j] == ma) 
        {
            // cerr << i << " " << j << "\n";
            for (int l = s[j - 1]; l < s[j]; ++ l)
            {
                e[i].emplace_back(l);
            }
            
        }
    }
}

bool bfs ()
{
    memset (lv, 0, sizeof (lv));
    queue<int> qu;
    for (int i : v)
    for (int j : e[i])
    if (!lv[j])
    {
        lv[j] = 1;
        qu.push (j);
    }
    bool ok = 0;
    while (qu.size())
    {
        int U = qu.front(); qu.pop();
        int u = ma[U];
        if (!u) return 1;
        for (int v : e[u])
        if (!lv[v])
        {
            lv[v] = lv[U] + 1;
            qu.push (v);
        }
    }
    return 0;
}

bool dfs (int u, int d)
{
    for (int v : e[u])
    if (lv[v] == d)
    {
        if (!ma[v] || dfs (ma[v], d + 1))
        {
            ma[v] = u;
            return 1;
        } 
    }
    return 0;
}

void solve()
{
    // cerr << "dmm\n";
    while (bfs ())
    {
        ++ cnt;
        for (int i = v.size() - 1; i >= 0; -- i)
        {
            if (dfs (v[i], 1))
            {
                ++ sol;
                v[i] = v.back();
                v.pop_back();
            }
        }
    }
    cout << sol;
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