#include <bits/stdc++.h>

#define fn1 "PERIOD2"

using namespace std;

const int mn = 5 * int(1e5) + 10;
const int mod = 1 * int(1e5) + 10;
const int mm = 1 * int(1e5) + 10;

int tt, ntest = 1;
int pr[mn];
int n;
int po[mn];
int rmq[mn][19];
vector<int> pos, posm;

void docfile()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (ifstream("test.inp"))
    {
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    }else if (ifstream(fn1".inp"))
    {
        freopen(fn1".inp", "r", stdin);
        freopen(fn1".out", "w", stdout);
    }
}

template <typename T> inline T read(T& x)
{
    x = 0; T f = 1;
    char ch = getchar();
    while (!isdigit(ch)) f = ch == '-' ? - f : f, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    x *= f;
}

template <typename T>
inline void write(T a)
{
    int i = 0;
    char S[20];
    if (a == 0) {putchar('0'); return;}
    while(a > 0)
    {
        S[i++] = a % 10 + '0';
        a /= 10;
    }
    --i;
    while(i >= 0) putchar(S[i--]);
}

void enter()
{
}

inline int mo (int a, int n)
{
    if (a > n) a -= n;
    if (a < 0) a += n;
    return a;
}

void prermq ()
{
    for (int i = 1; i <= 18; ++ i)
    for (int j = 0; j + (1 << i) - 1 < n; ++ j)
    rmq[j][i] = min (rmq[j][i - 1], rmq [j + (1 << (i - 1))][i - 1]);
}

void eros (int n)
{
    for (int i = 2; i <= trunc(sqrt (n)); ++ i)
    if (!pr[i])
    for (int j = i * i; j <= n; j += i)
    if (!pr[j])
    pr[j] = i;
    for (int i = 2; i <= n; ++ i)
    if (!pr[i])
    pr[i] = i;
}

int que (int l, int r)
{
    l = pos[l]; r = pos[r];
    if (l > r) swap (l, r);
    -- r;
    int lo = po[r - l + 1];
    return min (rmq[l][lo], rmq[r - (1 << lo) + 1][lo]);
}

void process ()
{
    int m;
    read (m);
    for (int i = 0; i < m; ++ i)
    {
        int l, r;
        read (l); read (r);
        -- l; -- r;
        int d = r - l + 1, D = d;
        while (D != 1)
        {
            int k = d / pr[D];
            if (que (l, l + k) >= r - (l + k) + 1)
            d /= pr[D];
            D /= pr[D];
        }
        write (d);
        putchar ('\n');
    }
}

void solve()
{
    read (n);
    ++ n;
	string s;
    s.reserve (n);
    char c = getchar ();
    while (isalpha (c))
    {
        s.push_back(c);
        c = getchar();
    }
	s.push_back(c);
	int N = n + 256;
	vector<int> id (n), idm(n);
    pos.resize(n), posm.resize(n);
	vector<int> lcp(n), l(n), r(n);
	vector<int> cnt (N);
	for (int i = 0; i < n; ++ i) {idm[i] = id[i] = i; pos[i] = s[i]; ++ cnt[pos[i]];};
    for (int k = 0;; k ? k *= 2 : k++)
	{
        for (int i = 1; i < N; ++ i)
        cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; -- i)
        id[-- cnt[pos[idm[i]]]] = idm[i];
		int r = 0; fill(cnt.begin(), cnt.end(), 0);
		int k1 = k ? k * 2 : k + 1;
        for (int i = 0; i < n; ++ i)
        {
            if (i && pos[id[i]] != pos[id[i - 1]]) ++ r;
            else if (i && pos[mo (id[i] + k, n)] != pos[mo (id[i - 1] + k, n)]) ++ r;
            posm[id[i]] = r;
            idm[i] = mo (id[i] - k1, n);
            ++ cnt[r];
        }
        pos = posm;
        if (r == n - 1) break;
	}
	int k = 0;
	for (int i = 0; i < n; ++ i)
	if (pos[i] != n - 1)
	{
        while (s[i + k] == s[id[pos[i] + 1] + k]) ++ k;
        rmq[pos[i]][0] = k;
        if (k) -- k;
	}
	long long sol = 0;
    s.pop_back();
    prermq();
    eros (500000);
    process();
}

void print_result()
{

}

int main()
{
    docfile();
    int cn = 0;
    for (int i = 1; i <= 500000; ++ i)
    {
        if ((1 << (cn + 1)) == i)
        ++ cn;
        po[i] = cn;
    }
    //cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}
