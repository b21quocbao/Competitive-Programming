#include <bits/stdc++.h>

#define fn "test"
#define fn1 "LPASS"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
pair<long long, int> a[mn];
int b[mn];
int n, k;
int Id[mn];
int f[mm][9][mm];
long long po[20];

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

int F (int id, int d, int l)
{
    if (f[id][d][l] != - 1) return f[id][d][l];
    int j = Id[id];
    if (!d && l == k)
    f[id][d][l] = a[j].second;
    else
    f[id][d][l] = 0;
    for (int i = id + 1; i <= n; ++ i)
    if (F (i, (d + b[Id[i]]) % 9, l + 1))
    {
        f[id][d][l] = max (f[id][d][l], F (i, (d + b[Id[i]]) % 9, l + 1) + a[j].second);
    }
    return f[id][d][l];
}

void enter()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++ i)
    {
        Id[i] = i;
        int x;
        cin >> x;
        int r = x;
        a[i].first = x;
        a[i].second = 0;
        b[i] = x;
        while (r)
        {
            r /= 10;
            ++ a[i].second;
        }
        // while (a[i].first < (int)(1e9)) a[i].first *= 10;
    }
    po[0] = 1ll;
    for (int i = 1; i <= 18; ++ i)
    po[i] = po[i - 1] * 10;
    sort (Id + 1, Id + n + 1, [](int i, int j)
         {
             return a[i].first * po[a[j].second] + a[j].first > a[j].first * po[a[i].second] + a[i].first; 
         });
    memset (f, - 1, sizeof (f));
    int ma = F (0, 0, 0);
    if (!ma)
    {
        cout << - 1;
        return;
    }
    cerr << ma;
    int d = 0, l = 1;
    for (int j = 1; j <= n; ++ j)
    {
        int i = Id[j];
        int k = (d + a[i].first) % 9;
        if (k < 0) k += 9;
        if (!ma) break;
        if (ma == F (j, k, l))
        {
            ++ l;
            ma -= a[i].second;
            d = (d + b[i]) % 9;
            cout << b[i];
        }
    }
}

void solve()
{
    cout << "\n";
}

void print_result()
{

}

int main()
{
    docfile();
    cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}