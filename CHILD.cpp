#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e4) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int L, a, m, h[110], l[110], x[110], y[110];
vector<int> v;
vector<int> v1[mn], v2[mn];
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
        v.push_back(y[i]);
        v.push_back(y[i] + l[i]);
    }
    v.push_back(1);
    v.push_back(L + 1);
    sort (v.begin(), v.end());
    v.resize(unique (v.begin(), v.end()) - v.begin());
    int inf = 1, sup = 255, sol;
    while (inf <= sup)
    {
        int mid = (inf + sup) >> 1;
        for (int i = 0; i < m; ++ i)
        if (h[i] > mid)
        {
            v1[x[i]].push_back(i);
            if (x[i] + l[i] <= L)
            v2[x[i] + l[i]].push_back(i);
        }
        bool ok = 0;
        memset (s, 0, sizeof (s));
        for (int i = 1; i <= L; ++ i)
        {
            if (ok) break;
            while (v1[i].size())
            {
                int x = v1[i].back();
                v1[i].pop_back();
                for (int i = id (y[x]); i < id (y[x] + l[x]); ++ i)
                if (s[i] >= 0) s[i] = - 1; else -- s[i];
            }
            while (v2[i].size())
            {
                int x = v2[i].back();
                v2[i].pop_back();
                for (int i = id (y[x]); i < id (y[x] + l[x]); ++ i)
                ++ s[i];
            }
            for (int j = 0; j < v.size(); ++ j)
            if (s[j] >= 0) ++ s[j];
            int r = - 1, mi = INT_MAX;
            for (int j = 0; j < v.size() - 1; ++ j)
            {
                if (r == - 1) r = j;
                mi = min (mi, s[j]);
                if (s[j] == - 1)
                {
                    mi = INT_MAX;
                    r = - 1;
                    continue;
                }
                if (v[j + 1] - v[r] >= a && mi >= a) 
                {
                    ok = 1;
                    break;
                }
            }
        }
        if (ok)
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