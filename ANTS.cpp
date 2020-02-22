#include <bits/stdc++.h>

#define fn "test"
#define fn1 "ANTS"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e6) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int d[mm];
int a[mn];

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
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++ i)
    cin >> a[i];
    sort (a, a + n);
    int x = 1;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> >> qu;
    for (int i = 1; i < n; ++ i)
    if (a[i] == a[i - 1]) ++ x;
    else
    {
        d[a[i - 1]] = x;
        qu.push({a[i - 1], a[i - 1]});
    } 
    d[a[n - 1]] = x;
    qu.push ({a[n - 1], a[n - 1]});
    int res = 0, cur = 0, sol = 0, sv;
    while (qu.top().first <= k)
    {
        if (cur == qu.top().first) res += d[qu.top().second]; else res = d[qu.top().second];
        qu.push ({qu.top().first + qu.top().second});
        qu.pop_front();
        if (res > sol) {sol = res; sv = 1;}
        else if (res == sol) {++ sv};
    }
    cout << sol << " " << sv;
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