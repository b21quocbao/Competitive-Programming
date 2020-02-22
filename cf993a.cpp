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
int d[230][230];
int xmin[2], xmax[2], ymin[2], ymax[2];

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
    for (int k = 0; k < 2; ++ k)
    {
        xmax[k] = INT_MIN;
        ymax[k] = INT_MIN;
        xmin[k] = INT_MAX;
        ymin[k] = INT_MAX;
    }
    for (int k = 0; k < 2; ++ k)
    for (int i = 0; i < 4; ++ i)
    {
        int x, y;
        cin >> x >> y;
        xmin[k] = min (xmin[k], x);
        xmax[k] = max (xmax[k], x);
        ymin[k] = min (ymin[k], y);
        ymax[k] = max (ymax[k], y);
    }
    for (int x = xmin[0]; x <= xmax[0]; ++ x)
    for (int y = ymin[0]; y <= ymax[0]; ++ y)
    d[x + 110][y + 110] = 1;
    int ymid = (ymin[1] + ymax[1]) >> 1;
    int xmid = (xmin[1] + xmax[1]) >> 1;
    for (int x = xmin[1], a = 0; x <= xmax[1]; ++ x)
    {
        for (int j = - a; j <= a; ++ j)
        {
            int y = ymid + j;
            if (d[x + 110][y + 110])
            {
                cout << "YES";
                return;
            }
        }
        if (x >= xmid) -- a; else ++ a;
    }
    cout << "NO";
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