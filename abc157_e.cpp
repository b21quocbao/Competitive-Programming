/*
Code by b21
Time: 19:39 Sun 01/03/2020
*/

#include <bits/stdc++.h>

using namespace std;

const int mn = 5 * (int)(1e5) + 10;
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
   else if (ifstream("abc157_e.inp"))
    {
        freopen("abc157_e.inp", "r", stdin);
        freopen("abc157_e.out", "w", stdout);
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

int C[mn][28];

void ub (int x, char c, int ok)
{
    int k = c - 'a';
    for (int i = x; i < mn; i += i & - i) {
        C[i][k] += ok;
    }
}

int v[30];

void db (int x, int ok) {
    if (!x) return;
    int s = 0;
    for (int i = x; i >= 1; i -= i & - i) {
        for (int c = 0; c <= 'z' - 'a'; ++ c)
        v[c] += ok * C[i][c];
    }
}

void enter()
{
    int n;
    cin >> n;
    cin.ignore();
    string s;
    getline (cin, s);
    for (int i = 0; i < n; ++ i)
    ub (i + 1, s[i], 1);
    int q;
    cin >> q;
    for (int i = 0; i < q; ++ i) {
        int id;
        cin >> id;
        if (id == 1) {
            int x;
            char c;
            cin >> x >> c;
            if (s[x - 1] == c) continue;
            ub (x, s[x - 1], - 1);
            s[x - 1] = c;
            ub (x, s[x - 1], 1);
        } else {
            int l, r;
            cin >> l >> r;
            memset (v, 0, sizeof (v));
            db(r, 1);
            db(l - 1, - 1);
            int sol = 0;
            for (int i = 0; i <= 'z' - 'a'; ++ i)
            if (v[i] > 0) ++ sol;
            cout << sol << "\n";
        }
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
    docfile();
    //cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}