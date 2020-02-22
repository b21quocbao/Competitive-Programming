#include <bits/stdc++.h>

#define fn "test"
#define fn1 "EXPRESSION"

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

long long gcd (long long a, long long b)
{
    return (!b ? a : gcd (b, a % b));
}

long long F (string s, long long a, long long b)
{
    if (s == "MAX") return max (a, b);
    if (s == "MIN") return min (a, b);
    if (s == "GCD") return llabs(gcd (a, b));
    if (s == "SUM") return a + b;
    if (s == "DIF") return b - a;
}

void enter()
{
    char c = getchar (), c1;
    vector<long long> vr;
    vector<string> vs;
    long long r = 0;
    string s;
    while (c == '(' || c == ')' || isalnum (c) || c == ',')
    {
        if (isdigit (c)) r = r * 10 + c - '0';
        if (c == '(') 
        {
            vs.push_back(s);
            s = "";
        }
        if (isalpha (c)) s += c;
        if (c == ',') 
        {
            if (isdigit (c1))
            vr.push_back(r);
            r = 0;
        }
        if (c == ')')
        {
            if (isdigit (c1))
            vr.push_back(r);
            r = 0;
            //cerr << vs.back() << " " << vr.back() << " " << vr[vr.size() - 2] << "\n";
            long long res = (F (vs.back(), vr.back(), vr[vr.size() - 2]));
            vr.pop_back(); vr.pop_back(); vs.pop_back();
            vr.push_back(res);
        }
        c1 = c;
        c = getchar ();
    }
    cout << vr.back();
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