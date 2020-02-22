#include<bits/stdc++.h>
using namespace std;
#define F1(i, a, b) for(int i = a; i <= b; ++i)
#define F2(i, a, b) for(int i = a; i >= b; --i)
const int maxn = 1e3 + 10;
typedef pair<int, int> ii;
int n, a[maxn][maxn], b[maxn][maxn], c[maxn][maxn];
bool spc1 = 0, spc2 = 0, sp[maxn], ok[maxn];
vector<ii> res;
vector<int> e;
int turn(int x)
{
   return 0 - x;
}
void init()
{
   int dem;
   F1(j, 1, n) {
      dem = 0;
      F1(i, 1, n) if (a[i][j] == 0) ++dem;
      if (dem >= n - 1) sp[j] = 1;
   }
   int j = 1;
   dem = 0;
   F1(i, 1, n) {
      if (a[i][j] == 0) ++dem;
      ++j;
   }
   if (dem >= n - 1) spc1 = 1;
   dem = 0;
   j = n;
   F1(i, 1, n) {
      if (a[i][j] == 0) ++dem;
      --j;
   }
   if (dem >= n - 1) spc2 = 1;
}
bool kq(int tt)
{
   res.clear();
   if (tt == 2 || tt == 5 || tt == 6 || tt == 8) {
      res.push_back(ii(1, 1));
      F1(j, 1, n) a[1][j] = turn(a[1][j]);
   }
   if (tt == 3 || tt == 5 || tt == 7 || tt == 8) {
      res.push_back(ii(3, 1));
      int j = 1;
      F1(i, 1, n) {
         a[i][j] = turn(a[i][j]);
         ++j;
      }
   }
   if (tt == 4 || tt == 6 || tt == 7 || tt == 8) {
      res.push_back(ii(3, 2));
      int j = n;
      F1(i, 1, n) {
         a[i][j] = turn(a[i][j]);
         --j;
      }
   }
   memset(ok, 1, sizeof(ok));
   F1(j, 1, n) if (a[1][j] == b[1][j] && a[1][j]) ok[j] = 0;
   F1(j, 1, n)
      if (a[1][j] != b[1][j] && ok[j]) {
         F1(k, 1, n) a[k][j] = turn(a[k][j]);
         res.push_back(ii(2, j));
         ok[j] = 0;
      }
   F1(i, 2, n) {
      int dem = 0;
      F1(j, 1, n) if (a[i][j] != b[i][j]) ++dem;
      if (dem == n) res.push_back(ii(1, i));
       else if (dem > 0) {
        bool check = 1;
        F1(j, 1, n) if (a[i][j] != b[i][j] && ok[j] == 0) check = 0;
        if (check) {
            F1(j, 1, n) if (a[i][j] != b[i][j]) {
                ok[j] = 0;
                res.push_back(ii(2, j));
                F1(k, 1, n) a[k][j] = turn(a[k][j]);
            }
        }
        else {
            F1(j, 1, n) a[i][j] = turn(a[i][j]);
            F1(j, 1, n) if (a[i][j] != b[i][j] && ok[j] == 0) return 0;
            res.push_back(ii(1, i));
            F1(j, 1, n) if (a[i][j] != b[i][j]) {
                F1(k, 1, n) a[k][j] = turn(a[k][j]);
                res.push_back(ii(2, j));
            }
        }
       }
      F1(j, 1, n) if (a[i - 1][j] == 0 && a[i][j] != 0) ok[j] = 0;
   }
   cout << res.size() << '\n';
   if (res.size()) F1(i, 0, res.size() - 1) cout << res[i].first << ' ' << res[i].second << '\n';
   return 1;
}
void sol()
{
   F1(i, 1, n)
    F1(j, 1, n) if ((a[i][j] == 0 && b[i][j] != 0) || (a[i][j] != 0 && b[i][j] == 0)) {
      cout << -1;
      return;
    }
   F1(i, 1, 8) {
      F1(j, 1, n)
       F1(k, 1, n) a[j][k] = c[j][k];
      if (kq(i)) return;
   }
   cout << -1;
}
int main()
{
   freopen("tab.inp", "r", stdin);
   freopen("tab.out", "w", stdout);
   scanf("%d", &n);
   F1(i, 1, n)
    F1(j, 1, n) scanf("%d", &a[i][j]);
   F1(i, 1, n)
    F1(j, 1, n) c[i][j] = a[i][j];
   F1(i, 1, n)
    F1(j, 1, n) scanf("%d", &b[i][j]);
   init();
   sol();
   return 0;
}
