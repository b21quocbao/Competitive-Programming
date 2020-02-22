#include<bits/stdc++.h>
#define taskname "test"
#define sz(a) static_cast<int>(a.size())
using namespace std;

const int maxn = 1e5;
int n, ans;
int a[maxn + 10];
vector<int> v;

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
    Read(n);
    for (int i = 1; i <= n; ++i) Read(a[i]);
}

void Init()
{
    int i = 1;
    for (; i <= n && a[i] == -1; ++i);
    --i;
    for (; i >= 0; --i)
        a[i] = a[i + 1] - 1;
}

void Solve()
{
    for (int i = 1; i <= n; ++i)
        if (a[i] != 1 && a[i] != -1 && a[i - 1] != -1 && a[i] - 1 != a[i - 1])
        {
            ans = -1;
            return;
        }
    for (int i = 1; i <= n; ++i)
        if (a[i] == -1) a[i] = a[i - 1] + 1;
    v.clear();
    for (int i = 2; i <= n; ++i)
        if (a[i] == 1) v.push_back(a[i - 1]);
    if (!sz(v))
    {
        ans = 0;
        return;
    }
    sort(v.begin(), v.end());
    for (int i = 1; i < sz(v); ++i)
        if (v[i] % v[i - 1])
        {
            ans = -1;
            return;
        }
    ans = v[0];
}

void PrintRes()
{
    if (ans == -1) cout<<"impossible\n";
    if (ans == 0) cout<<"inf\n";
    if (ans > 0) cout<<ans<<'\n';
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname".inp","r",stdin);
    freopen(taskname".out","w",stdout);

    int T;  Read(T);
    while(T--)
    {
        Enter();
        Init();
        Solve();
        PrintRes();
    }
}