#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif
#define int long long

const int mn=100005;

vector <pair <pair <int, int>, int> > sub[mn*2];
vector <pair <pair <int, int>, int> > plu[mn*2];

pair <pair <int, int>, int> Bish[mn];
int n, m, c, t;

int find_ans(vector <pair <pair <int, int>, int> > V)
{
  if (V.size()<2) return V.size();
  vector <pair <int, int> > T={{-1000009, 0}};

  int ret=1;
//  cerr<<deb<<'\n';
  for (int i=0; i<V.size(); i++)
  {
    //Binsearch
    int l=0, r=T.size()-1;
    int Lval=V[i].first.first-V[i].second*V[i].second;
    while (r>l)
    {
      int mid=(r+l)/2+1;
      if (Lval<T[mid].first) r=mid-1; //need to re-clarify
      else l=mid;
    }

    //Update
    int Sval=T[l].second+1;
    ret=max(ret, Sval);
    int Rval=V[i].first.first+V[i].second*V[i].second+c-1;
//    while (T.back().first>=Rval) T.pop_back();

    if (Sval>T.back().second) T.push_back({Rval, Sval});

  }
  return ret;
}

bool sort1(pair <pair <int, int>, int> a1, pair <pair <int, int>, int> a2)
{
  if ((a1.first.first+a1.second*a1.second)==(a2.first.first+a2.second*a2.second)) return a1>a2;
  return (a1.first.first+a1.second*a1.second)<(a2.first.first+a2.second*a2.second);
}

signed main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
freopen("test.inp", "r", stdin);
freopen("test.ans", "w", stdout);
  scanf("%lld", &t);
  while (t--)
  {
    for (int i=0; i<mn*2; i++) sub[i].clear(), plu[i].clear();
    int x, y, p;
//    cin>>n>>m>>c;
    scanf("%lld%lld%lld", &n, &m, &c);
    for (int i=1; i<=m; i++) 
    {
//      cin>>x>>y>>p;
      scanf("%lld%lld%lld", &x, &y, &p);
      Bish[i]={{x, y}, p};
      sub[x-y+mn].push_back(Bish[i]);
      plu[x+y].push_back(Bish[i]);
    }

    for (int i=0; i<mn*2; i++) 
    {
      sort(sub[i].begin(), sub[i].end(), sort1);
      sort(plu[i].begin(), plu[i].end(), sort1);
    }

    int ret=0;
    for (int i=0; i<mn*2; i++)
    {
      int ans=find_ans(sub[i]);
      ret=max(ret, ans);
      ans=find_ans(plu[i]);
      ret=max(ret, ans);
    }
    printf("%lld\n", ret);
  }
}