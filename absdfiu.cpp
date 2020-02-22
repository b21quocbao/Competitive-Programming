#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int&i : v)
    cin >> i;
    int x, y, z;
    cin >> x >> y >> z;
    -- x; -- y; -- z;
    v.erase (v.begin() + x);
    v.erase (v.begin() + y, v.begin() + z);
    cout << v.size() << "\n";
    for (int i : v)
    cout << i << " ";
    return 0;
}
