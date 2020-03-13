/**
 *	 Code by b21
 *	 Time: 16:33 Sat 07/03/2020
**/

#include <bits/stdc++.h>

using namespace std;

const int mn = 4 * (int)(1e5) + 10;
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
   else if (ifstream("1322b.inp"))
    {
        freopen("1322b.inp", "r", stdin);
        freopen("1322b.out", "w", stdout);
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

int ie[25 * mn][2];
bool sum[25 * mn];
int cie;
int a[mn];

bool qu (int x, int k) {
    int r = 0;
    int sol = 0;
    int D = ((x >> (k - 1)) & 1);
    for (int i = k - 1; i >= 0; -- i) {
        int d = ((x >> i) & 1);
        if (i == k - 1) 
        {
            r = ie[r][d];
            if (!r) break;
        } else {
            if (d != D)
            sol ^= sum[ie[r][d]];
            r = ie[r][1 - d];
            if (!r) break;
        }
    }
    if (D && r) sol ^= sum[r];
    return sol;
}

void add (int x, int k) {
    int r = 0;
    for (int i = k - 1; i >= 0; -- i) 
    {
        int d = (x >> i) & 1;
        if (!ie[r][d]) 
        ie[r][d] = cie++;
        r = ie[r][d];
        sum[r] = sum[r] ^ 1;
    }
}

void del (int x) {
    sum[x] = 0;
    for (int i = 0; i < 2; ++ i) {
        if (ie[x][i]) del (ie[x][i]);
        ie[x][i] = 0;
    }
}

void enter()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++ i)
    cin >> a[i];
    int sol = 0;
    bool nho = 0;
    for (int i = 1; i <= 25; ++ i) {
        bool sl1 = 0;
        for (int j = 0; j < n; ++ j)
        sl1 ^= ((a[j] >> (i - 1)) & 1);
        bool sl0 = 0;
        if ((n - sl1) % 2) sl0 = 1; else sl0 = 0;
        if ((sl1 & sl0) ^ nho)
        sol += (1 << (i - 1));
        if (i == 25) break;
        del (0);
        cie = 1;
        for (int j = 0; j < n; ++ j) 
        {
            nho ^= qu (a[j], i);
            add (a[j], i);
        }
    }
    cout << sol;
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