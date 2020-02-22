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
int su[mn], po[mn];

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
    string s;
    int m;
    char c = getchar ();
    while (!isdigit (c)) c = getchar();
    while (isdigit (c)) s.push_back(c), c = getchar();
    int n = s.size();
    read (m);
    int d = trunc (sqrt (n));
    for (int i = 0; i < n; i += d)
    {
        for (int j = i; j < min (i + d, n); ++ j)
        {
            su[i / d] = (su[i / d] << 1) + (s[j] - '0');
            if (su[i / d] >= 5) su[i / d] -= 5;
        }
    }
    po[0] = 1;
    for (int i = 1; i <= n; ++ i)
    {
        po[i] = (po[i - 1] << 1);
        if (po[i] >= 5) po[i] -= 5;
    }
    for (int i = 0; i < m; ++ i)
    {
        int id, x, y;
        read (id);
        read (x); read (y);
        if (!id)
        {
            int sol = 0;
            // for (int i = 0; i < n; i += d)
            // cerr << su[i / d] << " ";
            // cerr << "\n";
            // cerr << s << "\n";
            for (; x % d && x <= y; ++ x)
            {
                sol = (sol << 1) + (s[x] - '0');
                if (sol >= 5) sol -= 5;
            }
            if (x > y) 
            {
                write (sol);
                putchar ('\n');
                continue;
            }
            for (int i = x / d; i < y / d; ++ i)
            sol = ((sol * po[d]) + su[i]) % 5;
            if (y % d == d - 1)
            {
                sol = ((sol * po[d]) + su[y / d]) % 5;
            }
            else
            {
                for (int i = y / d * d; i <= y; ++ i)
                {
                    sol = (sol << 1) + (s[i] - '0');
                    if (sol >= 5) sol -= 5;
                }
            }
            write (sol);
            putchar ('\n');
        }
        else
        {
            if (s[x] == ('0' + y)) continue;
            s[x] = ('0' + y);
            if (!y)
            {
                if (x / d == (n - 1) / d)
                su[x / d] = su[x / d] - po[n - 1 - x];   
                else
                su[x / d] = su[x / d] - po[d - 1 - (x % d)];
                
                if (su[x / d] < 0) su[x / d] += 5;
            }
            else
            {
                if (x / d == (n - 1) / d)
                su[x / d] = su[x / d] + po[n - 1 - x];
                else
                su[x / d] = su[x / d] + po[d - 1 - (x % d)];
                if (su[x / d] >= 5) su[x / d] -= 5;
            }
        }
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