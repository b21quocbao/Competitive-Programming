#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e4) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 1;

int tt, ntest = 1;
int L, a, m, h[110], l[110], x[110], y[110];
vector<int> v;
vector<int> v1[mn], v2[mn];
bool ok[110][110];
int s[mn];

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
    
}

inline int id (int y)
{
    return (lower_bound (v.begin(), v.end(), y) - v.begin());
}

void solve()
{
    cin >> L >> a >> m;
    for (int i = 0; i < m; ++ i)
    {
        cin >> h[i] >> l[i] >> x[i] >> y[i];
        v.push_back(max (y[i] + 1 - a, 1));
        v.push_back(y[i] + l[i]);
    }
    v.push_back(1);
    v.push_back(L + 1);
    sort (v.begin(), v.end());
    v.resize(unique (v.begin(), v.end()) - v.begin());
    int inf = 1, sup = 256, sol;
    while (inf <= sup)
    {
        int mid = (inf + sup) >> 1;
        memset (ok, 0, sizeof (ok));
        for (int k = 0; k < m; ++ k)
        if (h[k] > mid)
        {
            for (int i = x[k]; i < x[k] + l[k]; ++ i)
            for (int j = y[k]; j < y[k] + l[k]; ++ j)
            ok[i][j] = 1;
        }
        bool solo = 0;
        memset (s, 0, sizeof (s));
        for (int i = 1; i + a - 1 <= L; ++ i)
        for (int j = 1; j + a - 1 <= L; ++ j)
        {
            bool Ok = 0;
            for (int x = i; x <= i + a - 1; ++ x)
            for (int y = j; y <= j + a - 1; ++ y)
            if (ok[x][y])
            Ok = 1;
            if (!Ok) 
            {
                solo = 1;
            }
        }
        if (solo)
        {
            sol = mid;
            sup = mid - 1;
        }
        else
        inf = mid + 1;
    }
    cout << sol;
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