#include<bits/stdc++.h>
#define taskname "test1"
using namespace std;

const int maxn = 1e6;

int tt, nT = 1;
int n, ans;
string s, t;
int f[maxn + 10];

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
    cin>>n>>t;
}

void Init()
{
    n = (n << 1) + 1;
    s = string(n, '.');
    for (int i = 1; i < n; i += 2) s[i] = t[i >> 1];
    ans = 0;
}

void Solve()
{
    int l = 0, r = -1;
    for (int i = 0; i <= n; ++i)
    {
        int k = (i > r)? 0 : min(f[l + r - i], r - i) + 1;
        while (i - k >= 0 && i + k <= n && s[i - k] == s[i + k]) ++k;
        f[i] = --k;
        if (i + k > r)
        {
            l = i - k;
            r = i + k;
        }
        int len = k;
        ans = max(ans, len);
    }
}

void PrintRes()
{
    cout<<ans;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    if (ifstream("test.inp"))
    {
        freopen("test.inp", "r", stdin);
        #ifdef CHECKING
            freopen(taskname".out", "w", stdout);
        #else
            freopen("test.out", "w", stdout);
        #endif //CHECKING
    }
    else if (ifstream(taskname".inp"))
    {
        freopen(taskname".inp", "r", stdin);
        freopen(taskname".out", "w", stdout);
    }

    //Read(nT);
    for (tt = 1; tt <= nT; ++tt)
    {
        Enter();
        Init();
        Solve();
        PrintRes();
    }
}