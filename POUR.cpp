#include <bits/stdc++.h>

#define fn "test"
#define fn1 "POUR"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
uint32_t v[3], id[3];

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

void enter()
{
    uint32_t V = 0;
    for (int i = 0; i < 3; ++ i)
    {
        cin >> v[i];
        id[i] = i;
    }
    vector<pair<int, int> > sol;
    while (1)
    {
        sort (id, id + 3, [](int i, int j)
             {
                  return v[i] < v[j];
             });
        vector<pair<int, int> > res;
        if (!v[id[0]]) break;
        int k = v[id[0]];
        while (v[id[0]] <= v[id[1]]) v[id[0]] <<= 1;
        for (int i = (v[id[0]] >> 1); i >= k; i >>= 1)
        {
            if (v[id[1]] >= i) 
            {
                v[id[1]] -= i;
                res.push_back({id[1] + 1, id[0] + 1});
            }
            else
            {
                v[id[2]] -= i;
                res.push_back({id[2] + 1, id[0] + 1});
            }
        }
        reverse(res.begin(), res.end());
        for (auto x : res)
        {
            sol.push_back(x);
        }
    }
    cout << sol.size() << "\n";
    for (auto x : sol)
    cout << x.first << " " << x.second << "\n";
}

void solve()
{

}

void print_result()
{

}

int main()
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