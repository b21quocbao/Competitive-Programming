#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = a; i < b; ++ i)
#define ROR(i, b, a) for (int i = b; i > a; -- i)
#define FOE(i, a, b) for (int i = a; i <= b; ++ i)
#define ROE(i, b, a) for (int i = b; i >= a; -- i)
#define X first
#define Y second
#define fn "test"
#define fn1 ""

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll, ll> pl;
typedef vector<ii> vii;
typedef vector<pl> vll;

const int mn = 1 * int(1e5) + 10;
const int mod = 1 * int(1e5) + 10;
const int mm = 1 * int(1e5) + 10;

int tt, ntest = 1;

void docfile()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if (ifstream(fn".inp"))
    {
        freopen(fn".inp", "r", stdin);
        freopen(fn".out", "w", stdout);
    }else if (ifstream(fn1".inp"))
    {
        freopen(fn1".inp", "r", stdin);
        freopen(fn1".out", "w", stdout);
    }
}

int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch)) f = ch == '-' ? - f : f, ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return x * f;
}

void write(int a)
{
    int i = 0;
    char S[20];
    if (a == 0) {putchar('0'); return;}
    while(a > 0)
    {
        S[i++] = a % 10 + '0';
        a /= 10;
    }
    --i;
    while(i >= 0) putchar(S[i--]);
}

void enter()
{
    
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