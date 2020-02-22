/*
Code by b21
Time: 08:13 Sun 20/10/2019
*/

#include <bits/stdc++.h>

using namespace std;

const int mn = 1 * (int)(1e6) + 10;
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
   else if (ifstream("2010k.inp"))
    {
        freopen("2010k.inp", "r", stdin);
        freopen("2010k.out", "w", stdout);
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
    
}

int n, a[mn], l1[mn], l2[mn], cnt1[mn], cnt2[mn];

void solve()
{
    read (n);
    vector<int> st1, st2;
    for (int i = 1; i <= n; ++ i)
    {
        read (a[i]);
        while (st1.size() && a[st1.back()] > a[i]) st1.pop_back();
        if (st1.size()) l1[i] = st1.back(); else l1[i] = 0;
        st1.push_back (i);
        while (st2.size() && a[st2.back()] < a[i]) st2.pop_back();
        if (st2.size()) l2[i] = st2.back(); else l2[i] = 0;
        st2.push_back (i);
        cnt1[i] = 1;
        cnt2[i] = 1;
    }
    long long sol = 0;
    for (int i = 1; i <= n; ++ i)
    {
        int x = i;
        while (1)
        {
            x = l1[x];
            if (x <= l2[i]) break;
            cnt1[i] += cnt1[x];
            sol += cnt1[x];
        }
        int res = l1[i];
        l1[i] = x;
        x = i;
        while (1)
        {
            x = l2[x];
            if (x <= res) break;
            cnt2[i] += cnt2[x];
            sol += cnt2[x];
        }
        l2[i] = x;
        ++ sol;
    }
    cout << sol;
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