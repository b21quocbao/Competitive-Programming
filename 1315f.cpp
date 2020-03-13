/*
Code by b21
Time: 16:49 Sun 01/03/2020
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
   else if (ifstream("1315f.inp"))
    {
        freopen("1315f.inp", "r", stdin);
        freopen("1315f.out", "w", stdout);
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

class SuffixArray
{
    public:
    string s;
    int n;
    vector<int> id, idm, cn, pos, posm, lcp;
    SuffixArray (string S)
    {
        s = S;
        s.push_back('/');
        n = s.size();
        id.resize(n + 2);
        idm.resize(n + 2);
        cn.resize(max (n, 256) + 2);
        pos.resize(n + 2);
        posm.resize(n + 2);
        lcp.resize(n + 2);
    }
    int mo (int k)
    {
        if (k >= n) k -= n;
        if (k < 0) k += n;
        return k;
    }
    void process()
    {
        for (int i = 0; i < n; ++ i)
        {
            ++ cn[pos[i] = (int)s[i]];
            id[i] = idm[i] = i;
        }
        for (int i = 1; i < 256; ++ i)
        cn[i] += cn[i - 1];
        for (int k = 0;; !k ? ++ k : k <<= 1)
        {
            for (int i = n - 1; i >= 0; -- i)
            id[-- cn[pos[idm[i]]]] = idm[i];
            int r = 0;
            cn[0] = 0;
            int K = (!k ? k + 1 : k << 1);
            for (int i = 0; i < n; ++ i)
            {
                if (i && (pos[id[i]] != pos[id[i - 1]] || pos[mo (id[i] + k)] != pos[mo (id[i - 1] + k)])) 
                {
                    cn[r + 1] = cn[r];
                    ++ r;
                }
                posm[id[i]] = r;
                ++ cn[r];
                idm[i] = mo (id[i] - K);
            }
            pos = posm;
            if (r == n - 1) break;
        }
        for (int i = 0, r = 0; i < n - 1; ++ i)
        if (pos[i] != n - 1)
        {
            if (r) -- r;
            while (s[i + r] == s[id[pos[i] + 1] + r]) 
            ++ r;
            lcp[pos[i]] = r;
        }
        -- n;
        for (int i = 0; i < n; ++ i)
        {
            id[i] = id[i + 1];
            lcp[i] = lcp[i + 1];
        }
        s.pop_back();
    }
};

void enter()
{
    int n, m, k;
    string s;
    cin >> n >> m >> k >> s;
    SuffixArray Sa(s);
    for (int i = 0; i <= Sa.pos[0]; ++ i) {
        int x = C (n - i, m - 1 - (i != Sa.pos[0]));
        if (x >= k || sum + x >= k) {
            d = id[i];
            break;
        } 
        sum += x;
    }
    for (int i = d + 1; i < n; ++ i) 
    if (Sa.pos[i] > Sa.pos[d]) {
        int cn = 0;
        for (int j = 1; j < d; ++ j)
        if (Sa.pos[j] > Sa.pos[d]) ++ cn;
        for (int j = i + 1; j < n; ++ j)
        if (Sa.pos[j] > Sa.pos[d]) ++ cn;
        sum += C (cn, m - 3 + (d == Sa.pos[0]));
        if (sum > d)
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