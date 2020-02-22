#include <bits/stdc++.h>
#define int long long

#define fn "test"
#define fn1 "COLOR"

using namespace std;

const int mn = 2 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int S;
int d[mn];
int f[13][mn];
int st[5], en[5];
int a[20][20], p[20][20];

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

#define ar array<int, 5>
ar h, t;

int F (int i, ar h)
{
    int r = 0;
    for (int i : h)
    r = r * 11 + i;
    if (d[r] > S) 
    {
        // for (int i : h)
        // cout << i << " ";
        // cout << "\n";
        // cout << d[r] << "\n";
        return 0;
    }
    if (i == 10) return 1;
    if (f[i][r] != - 1) return f[i][r];
    f[i][r] = 0;
    int st[5], en[5];
    for (int j = 0; j < 5; ++ j)
    if (!h[j])
    st[j] = 0, en[j] = p[i + 1][j];
    else
    st[j] = h[j] - 1, en[j] = h[j] - 1;
    for (int i0 = st[0]; i0 <= en[0]; ++ i0)
    for (int i1 = st[1]; i1 <= en[1]; ++ i1)
    for (int i2 = st[2]; i2 <= en[2]; ++ i2)
    for (int i3 = st[3]; i3 <= en[3]; ++ i3)
    for (int i4 = st[4]; i4 <= en[4]; ++ i4)
    {
        // cerr << i << " " << i0 << " " << i1 << " " << i2 << " " << i3 << " " << i4 << "\n";
        h = {i0, i1, i2, i3, i4};
        f[i][r] += F (i + 1, h);
    }
    return f[i][r];
}

void attemp (int id)
{
    // cerr << id << "\n";
    if (id == 5)
    {
        int r = 0;
        for (int i : h)
        r = r * 11 + i;
        for (int i = 0; i < 5; ++ i)
        {
            int mi = INT_MAX;
            for (int j = i; j < 5; ++ j)
            {
                mi = min (mi, h[j]);
                d[r] = max (d[r], mi * (j - i + 1));
            }
        }
        return;
    }
    for (int i = 0; i <= 10; ++ i)
    {
        h[id] = i;
        attemp (id + 1);
    }
}

void enter()
{
    cin >> S;
    attemp (0);
    for (int i = 0; i < 5; ++ i)
    for (int j = 1; j <= 10; ++ j)
    {
        char c;
        cin >> c;
        if (c == '1')
        a[j][i] = 1;    
    }
    for (int i = 10; i >= 1; -- i)
    for (int j = 0; j < 5; ++ j)
    if (!a[i][j])
    p[i][j] = p[i + 1][j] + 1;
    else p[i][j] = 0;
    memset (f, - 1, sizeof (f));
    int a = F (0, t);
    // cout << a << "\n";
    memset (f, - 1, sizeof (f));
    -- S;
    cout << a - F (0, t);

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