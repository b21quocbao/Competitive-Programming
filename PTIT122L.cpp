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

bool ok[100][100];
string s[100];
int hx[4] = {0, 1, 0, - 1};
int hy[4] = {1, 0, - 1, 0};

void enter()
{
    int m, n;
    cin >> m >> n;
    cin.ignore();
    for (int i = 0; i < m; ++ i)
    for (int j = 0; j < n; ++ j)
    ok[i][j] = 0;
    for (int i = 0; i < m; ++ i)
    getline (cin, s[i]);
    for (int i = 0; i < m; ++ i)
    for (int j = 0; j < n; ++ j)
    if (s[i][j] == 'B')
    {
        int cn = 0;
        int H1 = - 1;
        for (int h = 0; h < 4; ++ h)
        {
            int I = i + hx[h], J = j + hy[h];
            if (I >= 0 && I < m && J >= 0 && J < n && s[I][J] == 'W')
            {
                ++ cn;
                if (cn > 2 || ok[I][J] || abs (h - H1) == 2)
                {
                    cout << "NO";
                    return;
                }
                ok[I][J] = 1;
                H1 = h;
            }
        }
        if (cn != 2) 
        {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
}

void solve()
{
    cout << "\n";
}

void print_result()
{

}

int main()
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