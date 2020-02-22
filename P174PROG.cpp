#include <bits/stdc++.h>
#define int long long

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
unordered_map<int, int> D[2];

void docfile()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (ifstream(fn".inp"))
    {
        freopen(fn".inp", "r", stdin);
        if (!aNs) freopen(fn".out", "w", stdout);
		else freopen (fn".ans", "w", stdout);
    }else if (ifstream(fn1".inp"))
    {
        freopen(fn1".inp", "r", stdin);
        freopen(fn1".out", "w", stdout);
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

void cnh (int x, int w)
{
    int r = (x >> 1);
    int d = x - r - r;
    D[d][r] += w;
}

int qu (int x)
{
    int r = (x >> 1);
    int d = x - r - r;
    return (D[d].count (r) ? D[d][r] : 0);
}

void enter()
{
    int q;
    cin >> q;
    for (int i = 0; i < q; ++ i)
    {
        int id, u, v, vt;
        cin >> id >> u >> v;
        vector<int> V;
        while (v)
        {
            V.emplace_back(v);
            v >>= 1;
        }
        V.emplace_back(v);
        reverse (V.begin(), V.end());
        if (id == 1)
        {
            int w;
            cin >> w;
            while (1)
            {
                vt = lower_bound(V.begin(), V.end(), u) - V.begin();
                if (vt < V.size() && V[vt] == u) break;
                cnh (u, w);
                u >>= 1;
            }
            for (int i = vt + 1; i < V.size(); ++ i)
            cnh (V[i], w);
        }
        else
        {
            long long sol = 0;
            while (1)
            {
                vt = lower_bound(V.begin(), V.end(), u) - V.begin();
                if (vt < V.size() && V[vt] == u) break;
                sol += qu (u);
                u >>= 1;
            }
            for (int i = vt + 1; i < V.size(); ++ i)
            sol += qu (V[i]);
            cout << sol << "\n";
        }
    }   
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