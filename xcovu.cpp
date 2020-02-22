#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 << 10;
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

int n, m, k;
string ver[mn], hor[mn];

void enter()
{
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++)
	{
		cin >> ver[i];
	}
	for(int i=0;i<n-1;i++)cin>>hor[i];
}
int a[mn][mn];
void solve_by_n()
{
	int sum = 0;
    for(int i = 0; i < n; i++)
    {
        a[i][0] = 1;
        for(int j = 1; j < m; j++)
    		if(ver[i][j - 1] == 'E') a[i][j] = a[i][j - 1];
    		else a[i][j] = a[i][j - 1] ^ 1;

		sum += m - 1;

		if(i != 0)
		{
			int cnt = 0;
			for(int j = 0; j < m; j++)
                if(hor[i - 1][j] == 'E' && a[i][j] == a[i - 1][j]) cnt++;
				else if(hor[i - 1][j] == 'N' && a[i][j] != a[i - 1][j]) cnt++;

			sum += max(cnt, m - cnt);

    		if(cnt < (m - cnt))
    			for(int j = 0; j < m; j++)
    				a[i][j] ^= 1;
    	}
    }

    if(4 * sum < 3 * (n * (m - 1) + (n - 1) * m)) { return; }
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cout << a[i][j] + 1 << " \n"[j == m - 1];
	exit(0);
}
void solve_by_m()
{
	int sum = 0;
    for(int j = 0; j < m; j++)
    {
        a[0][j] = 1;
        for(int i = 1; i < n; i++)
    		if(hor[i - 1][j] == 'E') a[i][j] = a[i - 1][j];
    		else a[i][j] = a[i - 1][j] ^ 1;

		sum += n - 1;

		if(j != 0)
		{
			int cnt = 0;
			for(int i = 0; i < n; i++)
                if(ver[i][j - 1] == 'E' && a[i][j] == a[i][j - 1]) cnt++;
				else if(ver[i][j - 1] == 'N' && a[i][j] != a[i][j - 1]) cnt++;

			sum += max(cnt, n - cnt);

    		if(cnt < n - cnt)
    			for(int i = 0; i < n; i++)
    				a[i][j] ^= 1;
    	}
    }
    if(4 * sum < 3 * (n * (m - 1) + (n - 1) * m)) {return;}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cout << a[i][j] + 1 << " \n"[j == m - 1];
	exit(0);
}
void solve()
{
	if(k == 1)
	{
		int cnt = 0;
		for(int i = 0; i < n; i++)
		{
			for(char c: ver[i]) cnt += (c == 'E');
			for(char c: hor[i]) cnt += (c == 'E');
		}

		if(4 * cnt < 3 * (n * (m - 1) + (n - 1) * m)) { cout <<-1<< endl; return; }
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cout << 1 << " \n"[j == m - 1];

		return;
	}

	solve_by_n();
	solve_by_m();
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