#include <bits/stdc++.h>

#define fn "test"
#define fn1 "lines"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int a[mm][mm], b[mm][mm];

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

int F (vector<int> A)
{
    map <int, int> MAP;
    vector<int> B (A.size());
	for (int i = 0; i < A.size(); ++ i) MAP[A[i]]=B[i]=i;
	sort(B.begin(), B.end());
	int ans=0;
	for (int i=0; i< A.size(); i++) 
    if (B[i]!=A[i])
	{
		int pos_in_A=MAP[B[i]], temp;
		//swap(MAP[A[i]], MAP[A[pos_in_A]]);
		temp=MAP[A[i]];
		MAP[A[i]]=MAP[A[pos_in_A]];
		MAP[A[pos_in_A]]=temp;
		//swap(A[i], A[pos_in_A]);
		temp=A[i];
		A[i]=A[pos_in_A];
		A[pos_in_A]=temp;
		ans++;
	}
    return ans;
}

void enter()
{
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; ++ i)
    for (int j = 0; j < n; ++ j)
    {
        cin >> a[i][j];
        -- a[i][j];
        b[i][j] = a[i][j];
    }
    for (int j = 0; j < n; ++ j)
    {
        int k = a[0][j] % n;
        for (int i = 0; i < m; ++ i)
        if (a[i][j] % n != k)
        {
            cout << "*";
            return;
        }
    }
    for (int i = 0; i < m; ++ i)
    {
        sort (b[i], b[i] + n);
        if (b[i][0] % n) 
        {
            cout << "*";
            return;
        }
        for (int j = 0; j < n - 1; ++ j)
        if (b[i][j + 1] != b[i][j] + 1)
        {
            cout << "*";
            return;
        }
    }
    vector<int> v1, v2;
    for (int i = 0; i < m; ++ i)
    v1.emplace_back(a[i][0] / n);
    for (int i = 0; i < n; ++ i)
    v2.emplace_back(a[0][i] % n);
    cout << F (v1) + F (v2);
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