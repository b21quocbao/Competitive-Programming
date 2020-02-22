#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e3) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = base;
string v1[mn], v2[mn];
int id[mn];

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

struct cmp
{
    bool operator () (const string& a, const string& b)
    {
        if (!isalpha (a[0]))
        {
            if (a[0] == '-' && b[0] != '-') return 1;
            if (a[0] != '-' && b[0] == '-') return 0;
            if (a[0] == '-' && b[0] == '-')
            {
                if (a.size() != b.size())
                return (a.size() > b.size());
                for (int i = 1; i < min (a.size(), b.size()); ++ i)
                if (a[i] != b[i])
                return (a[i] > b[i]);
                return 0;
            }
            if (a.size() != b.size())
            return (a.size() < b.size());
        }
        for (int i = 0; i < min (a.size(), b.size()); ++ i)
        if (a[i] != b[i])
        return (a[i] < b[i]);
        return (a.size() < b.size());
    }
} myc;

void enter()
{
    string s, s1;
    getline (cin, s);
    int n = 0, m = 0, cn = 0;
    if (s == ".") exit(0);
    for (char c : s)
    {
        if (c == ',' || c == '.')
        {
            if (isalpha (s1[0]))
            {
                v1[n ++] = s1;
                id[cn ++] = 1;
            }
            else
            {
                v2[m ++] = s1;
                id[cn ++] = 0;
            }
            s1.clear();
        }
        else 
        if (isalnum (c) || c == '-')
        s1.push_back(c);
    }
    sort (v1, v1 + n, myc);
    sort (v2, v2 + m, myc);
    n = 0; m = 0;
    for (int i = 0; i < cn; ++ i)
    {
        if (id[i] == 1) cout << v1[n ++];
        else cout << v2[m ++];
        if (i != cn - 1)
        cout << ", "; 
        else
        cout << ".\n";
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