#include <bits/stdc++.h>
using namespace std;
const int mn = 100005;
long long a[mn];
int id[mn], bi[mn];
int db (int x)
{
    int r = 0;
    for (; x < mn; x += x & - x)
    r += bi[x];
    return r;
}
void ub (int x)
{
    for (; x >= 1; x -= x & - x)
    ++ bi[x];
}
int main()
{
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, s;
    cin >> n >> s;
    vector<long long> v;
    for (int i = 1; i <= n; ++ i)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= n; ++ i)
    {
        a[i] -= 1ll * s * i;
        v.emplace_back(a[i]);
    }
    v.emplace_back(0);
    sort (v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for (int i = 0; i <= n; ++ i)
    a[i] = (lower_bound(v.begin(), v.end(), a[i]) - v.begin()) + 1;
    ub (a[0]);
    long long sol = 0;
    for (int i = 1; i <= n; ++ i)
    {
        sol += db (a[i]);
        ub (a[i]);
    }
    cout << sol;
}