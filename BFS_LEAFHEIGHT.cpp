#include <bits/stdc++.h>
using namespace std;

#define fn "BFS_LEAFHEIGHT"

vector<int> e[101];
int d[101];

int main()
{
    freopen(fn".inp", "r", stdin);
    freopen(fn".out", "w", stdout);
    int n, m, root;
    cin >> n >> m >> root;
    for (int i = 0; i < m; ++ i)
    {
        int u, v;
        cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    deque<int> qu;
    qu.emplace_back(root);
    d[root] = 1;
    while(qu.size())
    {
        int u = qu.front(); qu.pop_front();
        bool ok = 0;
        for (int v : e[u])
        if (!d[v])
        { 
            ok = 1;
            d[v] = d[u] + 1, qu.emplace_back(v);
        }
        if (!ok)
        cout << u << " " << d[u] << "\n";
    }
}