#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, k, sol = 0, d = - 1, c = - 1;
    cin >> a >> b >> k;
    vector<int> v;
    for (int x = 1; x * x <= b; ++ x)
    if (x * x >= a)
    v.push_back(x * x);
    for (int y = 1; y * y * y <= b; ++ y)
    if (y * y * y >= a)
    {
        int cuoi = upper_bound (v.begin(), v.end(), y * y * y + k) - v.begin();
        int dau = lower_bound (v.begin(), v.end(), y * y * y - k) - v.begin();
        sol += (cuoi - dau);
    }
    cout << sol;
}