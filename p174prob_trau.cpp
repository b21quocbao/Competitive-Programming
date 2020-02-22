#include <bits/stdc++.h>
#define int long long

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 1;

int tt, ntest = 1;
int x, a, b;
vector<int> s1, s2;
int f[14][2][2][mn];
bool ok[13];

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

int F (int id, bool o1, bool o2, int mod)
{
    if (id == 13) return (!mod ? 1 : 0);
    if (f[id][o1][o2][mod] != - 1 ) return f[id][o1][o2][mod];
    int st, en;
    f[id][o1][o2][mod] = 0;
    if (!o1) st = s1[id]; else st = 0;
    if (!o2) en = s2[id]; else en = 9;
    for (int i = st; i <= en; ++ i)
    if (ok[i])
    f[id][o1][o2][mod] += F (id + 1, o1 | (i != st), o2 | (i != en), (mod * 10 + i) % x);
    return f[id][o1][o2][mod];
}

vector<int> ch (int a)
{
    vector<int> v;
    while (a)
    {
        v.emplace_back (a % 10);
        a /= 10;
    }
    while (v.size() < 13) v.emplace_back(0);
    reverse(v.begin(), v.end());
    return v;
}

bool kt (int y)
{
    while (y)
    {
        if (!ok[y % 10]) return 0;
        y /= 10;
    }
    return 1;
}

void enter()
{
    string s;
    cin >> x >> a >> b;
    cin >> s;
    for (char c : s)
    ok[c - '0'] = 1;
    if (x >= 0)
    {
        int sol = 0;
        auto y = x;
        while (y <= b)
        {
            if (y >= a && kt (y))
            {
                ++ sol;
        // cerr << y << "\n";
            }
            y += x;
        }
        cout << sol;
        return;
    }
    s1 = ch (a);
    s2 = ch (b);
    memset (f, - 1, sizeof (f));
    cout << F (0, 0, 0, 0);
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
    //cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}