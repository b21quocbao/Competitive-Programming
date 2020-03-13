#include <algorithm>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <vector>
 
using namespace std;
 
using lint = long long int;
using ldd = long double;
 
const lint INF = 1e18;
 
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
 
 
#ifdef HOME
    int jjj;
    #define PO cout << "Pomelo" << endl;
    #define OL cout << "Oliva" << endl;
 
    #define debug(x) cout << #x << " " << x << endl;
    #define debug_p(x) cout << #x << " " << x.ff << " " << x.ss << endl;
    #define debug_v(x) cout << #x << " "; for (auto iii : x) cout << iii << " "; cout << endl;
    #define debug_vp(x) cout << #x << " "; for (auto ii : x) cout << '[' << ii.ff << " " << ii.ss << ']'; cout << endl;
    #define say(x) cout << x << endl;
#else
    #define PO 0;
    #define OL 0;
 
    #define debug(x) 0;
    #define debug_p(x) 0;
    #define debug_vp(x) 0;
    #define debug_v(x) 0;
    #define debug_vp(x) 0;
    #define say(x) 0;
#endif // HOME
 
lint mod = 998244353;
 
lint pow2(lint a, lint n) {
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return a % mod;
    }
    lint d = pow2(a, n / 2) % mod;
    lint ans = (d * d) % mod;
    if (n % 2) {
        ans *= a;
        ans %= mod;
    }
    return (ans % mod);
}
 
lint inv (lint a) {
    return pow2(a, mod - 2) % mod;
}
 
vector<lint> fact(2e5 + 4);
vector<lint> rev(2e5 + 4);
 
lint c_n_k(lint n, lint k) {
    return (fact[n] * (rev[k] * rev[n - k] % mod)) % mod;
}
 
void solve()
{
    lint n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    set<pair<int, int>> kek;
    for (int i = 0; i < n; i++) {
        vector<int> st;
        for (int j = i; j < n; j++) {
            st.push_back(arr[j]);
            while ((st.size() > 1) && (*st.rbegin() == *(next(st.rbegin())))) {
                st.pop_back();
                st.back()++;
            }
            if (st.size() == 1) {
                kek.insert({i, j});
            }
        }
    }
    /*for (auto x : kek) {
        cout << x.ff << " " << x.ss << endl;
    }*/
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int l = 0; l < n; l++) {
        for (int j = 0; j < n; j++) {
            if (j + l >= n) {
                break;
            }
            if (kek.find(make_pair(j, l + j)) != kek.end()) {
                dp[j][l + j] = 1;
            } else {
                dp[j][l + j] = 2000;
                for (int o = j; o < l + j; o++) {
                    //cout << i << " " << j << " " << o << endl;
                    //cout << dp[i][o] + dp[o + 1][i + j] << endl;
                    dp[j][l + j] = min(dp[j][l + j], dp[j][o] + dp[o + 1][l + j]);
                }
            }
        }
    }
    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/
    cout << dp[0][n - 1] << endl;
    return;
}
 
 
 
void stupid_solve() {
    //ifstream in("input.txt");
}
void generator() {
    freopen("test.txt", "w", stdout);
    int n = rand() % 3 + 3;
    int m = rand() % 3 + 3;
    cout << n << " " << m << endl;
    for (int i = 1; i < n; i++) {
        cout << rand() % i << " ";
    }
    cout << endl;
    for (int i = 0; i < 5; i++) {
        cout << rand() % n << " ";
    }
    cout << endl;
}
 
int main() {
    freopen("test.inp", "r", stdin);
freopen("test.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    bool stress = false;
    //stress = true;
    int t;
    t = 1;
    //cin >> t;
    for (int i = 0; i < t; i++) {
        if (!stress) {
            solve();
        } else {
            int tests = 100;
            for (int i = 0; i < tests; i++) {
                generator();
                solve();
            }
        }
    }
}