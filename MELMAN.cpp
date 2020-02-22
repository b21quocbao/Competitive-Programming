#include <bits/stdc++.h>

#define fn "test"
#define fn1 "MELMAN"

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

class Hash
{
    public:
    vector<int> ha;
    vector<int> po;
    const int mod = (int)(1e9) + 7;
    Hash (string s, int hs = 31)
    {
        int n = s.size();
        po.resize(n + 1);
        ha.resize(n);
        for (int i = 0; i < n; ++ i)
        ha[i] = (1ll * (!i ? 0 : ha[i - 1]) * hs + s[i] - 'a') % mod;
        po[0] = 1;
        for (int i = 1; i <= n; ++ i)
        po[i] = (1ll * po[i - 1] * hs) % mod;
    }
    int GetHash (int i, int j)
    {
        int x = (ha[j] - 1ll * (!i ? 0 : ha[i - 1]) * po[j - i + 1]) % mod;
        return (x < 0 ? x + mod : x);
    }
    int HashValue ()
    {
        return ha.back();
    }
};

template<class T>
class HashTS
{
    public:
    vector<T> ha;
    vector<T> po;
    HashTS (string s, int hs = 31)
    {
        int n = s.size();
        ha.resize(n);
        po.resize(n + 1);
        for (int i = 0; i < n; ++ i)
        ha[i] = (!i ? 0 : ha[i - 1]) * hs + s[i] - 'a';
        po[0] = 1;
        for (int i = 1; i <= n; ++ i)
        po[i] = po[i - 1] * hs;
    }
    T GetHash (int i, int j)
    {
        return ha[j] - (!i ? 0 : ha[i - 1]) * po[j - i + 1];
    }
    T HashValue ()
    {
        return ha.back();
    }
};

void enter()
{
    string s, t;
    int k;
    getline (cin, s);
    getline (cin, t);
    if (t.size() > s.size())
    {
        cout << 0;
        return;
    }
    cin >> k;
    string S = t + s;
    ZFunc sol (S);
    Hash ha (S);
    vector<int> Sol;
    for (int i = t.size(); i + t.size() - 1 < S.size(); ++ i)
    {
        int j = i + sol.z[i], j1 = j + k;
        if (j1 < i + t.size())
        if (S[j1] != S[j1 - i])
        if (ha.GetHash (j + 1, j1 - 1) == ha.GetHash (j + 1 - i, j1 - 1 - i))
        if (ha.GetHash (j1 + 1, i + t.size() - 1) == ha.GetHash (j1 + 1 - i, t.size() - 1))
        Sol.emplace_back(i - t.size() + 1);
    } 
    cout << Sol.size() << "\n";
    for (int i : Sol) cout << i << " ";
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