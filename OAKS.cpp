#include <bits/stdc++.h>

#define fn "test"
#define fn1 "OAKS"

using namespace std;

const int mn = 3 * (int)(1e5) + 10;
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

#define y1 __y1
int x[mn], y[mn];


struct Z
{
    int l, r;
    Z (){}
    Z (int L, int R)
    {
        l = L; r = R;
    }
} no[20 * mn];
vector<Z> no1[20 * mn];
int N = 1;
vector<int> vx, vy;
vector<int> it[20 * mn];


void AddNode (int id)
{
    if (!no[id].l) no[id].l = ++N;
    if (!no[id].r) no[id].r = ++N;
}


void AddNode1 (int id1, int id)
{
    if (no1[id1][id].l) return;
    it[id1].emplace_back (0);
    it[id1].emplace_back (0);
    no1[id1].emplace_back(0, 0);
    no1[id1].emplace_back(0, 0);
    no1[id1][id] = Z (it[id1].size() - 2, it[id1].size() - 1);
}

void ud1 (int id1, int id2, int l, int r, int y)
{
    if (l > y || r < y) return;
    if (l == r)
    {
        ++ it[id1][id2];
        return;
    }
    int m = (l + r) >> 1;
    AddNode1 (id1, id2);
    ud1 (id1, no1[id1][id2].l, l, m, y);
    ud1 (id1, no1[id1][id2].r, m + 1, r, y);
    it[id1][id2] = it[id1][no1[id1][id2].l] + it[id1][no1[id1][id2].r];
}

void ud (int id, int l, int r, int x, int y)
{
    if (l > x || r < x) return;
    if (l == r)
    {
        if (!it[id].size()) 
        {
            it[id].emplace_back (0);
            it[id].emplace_back (0);
            no1[id].emplace_back(0, 0);
            no1[id].emplace_back(0, 0);
        }
        ud1 (id, 1, 1, vy.size(), y);
        return;
    }
    int m = (l + r) >> 1;
    AddNode (id);
    ud (no[id].l, l, m, x, y);
    ud (no[id].r, m + 1, r, x, y);
    if (!it[id].size()) 
    {
        it[id].emplace_back (0);
        it[id].emplace_back (0);
        no1[id].emplace_back(0, 0);
        no1[id].emplace_back(0, 0);
    }
    ud1 (id, 1, 1, vy.size(), y);
}

int qu1 (int id1, int id2, int l, int r, int a, int b)
{
    if (!id2) return 0;
    if (l > b || r < a) return 0;
    if (l >= a && r <= b) return it[id1][id2];
    int m = (l + r) >> 1;
    return qu1 (id1, no1[id1][id2].l, l, m, a, b) + 
           qu1 (id1, no1[id1][id2].r, m + 1, r, a, b);
}

int qu (int id, int l, int r, int x1, int x2, int y1, int y2)
{
    if (l > x2 || r < x1) return 0;
    if (!id) return 0;
    if (l >= x1 && r <= x2)
    {
        cerr << l << " " << r << " " << qu1 (id, 1, 1, vy.size(), y1, y2) << "\n";
        return qu1 (id, 1, 1, vy.size(), y1, y2);
    }
    int m = (l + r) >> 1;
    return qu (no[id].l, l, m, x1, x2, y1, y2) + 
           qu (no[id].r, m + 1, r, x1, x2, y1, y2);
}

void enter()
{
    int n;
    read (n);
    for (int i = 0; i < n; ++ i)
    {
        read (x[i]); read (y[i]);
        vx.emplace_back(x[i]);
        vy.emplace_back(y[i]);
    }
    sort (vx.begin(), vx.end());
    sort (vy.begin(), vy.end());
    vx.resize(unique (vx.begin(), vx.end()) - vx.begin());
vy.resize (unique(vy.begin(), vy.end()) - vy.begin());
    for (int i = 0; i < n; ++ i)
    {
        x[i] = lower_bound(vx.begin(), vx.end(), x[i]) - vx.begin() + 1;
        y[i] = lower_bound(vy.begin(), vy.end(), y[i]) - vy.begin() + 1;
        // cerr << i << "\n";
        ud (1, 1, vx.size(), x[i], y[i]);
    }
    int q;
    read (q);
    for (int i = 0; i < q; ++ i)
    {
        int x1, y1, x2, y2;
        read (x1); read (y1); read (x2); read (y2);
        x1 = lower_bound (vx.begin(), vx.end(), x1) - vx.begin() + 1;
        y1 = lower_bound (vy.begin(), vy.end(), y1) - vy.begin() + 1;
        x2 = upper_bound (vx.begin(), vx.end(), x2) - vx.begin();
        y2 = upper_bound (vy.begin(), vy.end(), y2) - vy.begin();
        write (qu (1, 1, vx.size(), x1, x2, y1, y2));
        putchar('\n');
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