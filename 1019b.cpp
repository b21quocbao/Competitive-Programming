/*
Code by b21
Time: 23:31 Thu 17/10/2019
*/

#include <bits/stdc++.h>
#define int long long

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
   else if (ifstream("1019b.inp"))
    {
        freopen("1019b.inp", "r", stdin);
        freopen("1019b.out", "w", stdout);
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

int p[mn], d[mn], id1[mn], id2[mn];

void enter()
{
    int b, k, cd, cp;
    cin >> b >> k >> cd >> cp;
    for (int i = 1; i <= cd; ++ i)
    {
        cin >> d[i];
        id1[i] = i;
    }
    for (int i = 1; i <= cp; ++ i)
    {
        cin >> p[i];
        id2[i] = i;
    }
    sort (id1 + 1, id1 + cd + 1, [](int i, int j)
         {
             return d[i] > d[j];
         });
    sort (id2 + 1, id2 + cp + 1, [](int i, int j)
         {
             return p[i] > p[j];
         });
    int ma = LLONG_MIN, J = 0;
    for (int j = 1; j <= cd; ++ j)
    d[id1[j]] += d[id1[j - 1]];
    for (int j = 1; j <= cp; ++ j)
    p[id2[j]] += p[id2[j - 1]];
    for (int i = 0; i <= min (cd, k); ++ i)
    {
        int B = b, P = 100;
        B += d[id1[i]];
        P += p[id2[min (k - i, cp)]];
        if (B * P > ma) 
        {
            ma = B * P;
            J = i;
        }
    }
    cout << J << " " << min (k - J, cp) << "\n";
    for (int i = 1; i <= J; ++ i)
    cout << id1[i] << " ";
    cout << "\n";
    for (int i = 1; i <= min (k - J, cp); ++ i)
    cout << id2[i] << " ";
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