#include <bits/stdc++.h>

using namespace std;

int ntest = 1, itest;
int a[110][110];
int f[(1 << 20) + 10];

template <typename T>
void read (T& x)
{
    x = 0; T f = 1;
    char c = getchar();
    for (;!isdigit(c); c = getchar()) if (c == '-') f = - f;
    for (;isdigit(c); c = getchar())
    x = x * 10 + (c - '0');
    x *= f;
}

template <typename T>
void write (T x)
{
	if (x < 0)
	{
		putchar('-');
		write (- x);
		return;
	}
    if (x < 10)
	{
		putchar((char)('0' + x));
        return;
	}
	write (x / 10);
	putchar((char)('0' + (x % 10)));
}

void enter()
{
	int n, k;
	cin >> n >> k;
	if (n == k)
	{
		cout << 0;
		return;
	}
    for (int i = 0; i < n; ++ i)
    for (int j = 0; j < n; ++ j)
    cin >> a[i][j];
    int sol = INT_MAX;
    for (int k = 0; k < n; ++ k)
    for (int i = 0; i < n; ++ i)
	for (int j = 0; j < n; ++ j)
	a[i][j] = min (a[i][j], a[i][k] + a[k][j]);
    for (int i = (1 << n) - 2; i >= 0; -- i)
    {
    	f[i] = INT_MAX;
    	int cn = 0;
    	for (int j = 0; j < n; ++ j)
		if ((i >> j) & 1) ++ cn;
		if (cn < k) continue;
		bool ok = 0;
        for (int j = 0; j < n; ++ j)
		if (((i >> j) & 1) == 0)
        {
        	if (ok) continue;
        	ok = 0;
            int I = i;
            I ^= (1 << j);
            for (int k = 0; k < n; ++ k)
			if ((i >> k) & 1)
            f[i] = min (f[i], f[I] + a[j][k]);
        }
        if (cn == k) sol = min (sol, f[i]);
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
	ios::sync_with_stdio(false);
	freopen("test.INP", "r", stdin);
	freopen("test.OUT", "w", stdout);
	//cin >> ntest;
	for (itest = 1; itest <= ntest; ++ itest)
	{
        enter();
        solve();
        print_result();
	}
}
