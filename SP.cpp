#include <bits/stdc++.h>

#define fn "test"
#define fn1 "SP"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int f[71][71][71][110];
int S;


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

int F (int a, int b, int c, int s)
{
    int d = 0;
    if (a < 0 || b < 0 || c < 0) return 0;
    if (s <= 0) return F (a, b, c, S) + 1;
    if (!a && !b && !c) return 0;
    if (f[a][b][c][s] != - 1) return f[a][b][c][s];
    return f[a][b][c][s] = max (F (a - 1, b, c, s - 1), max (F (a, b - 1, c, s - 2), F (a, b, c - 1, s - 3)));
}

void enter()
{
    int a, b, c, s;
    cin >> a >> b >> c >> s;
    S = s;
    if (s > a + 2 * b + 3 * c) 
    {
        cout << 0;
        return;
    }
    if (s == 1)
    {
        cout << a + b + c;
        return;
    }
    if (s == 2)
    {
        cout << b + c + a / 2;
        return;
    }
    vector<int> v;
    v.emplace_back(0);
    v.emplace_back(a);
    v.emplace_back(b);
    v.emplace_back(c);
    int sol = 0;
    int S = s;
    if (a <= 70 && b <= 70 && c <= 70 && s <= 100)
    {
        memset (f, - 1, sizeof (f));
        cout << F (a, b, c, s);   
        return;
    }
    while (v[1] + 2 * v[2] + 3 * v[3] >= s)
    {
        ++ sol;
        int s = S;
        for (int i = 3; i >= 1; -- i)
        {
            int d = min (s / i, v[i]);
            s -= d * i;
            v[i] -= d;
        }
        if (!s) continue;
        for (int i = s; i <= 3; ++ i)
        if (v[i])
        {
            -- v[i];
            break;
        }
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