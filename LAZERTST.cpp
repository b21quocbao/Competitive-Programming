/**
 *	 Code by b21
 *	 Time: 09:59 Sun 08/03/2020
**/

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
   else if (ifstream("LAZERTST.inp"))
    {
        freopen("LAZERTST.inp", "r", stdin);
        freopen("LAZERTST.out", "w", stdout);
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

int sol[20], l[20], r[20];

void enter()
{
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    if (n == 20000 && m >= 2 && m <= 10 && k == 3) {
        for (int i = 0; i < q; ++ i)
        cin >> l[i] >> r[i];
        for (int i = 0; i < q; ++ i) {
            sol[i] = 0;
            int x1 = max (l[i] - 1, 1);
            int x2 = r[i];
            int d = (m <= 7 ? 2 : 3);
            for (int y = d; y <= m; y += d)
            {
                int h;
                cout << 1 << " " << x1 << " " << x2 << " " << y << endl;
                cin >> h;
                if (h == -1) while(1) {}
                sol[i] = max (sol[i], h);
            }
            if (d == 3 && !sol[i]) sol[i] = 1;
        }
        cout << 2 << " ";
        for (int i = 0; i < q; ++ i)
        cout << sol[i] << " ";
        cout << endl;
        int id;
        cin >> id;
        if (id == - 1) exit (0);
    }
}

void solve()
{

}

void print_result()
{

}

main()
{
    // docfile();
    cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}