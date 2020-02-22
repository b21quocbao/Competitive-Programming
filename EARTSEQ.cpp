#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e6) + 10;
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

vector<int> v;
bool pr[mn];

void eros (int n)
{
    for (int i = 2; i * i <= n; ++ i)
    if (!pr[i])
    for (int j = i * i; j <= n; j += i)
    pr[j] = 1;
    for (int i = 2; i <= n; ++ i)
    if (!pr[i])
    v.emplace_back(i);
}

void enter()
{
    int n;
    int c = v.size() - 1;
    cin >> n;
    if (n == 3)
    {
        cout << 6 << " " << 10 << " " << 15;
        return;
    }
    bool ok = 0;
    int d = 2;
    for (int i = 0; i < n; ++ i)
    {
        if (!ok) 
        {
            if (i == n - 1)
            {
                cout << d * 2;
                continue;
            }
            cout << d * v[c];
            if (d != 3) d = 3;
            else d = 5;
        }
        else
        {
            if (i == n - 1)
            {
                cout << v[c] * 2;
                continue;
            }
            cout << v[c] * d;
            -- c;
        }
        cout << " ";
        ok = !ok;
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
    eros (1000000);
    cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}