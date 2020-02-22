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
    int n;
    read (n);
    vector<int> v, r;
    int x, y;
    for (int i = 1; i <= n; ++ i)
    v.emplace_back (i);
    while (v.size() >= 5)
    {
        r.clear();
        while (r.size () != 5)
        {
            r.emplace_back(v.back());
            v.pop_back();
        }
        cout << "? ";
        for (int i : r)
        cout << i << " ";
        cout << endl;
        int x, y;
        read (x); read (y);
        for (int i : r)
        if (i != x && i != y)
        v.emplace_back(i);
    }
    if (v.size() == 4)
    {
        cout << "? ";
        for (int i : v) 
        cout << i << " ";
        for (int i = 1; i <= n; ++ i)
        {
            bool ok = 1;
            for (int j : v)
            if (i == j) ok = 0;
            if (ok)
            {
                cout << i << endl;
                break;
            }
        }
        read (x); read (y);
        for (auto it = v.begin(); it != v.end(); ++ it)
        if ((*it) == x || (*it) == y)
        {
            v.erase(it);
            break;
        }
    }
    r.clear();
    for (int i = 1; i <= n; ++ i)
    if (i != v[0] && i != v[1] && i != v[2])
    {
        if (r.size() == 3) break;
        r.emplace_back(i);
    }
    cout << "? ";
    vector<pair<int, int> > qu;
    for (int i : r) cout << i << " ";
    cout << v[0] << " " << v[1] << endl;
    read (x); read (y);
    qu.emplace_back(x, y);
    cout << "? ";
    for (int i : r) cout << i << " ";
    cout << v[0] << " " << v[2] << endl;
    read (x); read (y);
    if (qu[0] == make_pair(x, y))
    {
        cout << "! " << v[0] << endl;
        return;
    }
    cout << "? ";
    for (int i : r) cout << i << " ";
    cout << v[1] << " " << v[2] << endl;
    read (x); read (y);
    if (qu[0] == make_pair(x, y))
    cout << "! " << v[1] << endl;
    else 
    cout << "! " << v[2] << endl;
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
    read (ntest);
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}