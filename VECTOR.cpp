#include <bits/stdc++.h>

#define fn "test"
#define fn1 "VECTOR"

using namespace std;

const int mn = 1 * (int)(1e7) + 10;
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

int pr[mn];
vector<int> vpr;
int cn1[mn], cn2[mn];

void eros (const int& N)
{
    for (int i = 2; i * i <= N; ++ i)
    if (!pr[i])
    for (int j = i * i; j <= N; j += i)
    pr[j] = i;
    for (int i = 2; i <= N; ++ i)
    if (!pr[i])
    {
        pr[i] = i;
        vpr.emplace_back(i);
    }
}

void enter()
{
    int n, m;
    eros (10000000);
    cin >> n;
    for (int i = 0, x; i < n; ++ i)
    {
        cin >> x;
        while (x != 1)
        {
            ++ cn1[pr[x]];
            x /= pr[x];
        }
    }
    cin >> m;
    for (int i = 0, x; i < m; ++ i)
    {
        cin >> x;
        while (x != 1)
        {
            ++ cn2[pr[x]];
            x /= pr[x];
        }
    }
    vector<pair<int, char> > v;
    for (const int& i : vpr)
    {
        while (cn1[i] % 2) 
        {   
            v.emplace_back(i, 'D');
            v.emplace_back(i, 'D');
            v.emplace_back(i, 'W');
            ++ cn1[i];
        }
        while (cn1[i])
        {
            v.emplace_back(i, 'L');
            cn1[i] -= 2;
        }
    }
    for (const int& i : vpr)
    {
        while (cn2[i] % 4)
        {
            v.emplace_back(i, 'D');
            ++ cn2[i];
        }
        while (cn2[i])
        {
            v.emplace_back(i, 'W');
            v.emplace_back(i, 'W');
            v.emplace_back(i, 'L');
            cn2[i] -= 4;
        }
    }
    cout << v.size() << "\n";
    for (const auto& x : v)
    {
        cout << x.first << " " << x.second << "\n";
    }
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