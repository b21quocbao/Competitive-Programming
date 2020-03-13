///------------------  CODE FOR FUN -------------------
#include <bits/stdc++.h>
#define FOR(i,j,k) for(int i = j; i <= k; i ++)
#define FORD(i,j,k) for(int i = j; i >= k; i --)
#define mp make_pair
//#define f first
//#define s second
//#define int long long
using namespace std;
 
const int MOD=1e9+7;
const int N = 200005;
int T, n;
long long mu[N], a[N], k;
long long maxval = 0, dem = 0;
bool dd[N], ok ;
vector < long long > S;
//void pre()
//{
//    dem = 0;
//    mu[0] = 1;
//    while(maxval)
//    {
//        maxval /= k;
//        dem ++;
//        mu[dem] = mu[dem - 1] * k;
//    }
////    dem ++;
////    mu[dem] = mu[dem - 1] * k;
////    cout << dem << " ";
////    cout << mu[dem] << " ";
//}
//void check(int x)
//{
//    FORD(i, dem, 0)
//    {
//        if(x >= mu[i])
//        {
//            x -= mu[i];
//            if(dd[i]) ok = 0;
//            dd[i] = 1;
////            cout << 1;
//        }
////        else cout << 0;
//    }
//    cout << "\n";
//    if(x)
//    {
//        ok = 0;
//    }
//}
int main()
{
    freopen("test.inp", "r", stdin);
        freopen ("test.ans", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //#define task"C"
    //freopen(task".inp","r",stdin);
    //freopen(task".out","w",stdout);
    cin >> T;
    while(T --)
    {
        S.clear();
        maxval = 0;
        memset(dd, 0, sizeof(dd));
        ok = 1;
        cin >> n >> k;
        FOR(i, 1, n)
        {
            cin >> a[i];
        }
        FOR(i, 1, n)
        {
            long long mu = 1, dem = 0;
            while(mu <= a[i])
            {
                if(mu * k > a[i])
                {
                    S.push_back(dem);
                    a[i] -= mu;
                    mu = 1;
                    dem = 0;
                }
                else
                {
                    mu *= k;
                    dem ++;
                }
            }
        }
        sort(S.begin(), S.end());
        for(int i = 0; i + 1 < S.size(); i ++)
        {
            if(S[i] == S[i + 1]) ok = 0;
        }
        if(ok == 0) cout << "NO";
        else cout << "YES";
        cout << "\n";
    }
    return 0;
}