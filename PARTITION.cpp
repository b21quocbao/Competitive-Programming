#include <bits/stdc++.h>
#define int long long

using namespace std;
const bool aNs = 0;
pair<int, int>  a[mn];
int ok[mn], id[mn];
int n, w, h;

pair<int, int> operator - (pair<int, int> x, pair<int, int> y)
{
    return {x.first - y.first, x.second - y.second};
}

int operator * (pair<int, int> x, pair<int, int> y)
{
    return x.first * y.second - x.second * y.first;
}

void Dthg (pair<int, int> x, pair<int, int> y)
{
    y.first >>= 1; y.second >>= 1;
    x.first -= y.first; x.second -= y.second;
    int u = y.first - x.first, v = y.second - x.second;
    int U = v, V = - u;
    int a = U, b = V, c = U * x.first + V * x.second;
    cout << a << " " << b << " " << - c;
    exit(0);
}

main()
{
    read (n); read (w); read (h);
    auto root = make_pair (w, h);
    w <<= 1; h <<= 1;
    int res = 0;
    for (int i = 0; i < n; ++ i)
    {
        read (a[i].first); read (a[i].second);
        a[i].first <<= 1; a[i].second <<= 1;
        if (a[i].second < root.second) 
        {
            a[i].first = root.first + (root.first - a[i].first);
            a[i].second = root.second + (root.second - a[i].second); 
            ok[i] = 1;
        }
        else 
        {
            ok[i] = - 1;
            ++ res;
        }
        id[i] = i;
    }
    sort (id, id + n, [&](int i, int j)
         {
             auto x = a[i] - root;
             auto y = a[j] - root;
             return (x * y) > 0;    
         });
    for (int j = 0; j < n; ++ j)
    {
        int i = id[j];
        res += ok[i];
        if (res == n / 2)
        Dthg (root, a[i]);
    }
}
