#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
unordered_set<int> pr;
bool Pr[mn];
int n;
int v[mn];
int ok[mn];
int cn[2], X[2], a[2];

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

void eros (int n)
{
    for (int i = 2; i <= trunc(sqrt (n)); ++ i)
    if (!Pr[i])
    for (int j = i * i; j <= n; j += i)
    Pr[j] = 1;
    for (int i = 2; i <= n; ++ i)
    if (!Pr[i])
    pr.insert(i);
}

void enter()
{
    eros (45000);
    cin >> n;
    for (int i = 0; i < n; ++ i)
    {
        int x;
        int cv = 0;
        for (int j = 0; j < 2; ++ j)
        {
            cin >> x;
            for (int k : pr)
            {
                if (x % k) 
                {
                    if (!ok[k]) v[cv ++] = k;
                    ++ ok[k];
                }
                while (x % k == 0) x /= k;
            }
            if (!i) X[j] = x;
            a[j] = x;
        }
        if ((a[1] % X[0] == 0) || (a[0] % X[0] == 0)) ++ cn[0];
        if ((a[1] % X[1] == 0) || (a[0] % X[1] == 0)) ++ cn[1];
        for (int i = 0; i < cv; ++ i)
        {
            if (ok[v[i]] == 2)
            pr.erase(v[i]);
            ok[v[i]] = 0;
        }
    }
    if (pr.size()) cout << *pr.begin();
    else 
    {
        if (X[0] != 1 && cn[0] == n)
        {
            cout << X[0];
            return;
        }
        if (X[1] != 1 && cn[1] == n)
        {
            cout << X[1];
            return;
        }
        cout << -1;
    }
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