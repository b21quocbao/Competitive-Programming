/*
Code by b21
Time: 20:44 Wed 06/11/2019
*/

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
   else if (ifstream("WEIRDO.inp"))
    {
        freopen("WEIRDO.inp", "r", stdin);
        freopen("WEIRDO.out", "w", stdout);
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

double fx[2][30], f[2][30], sl[2];
int F[mn];

void enter()
{
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < 26; ++ i)
    for (int j = 0; j < 2; ++ j)
    fx[j][i] = f[j][i] = 0;
    sl[0] = sl[1] = 0;
    for (int i = 0;  i < n; ++i)
    {
        string s;
        int cn = 0;
        getline (cin, s);
        int id = 0;
        s = '#' + s;
        int mi = 0;
        for (int i = 1; i < s.size(); ++ i)
        {
            char c = s[i];
            F[i] = F[i - 1] + (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
            if (i > 1 && 2 * F[i] - i < mi)
            {
                id = 1;
                break;
            }
            mi = max (mi, 2 * F[i - 1] - (i - 1));
        }
        ++ sl[id];
        vector<bool> ok(30);
        s.erase(s.begin());
        for (char c : s)
        {
            ++ fx[id][c - 'a'];
            if (!ok[c - 'a'])
            {
                ok[c - 'a'] = 1;
                ++ f[id][c - 'a']; 
            }
        }
    }
    double sol = 0;
    for (int i = 0; i < 26; ++ i)
    if (f[0][i])
    sol += log2 (f[0][i]);
    for (int i = 0; i < 26; ++ i)
    if (f[1][i])
    sol -= log2 (f[1][i]);
    for (int i = 0; i < 26; ++ i)
    if (fx[0][i])
    sol -= sl[0] * log2 (fx[0][i]);
    for (int i = 0; i < 26; ++ i)
    if (fx[1][i])
    sol += sl[1] * log2 (fx[1][i]);
    if (sol > 30)
    cout << "Infinity";
    else if (pow (2, sol) < 1e7)
    cout << fixed << setprecision(6) << pow (2, sol);
    else cout << "Infinity";
    
}

void solve()
{
    cout << "\n";
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