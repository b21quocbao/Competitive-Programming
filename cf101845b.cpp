#include<bits/stdc++.h>
#define taskname "VirtualACM"
#define sz(a) static_cast<int>(a.size())
using namespace std;

const int maxn = (int)(1e4) + 10;
int a[maxn], b[maxn], c[maxn];
int n, ans;

template<typename T>
void Read(T &x)
{
    bool Neg = false;
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-') Neg = !Neg;
    x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (Neg) x = -x;
}

template<typename T>
void Read_01(T &x)
{
    char c;
    for (c = getchar(); c != '0' && c != '1'; c = getchar());
    x = c - '0';
}

template<typename T>
void Write(T x)
{
    if (x < 0)
    {
        putchar('-');
        Write(-x);
        return;
    }
    if (x > 9) Write(x / 10);
    putchar(x % 10 + '0');
}

void Enter()
{
    string s;
    getline(cin, s);
    n = sz(s);
    for (int i = 0; i < n; ++i) a[i] = s[i] - '0';
    getline(cin, s);
    for (int i = 0; i < n; ++i)
    {
        b[i] = s[i] - '0';
        b[i + n] = b[i];
    }
}

void Init()
{
    ans = n;
}

void Solve()
{
    for (int i = 0; i <= n; ++i)
    for (int ok = 0; ok < 2; ++ ok)
    {
        int num = 0;
        memset(c, 0, sizeof c);
        c[n - 1] = ok;
        c[0] = ok;
        for (int k = 0; k < n - 1; ++k)
        if (a[k] != (b[i + k] ^ c[k]))
        {
            ++num;
            c[k] ^= 1;
            c[k + 1] ^= 1;
        }
        if (b[i + n - 1] ^ c[n - 1] == a[n - 1])
        ans = min(ans, num);
    }
}

void PrintRes()
{
    if (ans < n) Write(ans);
    else Write(-1);
}

main()
{
    if (ifstream("test.inp"))
    {
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    }
    Enter();
    Init();
    Solve();
    PrintRes();
}