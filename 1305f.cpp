/*
Code by b21
Time: 16:13 Wed 04/03/2020
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
   else if (ifstream("1305f.inp"))
    {
        freopen("1305f.inp", "r", stdin);
        freopen("1305f.out", "w", stdout);
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

bool ok[1000010];
vector<int> pr;

void eros (int n) {
    for (int i = 2; i * i <= n; ++ i) 
    if (!ok[i])
    for (int j = i * i; j <= n; j += i)
    ok[j] = 1;
    for (int i = 2; i <= n; ++ i)
    pr.emplace_back(i);
}

void enter()
{
    int n;
    cin >> n;
    vector<long long> v (n);
    for (long long& i : v) cin >> i;
    eros (1000000);
    srand(time(nullptr));
    random_shuffle(v.begin(), v.end());
    set<long long> se;
    for (int i = 0; (i < min (100ll, (int)v.size())) && ((int)se.size() * n <= 300000000); ++ i)
    for (long long k = v[i] - 1; k <= v[i] + 1; ++ k){
        long long x = k;
        if (!x) continue;
        if ((int)se.size() * n >= 300000000) break;
        for (int j : pr)
        if (1ll * j * j > x) break;
        else if (x % j == 0) {
            se.emplace(j);
            if ((int)se.size() * n >= 300000000) break;
            while (x % j == 0) x /= j;
        }
        if (x > 1) se.emplace(x);
        if ((int)se.size() * n >= 300000000) break;
    }
    long long sol = LLONG_MAX;
    for (int j : se) {
        long long res = 0;
        for (int i : v) 
        {
            if (i < j)
            res += (j - (i % j));
            else
            res += min (i % j, j - (i % j));
        }
        sol = min (sol, res);
        if (res == 3) cerr << j;
    }
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