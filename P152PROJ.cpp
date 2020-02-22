#include <bits/stdc++.h>

#define int int64_t
#define fn "test"
#define fn1 ""

using namespace std;

const int mn = 1 * (int)(1e5) + 10;
const int mod = 10007;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
int cid;
vector<int> pr;
int id[9][6][4][4][3][3][3][3];
int vl[70000];
vector<pair<int, int> >  f(70000), F(70000);
vector<int> v(8);
vector<int> gt[70000];

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

int lo (int n, int k)
{
    int K = k;
    int cn = 1;
    while (K * k <= n) 
    {
        ++ cn;
        K *= k;
    }
    return cn;
}

bool ispr (int n)
{
    for (int i = 2; i <= trunc(sqrt (n)); ++ i)
    if (n % i == 0) return false;
    return true;
}

inline int Id (vector<int> v)
{
    return id[v[0]][v[1]][v[2]][v[3]][v[4]][v[5]][v[6]][v[7]];
}

inline void mo (int& x)
{
    x %= mod;
}

inline void mo1 (int& x)
{
    if (x >= mod) x -= mod;
}

void enter()
{
    int n;
    cin >> n;
    #define ii pair<int, vector<int> >
    vector<ii> v; 
    vector<int> cn;
    for (int i : pr) cn.emplace_back(0);
    v.emplace_back(1, cn);
    for (int i = 0; i < n; ++ i)
    {
        int x;
        cin >> x;
        vector<int> cn;
        for (int i : pr)
        {
            int r = 0;
            while (x % i == 0)
            {
                x /= i;
                ++ r;
            }
            cn.emplace_back(r);
        }
        v.emplace_back(x, cn);
    }
    sort (v.begin() + 1, v.end(), [](ii a, ii b)
         {
             return a.first < b.first;
         });
    for (int j = 0; j < 70000; ++ j)
    {
        f[j].first = f[j].second = 0;
        F[j].first = F[j].second = 0;
    }
    f[0].first = 1;
    vector<int> nst(pr.size());
    unordered_set<int> st;
    st.insert(0);
    for (int i = 1; i < v.size(); ++ i)
    {
        unordered_set<int> mst;
        for (int j : st)
        {
            F[j].first = F[j].second = 0;
            mo1 (F[j].first += f[j].first);
            if (v[i].first != v[i - 1].first)
            mo1 (F[j].first += f[j].second);
            else
            mo1 (F[j].second += f[j].second);
            mst.insert (j);
        }
        for (int i1 : st)
        {
            for (int j = 0; j < 8; ++ j)
            nst[j] = max (gt[i1][j], v[i].second[j]);
            int i2 = Id (nst);
            if (v[i].first != v[i - 1].first)
            {
                mo (F[i2].second += f[i1].second * v[i].first);
                mo (F[i2].second += f[i1].first * v[i].first);
            }
            else
            {
                mo1 (F[i2].second += f[i1].second);
                mo (F[i2].second += f[i1].first * v[i].first);
            }
            mst.insert(i2);
        }
        st = mst;
        swap (f, F);
    }
    int sol = - 1;
    for (int i = 0; i < 70000; ++ i)
    {
        mo (sol += f[i].second * vl[i]);
        mo (sol += f[i].first * vl[i]);
    }
    if (sol < 0) sol += mod;
    cout << "Case " << tt << ": " << sol << "\n";
}

void solve()
{

}

void print_result()
{

}

void attemp (int cs, int s)
{
    if (cs == pr.size())
    {
        vl[cid] = s;
        gt[cid] = v;
        id[v[0]][v[1]][v[2]][v[3]][v[4]][v[5]][v[6]][v[7]] = cid ++;
        return;
    }
    int cn = 0;
    for (int j = 1; j <= 500; j *= pr[cs])
    {
        v[cs] = (cn ++);
        attemp (cs + 1, (s * j) % mod);
    }
}

int32_t main()
{
    docfile();
    cin>>ntest;
    pr.emplace_back(2);
    pr.emplace_back(3);
    pr.emplace_back(5);
    pr.emplace_back(7);
    pr.emplace_back(11);
    pr.emplace_back(13);
    pr.emplace_back(17);
    pr.emplace_back(19);
    attemp (0, 1);
    for (tt = 1; tt <= ntest; ++ tt)
    {
        enter();
        solve();
        print_result();
    }
}