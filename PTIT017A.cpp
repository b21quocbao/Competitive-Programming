#include <bits/stdc++.h>

using namespace std;

const int mn = 1 * (int)(1e7) + 10;

int d[mn];
vector<int> e[8];
int cn[8] = {665134,2536838,3642766,2389433,691209,72902,1716,1};

void eros (int N)
{
    for (int i = 2; i <= N; ++ i)
    if (!d[i])
    for (int j = i; j <= N; j += i)
    ++ d[j];
    for (int i = 0; i < 8; ++ i)
    e[i].reserve(cn[i]);
    for (int i = 2; i <= N; ++ i)
    e[d[i] - 1].emplace_back(i);
}

int main()
{
    ios_base::sync_with_stdio (0);
    cin.tie(nullptr);
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int ntest;
    cin>>ntest;
    eros (10000000);
    for (int tt = 1; tt <= ntest; ++ tt)
    {
        int l, r, k;
        cout << "Case #" << tt << ": "; 
        cin >> l >> r >> k;
        if (l > r)
        {
            cout << 0 << "\n";
            continue;
        }
        if (k > 8)
        {
            cout << 0 << "\n";
            continue;
        }
        -- k;
        cout << upper_bound(e[k].begin(), e[k].end(), r) - lower_bound(e[k].begin(), e[k].end(), l) << "\n";
    }
}