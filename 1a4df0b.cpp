#include <bits/stdc++.h>
#define int long long
 
#define fn ."test"
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
 
class BigNum
{
    public:
 
    vector<int> v;
    int sign = 1;
 
    BigNum () {}
 
    void resize(int n)
    {
        v.resize(n);
    }
 
    int size ()
    {
        return v.size();
    }
 
    void fix()
    {
        while (v.size() >= 2 && v.back() == 0) 
        v.pop_back();
        if (v.size() == 1 && v.back() == 0)
        sign = 1; 
    }
 
    void operator = (string s)
    {
        if (s[0] == '-') 
        {
            sign = - 1;
            s.erase(s.begin());
        }
        v.resize(((int)s.size() + 8) / 9);
        for (int i = 0; i < s.size(); ++ i)
        {
            int x = (s.size() - 1 - i) / 9;
            v[x] = v[x] * 10 + (s[i] - '0');
        }
    }
 
    BigNum (string s)
    {
        *this = s;
    }
 
    void operator = (int x)
    {
        if (x < 0)
        {
            sign = - 1;
            x = - x;
        }
        if (!x)
        {
            v.emplace_back (0);
            return;
        }
        while (x)
        {
            v.emplace_back (x % base);
            x /= base;
        }
        // reverse (v.begin(), v.end());
    }
 
    BigNum (int x)
    {
        // cerr << x << "**\n";
        *this = x;
    }
 
    // void operator = (long long x)
    // {
    //     if (x < 0)
    //     {
    //         sign = - 1;
    //         x = - x;
    //     }
    //     if (!x)
    //     {
    //         v.emplace_back (0);
    //         return;
    //     }
    //     while (x)
    //     {
    //         v.emplace_back (x % base);
    //         x /= base;
    //     }
    //     // reverse (v.begin(), v.end());
    // }
 
    // BigNum (long long x)
    // {
    //     *this = x;
    // }
 
    bool operator == (BigNum a)
    {
        return (sign == a.sign && v == a.v);
    }
 
    BigNum operator - () 
    {
        auto a = * this;
        a.sign = - sign;
        return a;
    }
 
    void operator = (BigNum a)
    {
        sign = a.sign;
        v = a.v;
    }
 
    bool operator < (BigNum a)
    {
        if (sign != a.sign) return (sign < a.sign);
        if (v.size() != a.v.size()) return (v.size() < a.v.size());
        if (a.sign == - 1) return ((- a) < (- (*this)));
        for (int i = v.size() - 1; i >= 0; -- i)
        if (v[i] != a.v[i]) return (v[i] < a.v[i]);
        return 0;
    }
 
    bool operator <= (BigNum a)
    {
        return ((*this) < a || (*this) == a);
    }
 
    bool operator > (BigNum a)
    {
        return (a < (*this));
    }
 
    bool operator >= (BigNum a)
    {
        return ((*this) > a || (*this) == a);
    }
 
    friend BigNum operator + (BigNum a, BigNum b)
    {
        if (a.sign != b.sign) return a - (- b);
        BigNum c;
        c.sign = a.sign;
        int r = 0;
        for (int i = 0; i < max (a.v.size(), b.v.size()); ++ i)
        {
            if (i < a.v.size()) r += a.v[i];
            if (i < b.v.size()) r += b.v[i];
            c.v.emplace_back(r % base);
            r /= base;
        }
        if (r) c.v.emplace_back(r);
        return c;
    }
 
    friend void operator += (BigNum& a, BigNum b)
    {
        a = a + b;
    }
 
    friend void operator -= (BigNum& a, BigNum b)
    {
        if (a.sign != b.sign) 
        {
            a += (- b);
            return;
        }
        if (a.sign == - 1) 
        {
            a = (- b) - (- a);
            return;
        } 
        if (a < b) 
        {
            a = - (b - a);
            return;
        }
        bool r = 0;
        for (int i = 0; i < a.size(); ++ i)
        {
            if (i < b.size())
            a.v[i] -= b.v[i];
            a.v[i] -= r;
            if (a.v[i] < 0)
            {
                r = 1;
                a.v[i] += base;
            }
            else r = 0;
        }
        a.fix();
    }
 
    friend BigNum operator - (BigNum a, BigNum b)
    {
        a -= b;
        return a;
    }
 
    friend BigNum operator * (BigNum a, BigNum b)
    {
        BigNum c; c.resize(a.size() + b.size());
        c.sign = a.sign * b.sign;
        for (int i = 0; i < a.size(); ++ i)
        {
            long long r = 0;
            for (int j = 0; j < b.size() || r; ++ j)
            {
                r += c.v[i + j] + 1ll * a.v[i] * (j == b.size() ? 0 : b.v[j]);
                c.v[i + j] = r % base;
                r /= base;
            }
        }
        c.fix();
        return c;
    }
 
    friend void operator *= (BigNum& a, BigNum b)
    {
        a = a * b;
    }
 
    friend BigNum operator / (BigNum a, int x)
    {
        long long r = 0;
        BigNum b;
        b.sign = a.sign;
        if (x < 0) b.sign = - b.sign;
        for (int i = a.size() - 1; i >= 0; -- i)
        {
            r = 1ll * r * base + a.v[i];
            b.v.emplace_back(r / x);
            r %= x;
        }
        reverse (b.v.begin(), b.v.end());
        b.fix();
        return b;
    }
 
    friend void operator /= (BigNum& a, int x)
    {
        a = a / x;
    }
 
    friend int operator % (BigNum a, int x)
    {
        long long r = 0;
        for (int i = a.size() - 1; i >= 0; -- i)
        r = (1ll * r * base + a.v[i]) % x;
        return r;
    }
    
    friend ostream& operator << (ostream& cout, BigNum a)
    {
        if (a.sign == - 1)
        cout << '-';
        cout << a.v.back();
        for (int i = a.size() - 2; i >= 0; -- i)
        cout << setfill('0') << setw (9) << a.v[i];
        return cout;
    }
 
    friend istream& operator >> (istream& cin, BigNum& a)
    {
        string s;
        cin >> s;
        a = s;
        return cin;
    }
};
 
 
 
bool operator > (pair<BigNum, BigNum> a, pair<BigNum, BigNum> b)
{
    return a.first * b.second > b.first * a.second;
}
 
int po (int n, int k)
{
    if (!k) return 1;
    int N = po (n, k >> 1);
    N = (1ll * N * N) % mod;
    return ((k & 1) ? (N * n) % mod : N);
}
 
void enter()
{
    int n;
    cin >> n;
    vector<int> a (n);
    for (int i = 0; i < n; ++ i)
    cin >> a[i];
    sort (a.begin(), a.end());
    pair<BigNum, BigNum> sol;
    long long Sol = 0;
    for (int i = 1; i < (1 << n); ++ i)
    if (__builtin_popcount(i) % 2 == 0)
    {
        BigNum A (1), B (1);
        vector<int> v;
        for (int j = 0; j < n; ++ j)
        if ((i >> j) & 1)
        v.emplace_back(a[j]);
        for (int i = 0; i < v.size(); ++ i)
        if (i < (v.size() / 2))
        B *= BigNum (v[i]);
        else 
        A *= BigNum (v[i]);
        Sol = max (Sol, (1ll * (A % mod) * po (B % mod, mod - 2)) % mod);
    }
    cout << Sol << "\n";
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
    cin>>ntest;
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}