#include <bits/stdc++.h>

#define fn "test"
#define fn1 "GROUP"

using namespace std;

const int mn = 10 * (int)(1e3) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
bool ok[mn];
int cn[mn], l[mn][2];
vector<int> d[mn];
bool fi[mn];

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
    int n, k;
    cin >> n >> k;
    cin.ignore();
    unordered_map<int, int> mu, mu1;
    for (int i = 0; i < n; ++ i)
    {
        string s;
        getline (cin, s);
        int ha = 0, ha1 = 0;
        for (int i = 0; i < k; ++ i)
        ha = (26ll * ha  + (s[i] - 'A')) % mod;
        for (int i = s.size() - k; i < s.size(); ++ i)
        ha1 = (26ll * ha1 + (s[i] - 'A')) % mod;
        if (mu.find (ha) == mu.end())
        mu[ha] = mu.size();
        if (mu1.find (ha1) == mu1.end())
        mu1[ha1] = mu1.size();
        d[mu[ha]].emplace_back (i);
        d[mu1[ha1] + n].emplace_back(i);
        ++ cn[mu[ha]];
        ++ cn[mu1[ha1] + n];
        l[i][0] = mu[ha];
        l[i][1] = mu1[ha1] + n;
    }
    vector<int> v;
    int t = 0;
    while (t != n)
    {
        int ma = 0, j;
        for (int i = 0; i < 2 * n; ++ i)
        if (cn[i] > ma)
        {
            ma = cn[i];
            j = i;
        }
        t += ma;
        v.emplace_back (j);
        for (int i : d[j])
        {
            -- cn[l[i][0]];
            -- cn[l[i][1]];
        }
    }
    cout << v.size() << "\n";
    for (int i : v)
    {
        vector<int> V;
        for (int j : d[i])
        {
            if (!fi[j]) V.emplace_back (j + 1);
            fi[j] = 1;
        }
        cout << V.size() << " ";
        for (int i : V)
        cout << i << " ";
        cout << "\n";
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