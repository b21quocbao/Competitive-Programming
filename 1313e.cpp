/*
Code by b21
Time: 09:50 Sat 29/02/2020
*/

#include <bits/stdc++.h>
#define int long long

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
   else if (ifstream("1313e.inp"))
    {
        freopen("1313e.inp", "r", stdin);
        freopen("1313e.out", "w", stdout);
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

int n, m;

class ZFunc
{
    public:
    vector<int> z;
    ZFunc (string s)
    {
        z.resize(s.size() + 2);
        int r = 0, l = 0;
        for (int i = 1; i < s.size(); ++ i)
        {
            if (r < i)
            while (s[i + z[i]] == s[z[i]]) ++ z[i];
            else
            {
                z[i] = min (z[i - l], r - i + 1);
                while (s[i + z[i]] == s[z[i]]) ++ z[i];
            }
            if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
        }
    }
};

int s[2 * mn];
int cn[2 * mn];

void addNode(int x) {
    for (int i = x; i <= m + 1; i += i & - i)
    {
        s[i] += x;
        ++ cn[i];
    }
}

void delNode (int x) {
    for (int i = x; i <= m + 1; i += i & - i)
    {
        s[i] -= x;
        -- cn[i];
    }
}

int qu (int x) {
    int S = 0, Cn = 0;
    for (int i = x; i >= 1; i -= i & - i)
    {
        S += s[i];
        Cn += cn[i];
    }
    return Cn * x - S;
}

void enter()
{
    cin >> n >> m;
    string a, b, s;
    cin >> a >> b >> s;
    a = s.substr(0, s.size() - 1) + '#' + a;
    ZFunc Fa(a);
    reverse(b.begin(), b.end());
    reverse(s.begin(), s.end());
    b = s.substr(0, s.size() - 1) + '#' + b;
    ZFunc Fb(b);
    int j = 0;
    int sol = 0;
    for (int i = 0; i < n; ++ i) {
        int x = - Fb.z[(n - 1 - (i - 1)) + m] + m + 1;
        // if (i) cerr << x << "\n";
        if (i) delNode(x);
        while (j < min (m - 1 + i, n))
        {
            int x = -Fb.z[(n - 1 - j) + m] + m + 1;
            // cerr << Fb.z[(n - 1 - j) + m] << "*\n";
            addNode(x);
            ++ j;
        }

        sol += qu (Fa.z[i + m] + 2);
        // cerr << Fa.z[i + m] << " " << sol << "\n";
        // cerr << "\n";
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