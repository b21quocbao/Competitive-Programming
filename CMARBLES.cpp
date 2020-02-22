#include <bits/stdc++.h>

#define fn "test"
#define fn1 "CMARBLES"

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int id[mn], idm[mn], cnt[mn], pos[mn], posm[mn], n;

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

int Id (int i)
{
    if (i >= n) i -= n;
    if (i < 0) i += n;
    return i;
}

void enter()
{
    int k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<string> v;
    for (int i = 0; i < k; ++ i)
    {
        string s1;
        for (int i = 0; i < n; ++ i)
        {
            if (s[i] == s[Id (i + 1)]) s1.push_back('B');
            else s1.push_back('W');
        }
        s = s1;
    }  
    v.push_back(s);
    for (int i = 0; i < k; ++ i)
    {
        vector<string> v1;
        for (string s : v)
        for (int j = 0; j < 2; ++ j)
        {
            string s1;
            if (j == 0) s1.push_back('W');
            else s1.push_back('B');
            for (int i = 0; i < n - 1; ++ i)
            if (s[i] == 'B')
            s1.push_back(s1.back());
            else 
            {
                s1.push_back((char)('B' + 'W' - s1.back()));
            }
            if ((s.back() == 'B' && s1.back() == s1[0]) || (s.back() == 'W' && s1.back() != s1[0]))
            v1.push_back(s1);
        }
        v = v1;
    }
    set<string> mu;
    int sol = 0;
    for (string& s : v)
    {
        //cerr << s << "\n";
        for (int i = 0; i < n; ++ i)
        {
            pos[i] = s[i];
            idm[i] = i;
            ++ cnt[pos[i]];
        }
        int r = 0;
        for (int k = 0; k <= n; (!k ? ++ k : k <<= 1))
        {
            for (int i = 1; i < max((int)n, 256); ++ i)
            cnt[i] += cnt[i - 1];
            for (int i = n - 1; i >= 0; -- i)
            id[--cnt[pos[idm[i]]]] = idm[i];
            int K = (!k ? k + 1 : k << 1);
            r = 0;
            for (int i = 0; i < max((int)n, 256); ++ i)
            cnt[i] = 0;
            for (int i = 0; i < n; ++ i)
            {
                idm[i] = Id (id[i] - K);
                if (i)
                if (pos[Id (id[i] + k)] != pos[Id (id[i - 1] + k)]
                   || (pos[id[i]] != pos[id[i - 1]]))
                ++ r;
                posm[id[i]] = r;
                ++ cnt[r];
            }
            swap (pos, posm);
            if (r == n - 1) break;
        }
        for (int i = 0; i < max((int)n, 256); ++ i)
        cnt[i] = 0;
        s = s.substr (id[0], n - id[0]) + s.substr (0, id[0]);
        if (mu.find (s) == mu.end()) 
        {
            mu.insert (s);
        }
    }
    cout << mu.size();
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