#include <iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<deque>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<cstdio>
#include <utility>
#include <cstring>
#include <bitset>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
#define inf 92233720368547757
#define mn 200005
#define FLN "test"
#define int long long
typedef pair<int, int> ii;
//common data structures and templates
template<typename T>
struct SegmentTree{
};
//gb
int n;
int pos[mn];
int cl, cr;
//functions here
void input(){
}
void solve(){
}

//#define LOCAL 1

signed main(signed argc, char** argv) {
    freopen("test.inp", "r", stdin);
freopen("test.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
#ifdef LOCAL
	   freopen(FLN".inp", "r", stdin);
	   freopen(FLN".out", "w", stdout);
#endif
	cin >> n; char c; int id;
	cl = 0; cr = 0;
	for(int i=1; i<= n; i++){
		cin >> c >> id;
	//	cerr << c << " " << id << "\n";
		if(i== 1){
			if(c == 'L') pos[id] = cl;
			else pos[id] = cr;
			cl--; cr++;
		}
		else{
			if(c =='L') pos[id] = cl, cl--;
			else{
				if(c == 'R')pos[id] = cr, cr++;
				else{
					cout << min(pos[id]-cl-1, cr-pos[id]-1) << "\n";
				}
			}
		}
	}
	return 0;
}
