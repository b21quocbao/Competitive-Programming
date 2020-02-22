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
int bi[mn], t[mn];
int la[4 * mn], it[4 * mn];
string s;

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

inline void lazy (int id, int d)
{
    la[id] += d;
    it[id] += d;
}

inline void layd (int id)
{
    int i = (id << 1);
    lazy (i, la[id]);
    lazy (i + 1, la[id]);
    la[id] = 0;
}

void initit (int id, int l, int r)
{
    if (l == r)
    {
        it[id] = t[l];
        return;
    }
    int m = (l + r) >> 1, i = id << 1;
    initit (i, l, m);
    initit (i + 1, m + 1, r);
    it[id] = min (it[i], it[i + 1]);
}

void udit (int id, int l, int r, int x, int d)
{
    if (r < x) return;
    if (l >= x)
    {
        lazy (id, d);
        return;
    }
    int m = (l + r) >> 1;
    int i = id << 1;
    layd (id);
    udit (i, l, m, x, d);
    udit (i + 1, m + 1, r, x, d);
    it[id] = min (it[i], it[i + 1]);
}

int quit (int id, int l, int r, int x, int y)
{
    if (!x) return 0;
    if (r < x || l > y) return INT_MAX;
    if (l >= x && r <= y) return it[id];
    int m = (l + r) >> 1;
    int i = id << 1;
    layd (id);
    return min (quit (i, l, m, x, y), quit (i + 1, m + 1, r, x, y));
}

void enter()
{
    int n, m;
    read (n); read (m);
    char c = getchar();
    while ((c != '(') && (c != ')'))
    c = getchar();
    s.push_back(' ');
    while ((c == '(' || c == ')'))
    {
        s.push_back(c);
        c = getchar();
    }
    for (int i = 1; i <= n; ++ i)
    if (s[i] == '(')
    t[i] = t[i - 1] + 1;
    else
    t[i] = t[i - 1] - 1;
    initit (1, 1, n);
    for (int i = 0; i < m; ++ i)
    {
        int id, x;
        read (id); read (x);
        if (!id)
        {
            char c = getchar();
            while ((c != '(') && (c != ')'))
            c = getchar();
            if (s[x] == c) continue;
            if (c == '(')
            udit (1, 1, n, x, 2);
            else 
            udit (1, 1, n, x, - 2);
            s[x] = c;
        }
        else
        {
            int y;
            read (y);
            int r1 = quit (1, 1, n, x - 1, x - 1);
            int r2 = quit (1, 1, n, y, y);
            if ((quit (1, 1, n, x, y) == r1) && (r2 == r1))
            putchar ('1');
            else
            putchar ('0');
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