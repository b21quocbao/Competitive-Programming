#include <bits/stdc++.h>

#define fn "test"
#define fn1 "WORDGAME"

using namespace std;

const int mn = 500 + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 50 + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
string t, s[mn];
int n;
int pre[mn][mm], suf[mn][mm];
bool ok[2][mn][20][mn];
int f[2][mm][mm][20][mn];

struct Z
{
    int si, l, r, res, id, len;
    Z(){}
    Z (int _si, int _l, int _r, int _res, int _id, int _len)
    {
        si = _si; l = _l; r = _r; res = _res;
        id = _id; len = _len;
    }
};
struct myc
{
    bool operator () (Z a, Z b)
    {
        return a.len > b.len;
    }
};

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
    cin >> t;
    cin >> n;
    for (int i = 0; i < n; ++ i)
    cin >> s[i];
    for (int j = 0; j < t.size(); ++ j)
    for (int i = 0; i < n; ++ i)
    {
        int k = j;
        for (int l = 0; l < s[i].size(); ++ l)
        if (k < t.size() && s[i][l] == t[k]) ++ k; 
        pre[i][j] = k - j;
    }
    for (int j = t.size() - 1; j >= 0; -- j)
    for (int i = 0; i < n; ++ i)
    {
        int k = j;
        for (int l = s[i].size() - 1; l >= 0; -- l)
        if (k >= 0 && s[i][l] == t[k]) -- k;
        suf[i][j] = j - k;
    }
    for (int i = 0; i < n; ++ i)
    for (int j = 0; j <= (int)s[i].size(); ++ j)
    for (int k = 0; k < n; ++ k)
    {
        int l = min (j, (int)s[k].size());
        string s1 = s[i].substr ((int)s[i].size() - j, l), s2 = s[k].substr ((int)s[k].size() - l, l);
        reverse (s2.begin(), s2.end());
        ok[0][i][j][k] = (s1 == s2);
        s1 = s[i].substr (j - l, l), s2 = s[k].substr (0, l);
        reverse (s2.begin(), s2.end());
        ok[1][i][j][k] = (s1 == s2);
    }
}

char get_char (int si, int id, int res)
{
    if (!res) return (!si ? s[id].back() : s[id][0]);
    if (res == s[id].size()) return (!si ? s[id][0] : s[id].back());
    if (!si && s[id][s[id].size() - res] == s[id][s[id].size() - res - 1]) return s[id][s[id].size() - res];
    if (si && s[id][res] == s[id][res - 1]) return s[id][res];
    return (' ');
}

bool is_palin (string s, int l, int r)
{
    for (int i = l; i < r - (i - l); ++ i)
    if (s[i] != s[r - (i - l)]) return 0;
    return 1;
}

bool kt (int si, int id, int l, int r, int res)
{
    if (l + r < t.size()) return false;
    if (res == s[id].size())
    return is_palin (s[id], 0, s[id].size() - 1);
    else if (res > 0)
    {
        char c = get_char (si, id, res);
        if (c == ' ') return 0;
        if (!si)
        return is_palin (s[id], s[id].size() - res, s[id].size() - 1);
        return is_palin (s[id], 0, res - 1);
    }
    return 1;
}

void solve()
{
    priority_queue <Z, vector<Z>, myc> qu;
    for (int i = 0; i < n; ++ i)
    {
        f[0][pre[i][0]][0][s[i].size()][i] = s[i].size();
        qu.push (Z (0, pre[i][0], 0, s[i].size(), i, s[i].size()));
    }
    while (qu.size())
    {
        Z top = qu.top(); qu.pop();
        int si = top.si, l = top.l, r = top.r;
        int id = top.id, len = top.len, res = top.res;
        if (f[si][l][r][res][id] != len) continue;
        if (kt (si, id, l, r, res))
        {
            cout << len;
            return;
        }
        char c = get_char (si, id, res);
        if (c == ' ') continue;
        for (int i = 0; i < n; ++ i)
        {
            if ((!si) && (s[i].back() != c || !ok[si][id][res][i])) continue;
            if ((si) && (s[i][0] != c || !ok[si][id][res][i])) continue;
            int ne_si = (s[i].size() <= res ? si : 1 - si);
            int ne_l = l + (si ? pre[i][l] : 0);
            int ne_r = r + (!si ? suf[i][t.size() - 1 - r] : 0);
            int ne_id = (ne_si == si ? id : i);
            int ne_res = abs (res - (int)s[i].size());
            int ne_len = len + s[i].size();
            int* x = &f[ne_si][ne_l][ne_r][ne_res][ne_id];
            if (!(*x) || (*x) > ne_len)
            {
                *x = ne_len;
                qu.push (Z (ne_si, ne_l, ne_r, ne_res, ne_id, ne_len));
            }
        }
    }
    cout << - 1;
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