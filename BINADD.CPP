/*
Code by b21
Time: 22:42 Sun 08/12/2019
*/

#include <bits/stdc++.h>

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 1;

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
   else if (ifstream("BINADD.inp"))
    {
        freopen("BINADD.inp", "r", stdin);
        freopen("BINADD.out", "w", stdout);
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

bool kt (vector<bool> a)
{
    for (const bool& x : a)
    if (x) return 1;
    return 0;
}

void operator ^= (vector<bool>& a, vector<bool> b)
{
    bool x, y;
    x ^= y;
    for (int i = 0; i < a.size(); ++ i)
    a[i] = a[i] ^ b[i];
}

void operator &= (vector<bool>& a, const vector<bool>& b)
{
    for (int i = 0; i < a.size(); ++ i)
    a[i] = a[i] & b[i];
    for (int i = 0; i < a.size() - 1; ++ i)
    a[i] = a[i + 1];
}



void enter()
{
    string s1, s2;
    cin >> s1 >> s2;
    string S1 (max(int(s2.size() - s1.size()), 0) + 1, '0');
    string S2 (max(int(s1.size() - s2.size()), 0) + 1, '0');
    s1 = S1 + s1;
    s2 = S2 + s2;
    vector<bool> a, b;
    for (char c : s1) a.emplace_back(c - '0');
    for (char c : s2) b.emplace_back(c - '0');
    int sol = 0;
    while (kt (b))
    {
        auto u = a;
        a ^= b;
        b &= u;
        ++ sol;
    }
    cout << sol << "\n";
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
    cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}