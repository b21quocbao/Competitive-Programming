/**
 *	 Code by b21
 *	 Time: 20:27 Fri 06/03/2020
**/

#include <bits/stdc++.h>

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 2 * (int)(1e5) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
void docfile()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (ifstream("test.inp"))
    {
       freopen("test.inp", "r", stdin);
       if (!aNs) freopen("test.out", "w", stdout);
       else freopen ("test.ans", "w", stdout);
    }
   else if (ifstream("LAZER.inp"))
    {
        freopen("LAZER.inp", "r", stdin);
        freopen("LAZER.out", "w", stdout);
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

vector<pair<int, int> > e[mn];
vector<int> v;
int la[4 * mm], it[4 * mm];
int y[mn], l[mn], r[mn], id[mn], Y[mn], s[mn];

void lazy (int id) {
    ++ it[id];
    ++ la[id];
}

void layd (int id) {
    int i = id * 2;
    la[i] += la[id];
    la[i + 1] += la[id];
    it[i] += la[id];
    it[i + 1] += la[id];
    la[id] = 0;
}

void init (int id = 1, int l = 1, int r = v.size()) {
    it[id] = 0;
    if (l == r) return;
    int i = id << 1, m = (l + r) >> 1;
    init (i, l, m);
    init (i + 1, m + 1, r);
}

void ud (int a, int b, int id = 1, int l = 1, int r = v.size()) {
    if (r < a || l > b) return;
    if (l >= a && r <= b) {
        lazy(id);
        return;
    }
    int i = id << 1, m = (l + r) >> 1;
    ud (a, b, i, l, m);
    ud (a, b, i + 1, m + 1, r);
}

int qu (int x, int id = 1, int l = 1, int r = v.size()) {
    if (r < x || l > x) return 0;
    if (l == r) return it[id];
    int i = id << 1, m = (l + r) >> 1;
    layd (id);
    return qu (x, i, l, m) + qu (x, i + 1, m + 1, r);
}

void enter()
{
    int n, q;
    cin >> n >> q;
    v.clear();
    for (int i = 1; i <= n; ++ i)
    {
        e[i].clear();
        cin >> y[i];
        v.emplace_back(y[i]);
    }
    for (int i = 0; i < q; ++ i) {
        id[i] = i;
        s[i] = 0;
        cin >> l[i] >> r[i] >> Y[i];
        e[l[i]].emplace_back(i, 1);
        e[r[i]].emplace_back(i, - 1);
        v.emplace_back(Y[i]);
    }
    sort (v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for (int i = 1; i <= n; ++ i)
    y[i] = lower_bound(v.begin(), v.end(), y[i]) - v.begin() + 1;
    for (int i = 0; i < q; ++ i)
    Y[i] = lower_bound(v.begin(), v.end(), Y[i]) - v.begin() + 1;
    sort (id, id + q, [](int i, int j) {
        return l[i] < l[j];
    });
    init();
    for (int i = 1; i <= n; ++ i) {
        for (auto j : e[i])
        s[j.first] += - j.second * qu (Y[j.first]);
        ud (min (y[i], y[i + 1]), max (y[i], y[i + 1]));
    }
    for (int i = 0; i < q; ++ i)
    cout << s[i] << "\n";
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
    cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
} 