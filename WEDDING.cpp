#include <bits/stdc++.h>

#define fn "test"
#define fn1 "WEDDING"

using namespace std;

const int mn = 2 * (int)(1e6) + 10;
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

int mod, s[mn], t[mn], x[mn], p[mn];

void attemp (int id, int a, int b)
{
    if (id == a + b)
    {
        bool ok = 1;
        for (int i = 0; i < a; ++ i)
        s[i] = x[i];
        for (int i = a; i < a + b; ++ i)
        t[i - a] = x[i];
        for (int i = 0; i < a; ++ i)
        for (int j = 0; j < b; ++ j)
        if ((s[i] * t[j]) % mod != p[i * a + j]) ok = 0; 
        if (ok) 
        {
            cout << "YES\n";
            cout << a << " ";
            for (int i = 0; i < a; ++ i)
            cout << s[i] << " ";
            cout << "\n";
            cout << b << " ";
            for (int i = 0; i < b; ++ i)
            cout << t[i] << " ";
            exit(0);
        }
        return;
    }
    for (int i = 0; i < mod; ++ i)
    {
        x[id] = i;
        attemp (id + 1, a, b);
    }
}

void enter()
{
    int k;
    cin >> k >> mod;
    for (int i = 0; i < k; ++ i)
    cin >> p[i];
    if (k <= 12 && mod == 7)
    {
        for (int i = 2; i < k; ++ i)
        if (k % i == 0)
        attemp (0, i, k / i);
        cout << "NO";
        return;
    }
    if (mod == 2)
    {
        for (int m = 2; m < k; ++ m)
        if (k % m == 0)
        {
            int n = k / m;
            for (int i = 0; i < m; ++ i)
            s[i] = 0;
            for (int i = 0; i < n; ++ i)
            t[i] = 0;
            for (int i = 0; i < m; ++ i)
            for (int j = 0; j < n; ++ j)
            if (p[i * n + j])
            s[i] = t[j] = 1;
            bool ok = 1;
            for (int i = 0; i < m; ++ i)
            for (int j = 0; j < n; ++ j)
            if ((s[i] * t[j]) % 2 != p[i * n + j])
            ok = 0;
            if (ok)
            {
                cout << "YES\n";
                cout << m << " ";
                for (int i = 0; i < m; ++ i)
                cout << s[i] << " ";
                cout << "\n";
                cout << n << " ";
                for (int i = 0; i < n; ++ i)
                cout << t[i] << " ";
                return;
            }
        }
        cout << "NO";
        return;
    }
    cout << "NO";
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