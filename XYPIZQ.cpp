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

pair<int, int> alpha;

int n;

int detect (int x, int y, int z)
{
    if (x > y)
    {
        return (y > z ? 1 : 2); 
    }
    else return (y > z ? 3 : 4);
}

pair<int, int> rg (pair<int, int> x)
{
    int d = __gcd (x.first, x.second);
    x.first /= d;
    x.second /= d;
    return x;
}

pair<int, int> operator * (int n, pair<int, int> x)
{
    x.first *= n;
    x = rg (x);
    return x;
}

pair<int, int> a (int i)
{
    return rg ((2 * n - 2 * i + 1) * alpha);
}

pair<int, int> operator + (int n, pair<int, int> x)
{
    return rg ({n * x.second + x.first, x.second});
}

pair<int, int> operator - (int n, pair<int, int> x)
{
    return rg ({n * x.second - x.first, x.second});
}

pair<int, int> operator / (pair<int, int> x, int n)
{
    return rg ({x.first, x.second * n});
}

ostream& operator << (ostream& out, pair<int, int> x)
{
    rg (x);
    cout << x.first << " " << x.second << "\n";
    return cout;
}

void enter()
{
    int t, i, y, z;
    cin >> n >> t >> i >> y >> z;
    alpha = rg (make_pair (1, 2 * n + 1));
    int cs = detect (i, y, z);
    if (t == 1)
    {
        if (cs == 1) cout << (1 + a (i - 2)) / 2;
        else if (cs == 2) cout << (1 - a (i)) / 2;
        else if (cs == 3) cout << (1 - a (i)) / 2;
        else cout << (1 + a (i + 2)) / 2;
    }
    else if (t == 2)
    {
        if (cs == 1) cout << a (i - 1);
        else if (cs == 2) cout << make_pair (0, 1);
        else if (cs == 3) cout << make_pair (0, 1);
        else cout << a (i + 1);
    }
    else if (t == 3)
    {
        if (cs == 1) cout << (1 + a (i)) / 2;
        else if (cs == 2) cout << (1 - a (i)) / 2;
        else if (cs == 3) cout << (1 - a (i)) / 2;
        else cout << (1 + a (i)) / 2;
    }
    else
    {
        if (cs == 1) cout << a (i - 1);
        else if (cs == 2) cout << make_pair (0, 1);
        else if (cs == 3) cout << make_pair (0, 1);
        else cout << a (i + 1);
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
    cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}