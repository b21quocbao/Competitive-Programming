#include<bits/stdc++.h>
#define taskname "test"
#define sz(a) static_cast<int>(a.size())
#define int long long
using namespace std;

int n, x, y;

void Enter()
{
    cin>>n;
    x = 0;  y = 1;
    for (int i = 1; i <= n; ++i)
    {
        int u, v;
        cin>>u>>v;
        x = x * v + u * y;
        y = y * v;
    }
}

void Init()
{

}

void Solve()
{

}

void PrintRes()
{
    cout<<x / y;
    x %= y;
    if (!x) return;
    cout<<'.';
    for (int i = 1; i < 400000; ++i)
    {
        x *= 10;
        cout<<x / y;
        x %= y;
        if (!x) return;
    }
    x *= 10;
    int ld = x / y;
    x %= y;
    if (x * 2 >= y) ++ld;
    cout<<ld;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("test.inp", "r", stdin);
    freopen("test.ans", "w", stdout);

    Enter();
    Init();
    Solve();
    PrintRes();
}