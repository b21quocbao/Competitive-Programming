#include <bits/stdc++.h>
#define float double

#define fn "test"
#define fn1 "AQUARIUM"

using namespace std;

const int mn = 1 * (int)(1e6) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
vector<int> q[mn], v[mn];
float res[mn];

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
    int m, h;
    int x, x1;
    read (m); read (h);
    for (int i = 0; i <= m; ++ i)
    {
        read (x);
        if (!i) 
        {
            x1 = x;
            continue;
        }
        v[min (x1, x)].emplace_back(0, abs (x - x1)); 
        v[max (x1, x)].emplace_back(1 ,abs (x - x1));
        x1 = x;
    }
    float s = 0, l = 0;
    for (int i = 0; i <= h; ++ i)
    {
        for (auto d : v[i])
        {
            s += d.first;
            l += 1. / d;
            s -= 1. / 2 / d;
        }
        for (auto d : q[i])
        {
            if (!d)
            {
                s += 1;
                continue;
            }
            l -= 1. / d;
            s += 1. / 2 / d;
        }
        s += l;
        res[i] = (!i ? 0 : res[i - 1] + s);
    }
    int qu;
    read (qu);
    for (int i = 0; i < qu; ++ i)
    {
        read (x);
        cout << fixed << setprecision(4) << res[x - 1] << "\n";
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