/*
Code by b21
Time: 15:41 Fri 28/02/2020
*/

#include <bits/stdc++.h>
#define int long long

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
void docfile()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (ifstream("test.inp"))
    {
       freopen("test.inp", "r", stdin);
       if (!aNs) freopen("test.out", "w", stdout);
       else freopen ("test.ans", "w", stdout);
    }
   else if (ifstream("cf1313d.inp"))
    {
        freopen("cf1313d.inp", "r", stdin);
        freopen("cf1313d.out", "w", stdout);
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

bool ok[8];

void ma (int& a, int b, int c) {
    if (b == - 1) return;
    a = max (a, b + c);
}

int unUse (int k) {
    for (int i = 0; i < k; ++ i)
    if (!ok[i])
    {
        ok[i] = 1;
        return i;
    }
}

void freeMem(int k) {
    ok[k] = 0;
}

void enter()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, pair<int, bool>> > a;
    vector<int> id;
    for (int i = 0; i < n; ++ i) {
        int l, r;
        cin >> l >> r;
        a.emplace_back(l, make_pair(i, 0));
        a.emplace_back(r + 1, make_pair(i, 1));
        id.emplace_back(id.size());
        id.emplace_back(id.size());
    }
    sort (id.begin(), id.end(), [&](int i, int j)
         {
             if (a[i].first != a[j].first)
             return a[i].first < a[j].first;
             return a[i].second.second > a[j].second.second;
         });
    int j = 0, K = 0;
    vector<int> f(1 << k), f1(1 << k);
    vector<int> idK(2 * n, - 1);
    vector<int> b(1 << k);
    for (int i = 0; i < (1 << k); ++ i) 
    b[i] = __builtin_popcount(i) % 2;
    fill(f.begin(), f.end(), - 1);
    f[0] = 0;
    // for (auto i : id) cout << a[i].first << "\n";
    int S = 0;
    for (int i = 0; i < id.size() - 1; ++ i) {
        f.swap(f1);
        fill(f.begin(), f.end(), - 1);
        int d = a[id[i + 1]].first - a[id[i]].first;
        bool l = 0;

        if (idK[a[id[i]].second.first] == - 1)
        {
            idK[a[id[i]].second.first] = unUse(k);
            l = 1;
        }
        else 
        freeMem(idK[a[id[i]].second.first]);
        int idI = idK[a[id[i]].second.first];
        for (int mask = 0; mask < (1 << k); ++ mask) {
            if ((mask >> idI) & 1)
            {
                if (l)
                ma (f[mask], f1[mask ^ (1 << idI)], b[mask] * d);
                else
                ma (f[mask ^ (1 << idI)], f1[mask], b[mask ^ (1 << idI)] * d);
            }
            else 
            {
                ma (f[mask], f1[mask], b[mask] * d);
            }
        }
    }
    int sol = 0;
    for (int i = 0; i < (1 << k); ++ i) 
    sol = max (sol, f[i]);
    // cerr << f[()];
    cout << sol;
}

void solve()
{

}

void print_result()
{

}

main()
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