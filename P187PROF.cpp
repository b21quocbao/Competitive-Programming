#include <bits/stdc++.h>

#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
// const int mod = 1 * (int)(1e9) + 7;
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

int mod[4] = {(int)1e9 + 2277, (int)1e9 + 5277, (int)1e9 + 8277, (int)1e9+ 9277};
string s[mn];
int ok[mn];

void enter()
{
    int n;
    cin >> n;
    cin.ignore();
    vector<vector<int> > V;
    for (int i = 0; i < n; ++ i)
    {
        getline (cin, s[i]);
        vector<int> v (4);
        for (const char &c : s[i])
        {
            int d = c - 'a' + 1;
            for (int j = 0; j < 4; ++ j)
            v[j] = (1ll * v[j] * 31 + d) % mod[j];
        }
        V.emplace_back(v);
    }
    long long sol = 0;
    sort (V.begin(), V.end());
    for (int i = 0; i < n; ++ i)
    for (int j = 0; j < s[i].size(); ++ j)
    {
        vector<int> v (4);
        for (int k = j; k < s[i].size(); ++ k)
        {
            for (int t = 0; t < 4; ++ t)
            v[t] = (1ll * v[t] * 31 + (s[i][k] - 'a' + 1)) % mod[t];
            auto it1 = lower_bound(V.begin(), V.end(), v);
            auto it2 = upper_bound(V.begin(), V.end(), v);
            if (it2 == it1) continue;
            if (ok[it1 - V.begin()] == i + 1) continue;
            ok[it1 - V.begin()] = i + 1;
            sol += (it2 - it1);
            // cerr << sol << " " << i << " " << j << " " << k << "\n";
        }
    }
    cout << sol - n;
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