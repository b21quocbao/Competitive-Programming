#include <bits/stdc++.h>

#define int int64_t
#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * int(1e5) + 10;
const int mod = 1 * int(1e5) + 10;
const int mm = 1 * int(1e5) + 10;

int tt, ntest = mod;
long long gt[20];
int it[110];

void docfile()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (ifstream(fn".inp"))
    {
        freopen(fn".inp", "r", stdin);
        freopen(fn".out", "w", stdout);
    }else if (ifstream(fn1".inp"))
    {
        freopen(fn1".inp", "r", stdin);
        freopen(fn1".out", "w", stdout);
    }
}

template<typename T> inline void read(T& x)
{
    T f = 1; x = 0;
    char ch = getchar();
    while (!isdigit(ch)) f = ch == '-' ? - f : f, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    x *= f;
}

template<typename T> void write(const T& a)
{
	if (a < 0)
	{
		putchar ('-');
        write (-a);
        return;
	}
	if (a >= 10) write (a / 10);
	putchar('0' + a % 10);
}

template<typename T> void writeln(const T& a)
{
    write (a);
    putchar('\n');
}

int Id (int id, int l, int r, int x)
{
	if (l == r) return l;
	int m = (l + r) >> 1;
    if (it[id << 1] >= x) return Id (id << 1, l, m, x);
    return Id ((id << 1) ^ 1, m + 1, r, x - it[id << 1]);
}

void initit (int id, int l, int r)
{
	if (l == r)
	{
		it[id] = 1;
		return;
	}
	int m = (l + r) >> 1;
	initit (id << 1, l, m);
	initit ((id << 1) ^ 1, m + 1, r);
	it[id] = it[id << 1] + it[(id << 1) ^ 1];
}

void ud (int id, int l, int r, int x)
{
	if (l > x || r < x) return;
	if (l == r)
	{
		-- it[id];
		return;
	}
	int m = (l + r) >> 1;
	ud (id << 1, l, m, x);
	ud ((id << 1) ^ 1, m + 1, r, x);
	it[id] = it[id << 1] + it[(id << 1) ^ 1];
}

int qu (int id, int l, int r, int x)
{
	if (l > x) return 0;
    if (r <= x) return it[id];
    int m = (l + r) >> 1;
    return qu (id << 1, l, m, x) + qu ((id << 1) ^ 1, m + 1, r, x);
}

void enter()
{
	int n, id;
	cin >> n;
	if (!n) exit(0);
	cin >> id;
    if (id == 1)
	{
		long long sol = 0;
		initit (1, 1, n);
		for (int i = n - 1; i >= 0; -- i)
		{
			long long x;
			cin >> x;
			if (!i) continue;
			ud (1, 1, n, x);
			sol += qu (1, 1, n, x) * gt[i];
		}
		cout << sol + 1 << "\n";
	}
	else
	{
		long long x;
        cin >> x;
        initit (1, 1, n);
        for (int i = n - 1; i >= 1; -- i)
		{
			int d = (x - 1) / gt[i];
			long long r = Id (1, 1, n, d + 1);
			cout << r << " ";
			ud (1, 1, n, r);
			x -= (d * gt[i]);
		}
		cout << Id (1, 1, n, 1);
		cout << "\n";
	}
}

void solve()
{

}

void print_result()
{

}

int32_t main()
{
    docfile();
    gt[1] = 1;
    for (int i = 2; i <= 15; ++ i)
	gt[i] = gt[i - 1] * i;
    //cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}
