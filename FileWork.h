#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll rm = RAND_MAX + 1;

ll Ran (ll a, ll b)
{
    ll x = a + ((ll)rand() * rm * rm * rm + (ll)rand() * rm * rm + (ll)rand() * rm + (ll)rand()) % (b - a + 1);
    return x;
}

ll mak (ll a, ll b)
{
    int c = Ran (0, 2);
    if (!c) return  a;
    if (c == 1) return b;
    return Ran (a, b);
}

vector<int> fa;


int Fa (int u)
{
    return (fa[u] < 0 ? u : fa[u] = Fa (fa[u]));
}

void Uni (int u, int v)
{
    u = Fa (u); v = Fa (v);
    if (fa[u] > fa[v]) swap (u, v);
    fa[u] += fa[v];
    fa[v] = u;
}

void work ()
{
    ofstream in ("test.inp");
    ofstream an ("test.ans");
    int n = Ran (1000, 1000);
    in << n << "\n";
    for (int i = 1; i <= n; ++ i)
    in << Ran (1, 100000) << " ";
}