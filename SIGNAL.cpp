#include <bits/stdc++.h>

#define fn "test"
#define fn1 "SIGNAL"

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

int x[mn], y[mn], s[mn];

void enter()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++ i)
    {
        cin >> x[i] >> y[i] >> s[i];
    }
    if (n <= k)
    {
        cout << fixed << setprecision(6) << 0;
        return;
    }
    #define y1 __y1
    if (k == 2)
    {
        double inf = 0, sup = 2e7, sol = - 1;
        inf = sup = 13361;
        for (int i = 1; i <= 500; ++ i)
        {
            double mid = (inf + sup) / 2;
            double May = -1e9, Miy = 1e9, Mix = 1e9, Max = -1e9;
            for (int i = 0; i < n; ++ i)
            {
                if (s[i] > 1e8 / mid) continue;
                double d = mid * s[i];
                double x1 = x[i] + y[i] - d;
                double x2 = x[i] + y[i] + d;
                double y1 = y[i] - x[i] - d;
                double y2 = y[i] - x[i] + d;
                May = max (May, y1);
                Miy = min (Miy, y2);
                Max = max (Max, x1);
                Mix = min (Mix, x2);
            }
            if (May > Miy || Max > Mix)
            {
                auto r1 = Mix, r2 = Miy;
                if (Max > Mix)
                {
                    double May = -1e9, Miy = 1e9, Mix = 1e9, Max = -1e9;
                    for (int i = 0; i < n; ++ i)
                    {
                        if (s[i] > 1e8 / mid) continue;
                        double d = mid * s[i];
                        double x1 = x[i] + y[i] - d;
                        double x2 = x[i] + y[i] + d;
                        double y1 = y[i] - x[i] - d;
                        double y2 = y[i] - x[i] + d;
                        if (x1 <= r1) continue;
                        May = max (May, y1);
                        Miy = min (Miy, y2);
                        Max = max (Max, x1);
                        Mix = min (Mix, x2);
                    }
                    if (May > Miy || Max > Mix)
                    {
                        inf = mid;
                        continue;
                    }
                    May = -1e9, Miy = 1e9, Mix = 1e9, Max = -1e9;
                    for (int i = 0; i < n; ++ i)
                    {
                        if (s[i] > 1e8 / mid) continue;
                        double d = mid * s[i];
                        double x1 = x[i] + y[i] - d;
                        double x2 = x[i] + y[i] + d;
                        double y1 = y[i] - x[i] - d;
                        double y2 = y[i] - x[i] + d;
                        if (x1 > r1) continue;
                        May = max (May, y1);
                        Miy = min (Miy, y2);
                        Max = max (Max, x1);
                        Mix = min (Mix, x2);
                    }
                    if (May > Miy || Max > Mix)
                    {
                        inf = mid;
                        continue;
                    }
                }
                else
                {
                    double May = -1e9, Miy = 1e9, Mix = 1e9, Max = -1e9;
                    for (int i = 0; i < n; ++ i)
                    {
                        if (s[i] > 1e8 / mid) continue;
                        double d = mid * s[i];
                        double x1 = x[i] + y[i] - d;
                        double x2 = x[i] + y[i] + d;
                        double y1 = y[i] - x[i] - d;
                        double y2 = y[i] - x[i] + d;
                        if (y1 <= r2) continue;
                        May = max (May, y1);
                        Miy = min (Miy, y2);
                        Max = max (Max, x1);
                        Mix = min (Mix, x2);
                    }
                    if (May > Miy || Max > Mix)
                    {
                        inf = mid;
                        continue;
                    }
                    May = -1e9, Miy = 1e9, Mix = 1e9, Max = -1e9;
                    for (int i = 0; i < n; ++ i)
                    {
                        if (s[i] > 1e8 / mid) continue;
                        double d = mid * s[i];
                        double x1 = x[i] + y[i] - d;
                        double x2 = x[i] + y[i] + d;
                        double y1 = y[i] - x[i] - d;
                        double y2 = y[i] - x[i] + d;
                        if (y1 > r2) continue;
                        May = max (May, y1);
                        Miy = min (Miy, y2);
                        Max = max (Max, x1);
                        Mix = min (Mix, x2);
                    }
                    if (May > Miy || Max > Mix)
                    {
                        inf = mid;
                        continue;
                    }
                }
            }
            sol = mid;
            sup = mid;
        }
        cout << fixed << setprecision (8) << sol;
        return;
    }
    double inf = 0, sup = 2e7, sol = - 1;
    for (int i = 1; i <= 1000; ++ i)
    {
        double mid = (inf + sup) / 2;
        double May = -1e9, Miy = 1e9, Mix = 1e9, Max = -1e9;
        for (int i = 0; i < n; ++ i)
        {
            if (s[i] > 1e8 / mid) continue;
            double d = mid * s[i];
            double x1 = x[i] + y[i] - d;
            double x2 = x[i] + y[i] + d;
            double y1 = y[i] - x[i] - d;
            double y2 = y[i] - x[i] + d;
            May = max (May, y1);
            Miy = min (Miy, y2);
            Max = max (Max, x1);
            Mix = min (Mix, x2);
        }
        if (May > Miy || Max > Mix)
        inf = mid;
        else
        {
            sol = mid;
            sup = mid;
        }
    }
    cout << fixed << setprecision (8) << sol;
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