/*
Code by b21
Time: 21:50 Tue 03/03/2020
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
   else if (ifstream("1305b.inp"))
    {
        freopen("1305b.inp", "r", stdin);
        freopen("1305b.out", "w", stdout);
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

bool id[mn];
int cn[mn];

void enter()
{
    string s;
    getline (cin, s);
    int n = s.size();
    s = '#' + s;
    for (int i = 1; i <= n; ++ i)
    id[i] = 1;
    vector<vector<int> > V;
    while(1) {
        for (int i = n; i >= 1; -- i)
        cn[i] = cn[i + 1] + (s[i] == ')' && id[i]);
        int L = 0;
        int Cn = 0, cn1 = 0;
        for (int i = 1; i <= n; ++ i)
        if (id[i] && s[i] == '(')
        {
            ++ Cn;
            if (Cn <= cn[i]) 
            {
                L = i;
                cn1 = Cn;
            }
        }
        Cn = cn1;
        if (Cn && L) {
            vector<int> v;
            for (int i = 1; i <= L; ++ i)
            if (id[i] && s[i] == '(')
            {
                v.emplace_back(i);
                id[i] = 0;
            }
            for (int i = n; i >= L; -- i)
            if (s[i] == ')' && Cn)
            {
                v.emplace_back(i);
                -- Cn;
                id[i] = 0;
            }
            V.emplace_back(v);
        } else break;
    }
    cout << V.size() << "\n";
    for (vector<int> v : V) {
        sort (v.begin(), v.end());
        cout << v.size() << "\n";
        for (int i : v) cout << i << " ";
        cout << "\n";
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