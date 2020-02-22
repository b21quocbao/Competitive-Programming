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
int x[20];
int d[(1 << 18)];
int bi[20];

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
    cin.ignore();
    map<string, int> mu;
    for (int i = 0; i < n; ++ i)
    {
        string s1, s;
        x[i] = 0;
        getline (cin, s1);
        for (char c : s1)
        if (isdigit(c))
        x[i] = x[i] * 10 + c - '0';
        else if (isalpha (c) || c == ' ')
        s.push_back(c);
        if (s.back() == ' ')
        s.pop_back();
        mu[s] = i;
    }
    memset (bi, 0, sizeof (bi));
    for (int i = 0; i < m; ++ i)
    {
        string s1, s2, s3;
        bool ok = 0;
        getline (cin, s2);
        for (char c : s2)
        {
            if (c == '-') ok = 1;
            if (c == '-' || c == '>') continue;
            if (ok)
            s3.push_back(c);
            else
            s1.push_back(c);
        }
        if (s1.back() == ' ')
        s1.pop_back();
        if (s3.back() == ' ')
        s3.pop_back();
        if (s3[0] == ' ')
        s3.erase(s3.begin());
        int u = mu[s1], v = mu[s3];
        bi[v] |= (1 << u);
    }
    int sol = 0;
    memset (d, 0, sizeof (d));
    for (int i = 0; i < (1 << n) - 1; ++ i)
    {
        int cn = 1;
        bool ok = 1;
        for (int j = 0; j < n; ++ j)
        if ((i >> j) & 1)
        if ((bi[j] & i) != bi[j]) 
        {
            ok = 0;
            break;
        }
        else ++ cn;
        if (!ok) continue;
        for (int j = 0; j < n; ++ j)
        if (((i >> j) & 1) == 0)
        {
            int l = i ^ (1 << j);
            if ((bi[j] & l) == bi[j])
            d[l] = max (d[l], d[i] + cn * x[j]);
        }
    }
    cout << d[(1 << n) - 1] << "\n";
}

void solve()
{

}z

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