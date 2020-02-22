#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e3;
queue<int> Q;
int n, m, s, t;
int c[maxn + 10][maxn + 10], f[maxn + 10][maxn + 10];
int Flowln[maxn + 10], h[maxn + 10];
bool InQueue[maxn + 10];

void Enter()
{
    cin>>n>>m>>s>>t;
    memset(c, 0, sizeof c);
    for (int i = 1; i <= m; ++i)
    {
        int u, v;
        cin>>u>>v;  cin>>c[u][v];
    }
}

bool OverFlow(int u)
{
    return (u != s && u != t && Flowln[u] > 0);
}

void Init()
{
    memset(f, 0, sizeof f);
    memset(InQueue, false, sizeof InQueue);
    memset(h, 0, sizeof h);
    h[s] = n;
    for (int v = 1; v <= n; ++v)
    {
        f[s][v] = c[s][v];
        f[v][s] = -c[s][v];
        Flowln[v] = f[s][v];
        if (OverFlow(v))
        {
            Q.push(v);
            InQueue[v] = true;
        }
    }
}

bool Discharge(int u)
{
    bool Pushed = false;
    for (int v = 1; v <= n; ++v)
        if (c[u][v] > f[u][v] && h[u] > h[v])
        {
            int Delta = c[u][v] - f[u][v];
            Delta = min(Delta, Flowln[u]);
            f[u][v] += Delta;
            f[v][u] -= Delta;
            Flowln[u] -= Delta;
            Flowln[v] += Delta;
            if (OverFlow(v) && !InQueue[v])
            {
                Q.push(v);
                InQueue[v] = true;
            }
            Pushed = true;
        }
    return Pushed;
}

void Lift(int u)
{
    int minH = INT_MAX;
    for (int v = 1; v <= n; ++v)
        if (c[u][v] > f[u][v] && h[v] < minH) minH = h[v];
    h[u] = minH + 1;
}

void Preflowpush()
{
    while (!Q.empty())
    {
        int u = Q.front();
        if (!Discharge(u)) Lift(u);
        if (Flowln[u] <= 0)
        {
            Q.pop();
            InQueue[u] = false;
        }
    }
}

void PrintResult()
{
    int res = 0;
    for (int u = 1; u <= n; ++u)
        for (int v = 1; v <= n; ++v)
            if (f[u][v] > 0  && u == s) res += f[u][v];
    cout<<res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
freopen("test.inp", "r", stdin);
freopen("test.out", "w", stdout);
    Enter();
    Init();
    Preflowpush();
    PrintResult();
}