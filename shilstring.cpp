#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

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

void enter()
{
    int n;
    string s;
    cin >> n;
    cin.ignore();
    getline(cin, s);
    s = ' ' + s;
    int d = n / 2;
    int sol = INT_MAX;
    vector<char> v1,v2;
    for (int i = 1; i <= n; ++ i)
    if (i <= d)
    v1.emplace_back(s[i]);
    else
    v2.emplace_back(s[i]);
    sort(v1.begin(), v1.end());
    sort (v2.begin(), v2.end());
    for (int k = 0; k < 2; ++ k)
    {
        int cn = 0, j = 0, cn1 = 0, cn2 = 0;
        for (int i = 0; i < d; ++ i)
        {
            while (j < d && v2[j] <= v1[i]) ++ j;
            if (v2[i] == 'a') ++ cn1;
            if (v1[i] == 'a') ++ cn2;
            if (j < d)  ++ j;
            else ++ cn;
        }
        cerr << cn << "\n";
        cerr << cn1  << " " << cn2 << "\n";
        sol = min (sol, cn + (cn1 - min (cn1, cn2)));
        swap (v1, v2);
    }
    int cn = 0, j = 0;
    for (int i = 0; i < d; ++ i)
    {
        while (j < d && v2[j] < v1[i]) ++ j;
        if (j < d && v2[j] == v1[i]) ++ j; 
        else ++ cn;
    }
    sol = min (sol, cn);
    cout << sol;
}

void solve()
{

}

void print_result()
{

}

int main()
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