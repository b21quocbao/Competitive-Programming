#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;
typedef vector<vector<int> > vii;

int tt, ntest = 1;
vii c(2, vector<int> (2));
long long n;

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

vii operator * (vii a, vii b)
{
    for (int i = 0; i < 2; ++ i)
    for (int j = 0; j < 2; ++ j)
    {
        c[i][j] = 0;
        for (int k = 0; k < 2; ++ k)
        c[i][j] += (1ll * a[i][k] * b[k][j]) % mod;
        if (c[i][j] >= mod) c[i][j] -= mod; 
   }
    return c;
}

vii po (vii a, long long n)
{
    if (n == 1) return a;
    auto b = po (a, n >> 1);
    b = b * b;
    return ((n & 1) ? b * a : b); 
}

void enter()
{
    cin >> n;    
    vii g(2, vector<int> (1, 0)), ch (2, vector<int> (2, 0));
    g[0][0] = ch[0][0] = ch[0][1] = ch[1][0] = 1;
    if (n - 1 >= 1) g = po (ch, n - 1) * g;
    cout << g[0][0];
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