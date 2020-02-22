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
string s;
int n, id[mn], pos[mn], cnt[mn], idm[mn], posm[mn], lc[mn][17], lo2[mn], bi[mn], rmid[mn][17];
int tr[mn], a, b, f[mn];

int mo (int k)
{
    if (k > n) k -= n;
    return k;
}

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

void pre_sa()
{
    s.push_back('#');
    ++ n;
    memset (cnt, 0, sizeof (cnt));
    for (int i = 1; i <= n; ++ i)
    {
        id[i] = i;
        pos[i] = s[i];
        ++ cnt[pos[i]];
    }
    for (int j = 0; ; (!j ? ++ j : j <<= 1))
    {
        for (int i = 1; i <= n; ++ i)
        {
            idm[i] = id[i] - j;
            if (idm[i] < 1) idm[i] += n;
        }
        for (int i = 1; i <= max (n, 256); ++ i)
        cnt[i] += cnt[i - 1];
        for (int i = n; i >= 1; -- i)
        id[cnt[pos[idm[i]]] --] = idm[i];
        memset (cnt, 0, sizeof (cnt));
        int r = 1;
        for (int i = 1; i <= n; ++ i)
        {
            posm[id[i]] = r;
            ++ cnt[r];
            if (i == n) continue;
            if (pos[id[i]] != pos[id[i + 1]]) ++ r;
            else if (pos[mo (id[i] + j)] != pos[mo (id[i + 1] + j)]) ++ r;
        }
        swap (pos, posm);
        if (r == n) break;
    }
    int r = 0;
    for (int i = 1; i <= n; ++ i)
    if (pos[i] != n)
    {
        if (r) -- r;
        while (s[i + r] == s[id[pos[i] + 1] + r]) ++ r;
        lc[pos[i]][0] = r;
    }
}

void pre_rmq()
{
    for (int i = 1; i <= 16; ++ i)
    for (int j = 1; j <= n; ++ j)
    lc[j][i] = min (lc[j][i - 1], lc[j + (1 << (i - 1))][i - 1]);
}

int qu_rmq (int a, int b)
{
    -- b;
    if (a > b) return n + 5;
    int l = lo2[b - a + 1];
    return (min (lc[a][l], lc[b - (1 << l) + 1][l]));
}

void ub (int x, int i)
{
    for (; x < mn; x += x & - x)
    bi[x] = i;
}

int db (int x, bool ok)
{
    int sol = 0;
    for (; x >= 1; x -= x & - x)
    if (bi[x])
    {
        if (!sol) 
        {
            sol = bi[x];
            continue;
        }
        if (ok) sol = min (sol, bi[x]);
        else sol = max (sol, bi[x]);
    }
    return sol;
}

void pre_tr()
{
    pre_sa();
    pre_rmq();
}

void init_rmq_id()
{
    for (int i = 1; i <= n; ++ i)
    rmid[i][0] = id[i];
    for (int j = 1; j <= 16; ++ j)
    for (int i = 1; i <= n; ++ i)
    rmid[i][j] = min (rmid[i][j - 1], rmid[i + (1 << (j - 1))][j - 1]);
}

int qu_rmq_id (int l, int r)
{
    int lo = lo2[r - l + 1];
    return min (rmid[l][lo], rmid[r - (1 << lo) + 1][lo]);
}

void enter()
{
    cin >> n >> a >> b;
    cin >> s;
    s = '#' + s;
    memset (f, 0, sizeof (f));
    pre_tr();
    int i = 1;
    int sol = 0;
    init_rmq_id();
    for (int i = 1; i < n; ++ i)
    {
        int inf = 1, sup = (i >> 1), res = - 1;
        while (inf <= sup)
        {
            int l, r;
            int k = (inf + sup) >> 1;
            int po = pos [i - k + 1];
            int ll = 1, rr = po;
            while (ll <= rr)
            {
                int mid = (ll + rr) >> 1;
                if (qu_rmq (mid, po) >= k)
                {
                    l = mid;
                    rr = mid - 1;
                }
                else ll = mid + 1;
            }
            ll = po; rr = n;
            while (ll <= rr)
            {
                int mid = (ll + rr) >> 1;
                if (qu_rmq (po, mid) >= k)
                {
                    r = mid;
                    ll = mid + 1;
                }
                else rr = mid - 1;
            }
            if (qu_rmq_id (l, r) <= i - 2 * k + 1)
            {
                res = k;
                inf = k + 1;
            }
            else sup = k - 1;
        }
        f[i] = f[i - 1] + a;
        if (res != - 1) f[i] = min (f[i], f[i - res ] + b);
        //cout << i << " " << f[i] << " " << res << "\n";
    }
    cout << f[n - 1] << "\n";
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
    cin>>ntest;
    int r = 1;
    for (int i = 2; i < mn; ++ i)
    {
        if (i == (1 << (r + 1))) ++ r;
        lo2[i] = r;
    }
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}