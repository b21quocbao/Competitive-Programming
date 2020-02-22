#include <bits/stdc++.h>

#define fn "test"
#define fn1 "GUIDE"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
struct node
{
    int l, r, v;
};
int nit;
node it[4 * mn];
int n, a[mn], id[mn], b[mn], c[mn], id2[mn], rv[mn], Id[mn];

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

int ud (int oldId, int l, int r, int x)
{
    int Nid = (++ nit);
    if (l == r) return Nid;
    int m = (l + r) >> 1;
    if (x <= m)
    {
        it[Nid].r = it[oldId].r;
        it[Nid].l = ud (it[oldId].l, l, m, x);
    }
    else
    {
        it[Nid].l = it[oldId].l;
        it[Nid].r = ud (it[oldId].r, m + 1, r, x);
    }
    return Nid;
}

int initit (int l, int r)
{
    int Nid = (++nit);
    if (l == r) return (Nid);
    int m = (l + r) >> 1;
    it[Nid].l = initit (l, m);
    it[Nid].r = initit (m + 1, r);
    return Nid;
}

int qu (int id, int l, int r, int x)
{
    if (l >= x) return 0;
    if (r < x) return it[id].v;
    int m = (l + r) >> 1;
    return max (qu (it[id].l, l, m, x), 
    qu (it[id].r, m + 1, r, x));
}

void Ud (int id, int l, int r, int x, int k)
{
    if (l > x || r < x) return;
    if (l == r) 
    {
        it[id].v = k;
        return;
    }
    int m = (l + r) >> 1;
    Ud (it[id].l, l, m, x, k);
    Ud (it[id].r, m + 1, r, x, k);
    it[id].v = max (it[it[id].l].v, it[it[id].r].v);
}

void enter()
{
    cin >> n;
    for (int i = 1; i <= n; ++ i)
    {
        cin >> a[i];
        id[i] = i;
    }
    for (int i = 1; i <= n; ++ i)
    {
        cin >> b[i];
        id2[i] = i;
    }
    sort (id + 1, id + n + 1, [](int i, int j)
         {
             return a[i] < a[j];
         });
    sort (c + 1, c + n + 1);
    int m = unique (c + 1, c + n + 1) - c;
    for (int i = 1; i <= n; ++ i)
    rv[id[i]] = i;
    Id[0] = initit (1, n);
    for (int i = 1; i <= n; ++ i)
    Id[i] = ud (Id[i - 1], 1, n, id[i]);
    int sol = 0;
    for (int i = 1; i <= n; ++ i)
    {
        int j = lower_bound (c + 1, c + m + 1, b[i]) - c;
        int r = qu (Id[rv[i]], 1, n, j) + 1;
        Ud (Id[rv[i]], 1, n, j + 1, r);
        sol = max (sol, r);
    }
    cout << sol;
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


