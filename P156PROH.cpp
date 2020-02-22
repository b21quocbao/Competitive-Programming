#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const double eps = 2e-2;
const bool aNs = 0;

int tt, ntest = 1;
vector<int> v;
vector<int> c;

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

double go (double te)
{
    double g1 = te / 120.;
    double g2 = (te - trunc(te / 3600.) * 3600.) / 10.; 
    double g = g2 - g1;
    if (g < 0)
    {
        g = 360 - abs (g);
    }
    //if (g >= 180) g = 360 - g;
    return g;
}

double mo (double te)
{
    if (te < 3600) te += 12 * 3600;
    if (te >= 13 * 3600) te -= 12 * 3600;
    return te;
}

void enter()
{
    // 1s:1/120o
    // 43200:360
    // 120:1
    //3600 : 360
    //1:6
    // 1:1/10o
    // 1s:11/120o
    // 120s:11o
    // 120/11s:1o
    // k * (120/11s) : (k % 360)
    string s;
    int a, b;
    cin >> a >> s >> b;
    int t;
    if (b >= 12) b -= 12;
    if (s == "after")
    {
        int vt = upper_bound(v.begin(), v.end(), 3600 * b * 11) - v.begin();
        if (vt == v.size()) vt = 0;
        while (c[vt] != a) vt = (vt + 1) % ((int)v.size());
        t = round (v[vt] / 11.);
    }
    else
    {
        int vt = lower_bound(v.begin(), v.end(), 3600 * b * 11) - v.begin();
        cerr << v[vt] << "\n";
        -- vt;
        cerr << v[vt] << "\n";
        if (vt == - 1) vt = v.size() - 1;
        while (c[vt] != a) 
        {
            -- vt;
            if (vt < 0) vt += (int)(v.size());
        }
        t = round (v[vt] / 11.);
    }
    if (t < 3600) t += 12 * 3600;
    cout << "Case " << tt << ": " << t / 3600 << ":" ;
    cout << setfill ('0') << setw(2) << (t % 3600) / 60;
    cout << ":" << setfill ('0') << setw (2) << t % 60 << "\n";
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
    int te = 0;
    int cn = 0;
    int eps = 1;
    while (te < 12 * 3600 * 11)
    {
        v.emplace_back(te);
        c.emplace_back(cn);
        cn = (cn + 1) % 360;
        te = te + 120;
    }
    cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}