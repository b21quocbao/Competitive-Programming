#include <bits/stdc++.h>

#define fn "test"
#define fn1 "FIND"

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
int n, m, ver[mn], a[mn], id[mn];
node it[mn * 20];
int nit = 1;

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
    cin >> n >> m;
    for (int i = 0; i < n; ++ i)
    {
        cin >> a[i];
        id[i] = i;
    }
    sort (id, id + n, [](int i, int j)
         {
              return a[i] < a[j];
         });
}

int query (int id, int l, int r, int a, int b)
{
    if (l >= a && r <= b) return it[id].v;
    if (b < l || a > r) return 0;
    int m = (l + r) >> 1;
    return query (it[id].l, l, m, a, b) + query (it[id].r, m + 1, r, a, b);
}

int ud (int l, int r, int u, int od)
{
    if (l == r)
    {
        it[nit] = {0, 0, 1};
        return nit ++;
    }
    int ik = nit ++;
    int m = (l + r) >> 1;
    if (u <= m)
    {
        it[ik].l = ud (l, m, u, it[od].l);
        it[ik].r = it[od].r;
    }
    else
    {
        it[ik].l = it[od].l;
        it[ik].r = ud (m + 1, r, u, it[od].r);
    }
    it[ik].v = it[it[ik].l].v + it[it[ik].r].v;
    return ik;
}

void solve()
{
    for (int i = 0; i < n; ++ i)
    ver[i] = ud (0, n - 1, id[i], !i ? 1 : ver[i - 1]);
    for (int i = 0; i < m; ++ i)
    {
        int l, r, k;
        cin >> l >> r >> k;
        -- l; -- r;
        int sol;
        for (int inf = 0, sup = n - 1; inf <= sup;)
        {
            int mid = (inf + sup) >> 1;
            if (query (ver[mid], 0, n - 1, l, r) >= k)
            {
                sol = a[id[mid]];
                sup = mid - 1;
            }
            else inf = mid + 1;
        }
        cout << sol << "\n";
    }
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