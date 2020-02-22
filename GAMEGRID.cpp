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

int a[mm][mm], b[mm][mm];
bool ok[mm][mm];

struct Z
{
    int a, b, c, d;
    Z (){}
    Z (int A, int B, int C, int D)
    {
        a = A; b = B; c = C; d = D;
    }
};

vector<Z> solv;


void F (int i, int j, int k, int l)
{
    if (i > k || j > l) return;
    for (int I = i; I <= k; ++ I)
    for (int J = j; J <= l; ++ J)
    b[I - i + 1][J - j + 1] = a[I][J];
    int sol = INT_MAX, soli, solj;
    for (int I = 1; I <= k - i + 1; ++ I)
    for (int J = 1; J <= l - j + 1; ++ J)
    {
        b[I][J] += b[I][J - 1] + b[I - 1][J] - b[I - 1][J - 1];
        if (ok[I][J]) continue;
        if (I * J - abs (b[I][J]) < sol)
        {
            sol = I * J - abs (b[I][J]);
            soli = I; solj = J;
        }
    }
    if (sol == INT_MAX) return;
    solv.emplace_back(i, j, i + soli - 1, j + solj - 1);
    if (i - j + 1 <= 300 && k)
    ok[soli][solj] = 1;
    ok[solj][soli] = 1;
    F (i, j + solj, k, l);
    F (i + soli, j, k, j + solj - 1);
}


void enter()
{
    int n;
    read (n);
    for (int i = 1; i <= n; ++ i)
    for (int j = 1; j <= n; ++ j)
    {
        read (a[i][j]);
        if (!a[i][j]) a[i][j] = - 1;
    }
    F (1, 1, n, n);
    cout << solv.size() << "\n";
    for (auto x : solv)
    cout << x.a << " " << x.b << " " << x.c << " " << x.d << "\n";
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

