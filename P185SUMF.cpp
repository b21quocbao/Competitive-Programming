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

void enter()
{
    int n;
    cin >> n;
    vector<int> a (n);
    for (int i = 0; i < n; ++ i)
    {
        cin >> a[i];
    }
    int sol = 0;
    while (1)
    {
        int inf = sol + 1, sup = a[0];
        int Res = sol;
        sol = - 1;
        while (inf <= sup)
        {
            if (inf == 1)
            {
                sol = 1;
                break;
            }
            int mid = (inf + sup) >> 1;
            if (a[0] / mid != a[0] / Res)
            {
                sol = mid;
                sup = mid - 1;
            }
            else inf = mid + 1;
        }
        if (sol == - 1) break;
        int res = a[0] / sol;
        for (int j = 0; j < 2; ++ j)
        {
            if (j)-- res;
            if (!res) continue;
            long long Sol = 0;
            bool ok = 1;
            for (int i = 0; i < n; ++ i)
            {
                if (a[i] % (res + 1) == 0)
                {
                    Sol += a[i] / (res + 1);
                    continue;
                }
                int y = a[i] / (res + 1) + 1;
                if (y * (res + 1) - a[i] > y)
                {
                    ok = 0;
                    break;
                }
                Sol += y;
            }
            if (ok)
            {
                cout << Sol;
                return;
            }
        }
    }
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