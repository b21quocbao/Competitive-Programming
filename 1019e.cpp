/*
Code by b21
Time: 22:53 Thu 17/10/2019
*/

#include <bits/stdc++.h>

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
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
   else if (ifstream("1019e.inp"))
    {
        freopen("1019e.inp", "r", stdin);
        freopen("1019e.out", "w", stdout);
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

#define double long double

double n, p, s, v;


double f (double c)
{
    return -((n * pow (log2 (n), c * sqrt (2)) / p / 1e9) + (s * (1 + 1 / c) / v));
}

void max_f(double left, double right) {

	int N_ITER = 1000000;

	for (int i = 0; i < N_ITER; i++) {

		double x1 = left + (right - left) / 3.0;
		double x2 = right - (right - left) / 3.0;

		if (f(x1) > f(x2)) right = x2;
		else left = x1;
	}
    cout << fixed << setprecision(10) << -f(left) << " " << left << "\n";
}

void enter()
{
    cin >> n >> p >> s >> v;
    max_f (1e-8, 10000);
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
    //cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}