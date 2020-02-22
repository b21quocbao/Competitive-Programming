#include <bits/stdc++.h>

#define fn "test"
#define fn1 "POINTS"

using namespace std;

const int mn = 1 * (int)(1e3) + 10;
const int mod = 1 * (int)(1e9) + 7;
const int mm = 1 * (int)(1e3) + 10; 
const int base = 1 * (int)(1e9);
const bool aNs = 1;

int tt, ntest = 1;
unordered_set<int> mu;

struct Z
{
    int x, y, z;
    Z (){}
    Z (int X, int Y, int Z1)
    {
        x = X; y = Y; z = Z1;
    }
};
struct Z1
{
    int i, j, x, y, z;
    Z1 (){}
    Z1 (int I, int J, int X, int Y, int Z1)
    {
        i = I; j = J;
        x = X; y = Y; z = Z1;
    }
};

Z a[mn];

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

Z1 tg (int i, int j, int x, int y, int z)
{
    int g = __gcd (__gcd (x, y), z);
    if (x < 0 && g > 0) g = - g;
    x /= g;
    y /= g;
    z /= g;
    return Z1 (i, j, x, y, z);
}

bool operator < (Z a, Z b)
{
    if (a.x != b.x)
    return (a.x < b.x);
    if (a.y != b.y)
    return (a.y < b.y);
    return (a.z < b.z);
}

bool operator < (Z1 a, Z1 b)
{
    if (a.x != b.x)
    return (a.x < b.x);
    if (a.y != b.y)
    return (a.y < b.y);
    if (a.z != b.z)
    return (a.z < b.z);
    if (a.i != b.i)
    return (a.i < b.i);
    if (a.j != b.j)
    return (a.j < b.j);
    
}

bool operator != (Z a, Z b)
{
    return (a.x != b.x || a.y != b.y || a.z != b.z);
}

bool operator != (Z1 a, Z1 b)
{
    if (a.x == b.x && a.y == b.y && a.z == b.z)
    {
        if (a.i == b.i) return 0;
        if (mu.find (b.i) != mu.end()) return 0;
        if (mu.find (b.j) != mu.end()) return 0;
        return 1;
    }
    return 1;
}

void enter()
{
    int n;
    cin >> n;
    vector<Z1> v;
    for (int i = 0; i < n; ++ i)    
    cin >> a[i].x >> a[i].y >> a[i].z;
    sort (a, a + n);
    // for (int i = 0; i < n; ++ i)    
    // cout << a[i].x << " " << a[i].y << " " << a[i].z << "\n";
    // cout << "\n";
    for (int i = 0; i < n; ++ i)
    for (int j = 0; j < i; ++ j)
    v.emplace_back(tg (j, i, a[i].x - a[j].x, a[i].y - a[j].y, a[i].z - a[j].z));
    sort (v.begin(), v.end());
    int sol = 0;
    Z cur;
    cur.x = (int)(1e9);
    for (int i = 0; i < v.size();)
    {
        int j;
        if (1 || cur != Z (v[i].x, v[i].y, v[i].z))
        {
            cur = Z (v[i].x, v[i].y, v[i].z);
            mu.clear();
        }
        else 
        {
            if (mu.find (v[i].i) != mu.end()) 
            {
                ++ i;
                continue;
            }
            if (mu.find (v[i].j) != mu.end()) 
            {
                ++ i;
                continue;
            }
        }
        for (j = i; j < v.size(); ++ j)
        {
            if (j == v.size() || v[i] != v[j]) break;
            mu.insert (v[j].j);
            mu.insert (v[j].i);
        }
        if (j - i >= 2) 
        {
            ++ sol;
            // cout << v[i].i << " " << v[i].j << " " << v[i].x << " " << v[i].y << " " << v[i].z << "\n";
            // cout << v[i + 1].i << " " << v[i + 1].j << " " << v[i + 1].x << " " << v[i + 1].y << " " << v[i + 1].z << "\n";
        }
        i = j;
    }
    cout << sol;
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