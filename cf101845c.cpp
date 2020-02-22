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
int f[410][410];
bool ok[410];

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
    string s1, s2;
    int n, sol = 0;
    cin >> s1 >> s2;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; ++ i)
    {
        char c1, c2;
        int d;
        cin >> c1 >> c2 >> d;
        if (!ok[(int)c1])
        {
            ok[(int)c1] = 1;
            v.emplace_back((int)c1);
        }
        if (!ok[(int)c2])
        {
            ok[(int)c2] = 1;
            v.emplace_back((int)c2);
        }
        if (f[(int)c1][(int)c2])
        f[(int)c1][(int)c2] = min (f[(int)c1][(int)c2], d);
        else
        f[(int)c1][(int)c2] = d;
    }
    for (int k : v)
    for (int i : v)
    for (int j : v)
    if (f[i][k] && f[k][j])
    {
        if (!f[i][j]) f[i][j] = f[i][k] + f[k][j];
        else
        f[i][j] = min (f[i][j], f[i][k] + f[k][j]);
    }
    for (int i = 0; i < s1.size(); ++ i)
    {
        if (s1[i] == s2[i]) continue;
        if (!f[(int)(s1[i])][(int)(s2[i])])
        {
            cout << - 1;
            return;
        }
        else
        sol += f[(int)(s1[i])][(int)(s2[i])];
        cerr << sol << "\n";
    }
    cout << sol;
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