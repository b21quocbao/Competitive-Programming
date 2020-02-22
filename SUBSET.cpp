#include <iostream>

#define fn "test"
#define fn1 "SUBSET"

using namespace std;

const int mn = 2 * (int)(1e5) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10;
const int base = 1 * (int)(1e9);
const bool aNs = 0;

int tt, ntest = 1;
long long a[mn], n, l, r;
int f[80][mn], tr[80][mn];
vector<int> v1, v2;
struct myclass {
  bool operator() (int i,int j) { return (v1[i]<v1[j]);}
} myc;
vector<int> sol;
int id[mn];
bool ok3 = 1, ok4 = 1;

void docfile()
{
    vector<int> v;
    
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

void process (vector<int>& v, int x, int y)
{
    sync_with
    int l = y - x + 1;
    for (int i = 0; i < (1 << l); ++ i)
    {
        int s = 0;
        for (int j = 0; j < l; ++ j)
        if ((i >> j) & 1) s += a[x + j];
        v.push_back(s);
    }

}

void sub1()
{
    sync_
    vector<int> v;
    int m = (n >> 1);
    process (v1, 0, m - 1);
    process (v2, m, n - 1);
    vector<int> id (v1.size());
    vector<int> id2(v2.size());
    for (int i = 0; i < v1.size(); ++ i)
    {
        id[i] = i;
        id2[i] = i;
    }
    sort (id.begin(), id.end(), [](int i, int j)
         {
             return v1[i] > v1[j];
         });
    sort (id2.begin(), id2.end(), [](int i, int j)
         {
             return v2[i] < v2[j];
         });
    int j = 0;
    for (int i = 0; i < v1.size(); ++ i)
    {
        while (j < v2.size() && v1[id[i]] + v2[id2[j]] < l) ++ j;
        if (v1[id[i]] + v2[id2[j]] <= r)
        {
            for (int k = 0; k < m; ++ k)
            if ((id[i] >> k) & 1)
            sol.push_back(k);
            for (int k = 0; k < n - m; ++ k)
            if ((id2[j] >> k) & 1)
            sol.push_back(m + k);
            return;
        }
    }
}

void sub2()
{
    f[0][0] = 1;
    f[0][a[0]] = 1;
    for (int i = 1; i < n; ++ i)
    for (int s = 1; s <= r; ++ s)
    {
        if (f[i - 1][s]) 
        {
            f[i][s] = 1;
            tr[i][s] = tr[i - 1][s];
        }
        else if (s >= a[i] && f[i - 1][s - a[i]])
        {
            f[i][s] = 1;
            tr[i][s] = i;
        }
    }
    -- n;
    int S;
    for (int s = l; s <= r; ++ s)
    if (f[n - 1][s]) {S = s; break;}
    while (S)
    {
        int k = tr[n][S];
        S -= a[k];
        sol.push_back(k);
        n = k - 1;
    }
}

void sub3()
{
    for (int i = n - 1; i >= 0; -- i)
    if (l >= a[i])
    {
        sol.push_back(i);
        l -= a[i];
    }
}

void sub4()
{
    for (int i = 0; i < min (r / a[i], n); ++ i)
    sol.push_back(i);
}

void enter()
{
    cin >> n >> l >> r;
    for (int i = 0; i < n; ++ i)
    {
        cin >> a[i];
        if (a[i] != a[0]) ok4 = 0;
        if (a[i] != i + 1) ok3 = 0;
    }
    if (n <= 40) 
    {
        sub1();
        return;
    }
    if (n <= 80) 
    {
        sub2();
        return;
    }
    if (ok3) 
    {
        sub3();
        return;
    }
    if (ok4)
    {
        sub4();
        return;
    }
    for (int i = 0; i < n; ++ i)
    {
        id[i] = i;
    }
    sort (id, id + n, [](int i, int j)
        {
             return a[i] < a[j];
        });
    long long s = 0;
    for (int i = 0; i < n; ++ i)
    {
        s += a[i];
        if (s >= l && s <= r)
        {
            for (int j = 0; j <= i; ++ j)
            sol.push_back(id[j]);
        }
        else if (s > r)
        {
            for (int j = 1; j <= i; ++ j)
            sol.push_back(id[j]);
        }
    }
}

void solve()
{
    sort (sol.begin(), sol.end());
    cout << sol.size() << "\n";
    for (int i : sol) cout << i + 1 << " ";
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