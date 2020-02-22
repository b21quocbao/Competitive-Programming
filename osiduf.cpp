#include <iostream>
#include <unordered_set>
using namespace std;
int n,m;
long long res;
unordered_set<int> red[100001];
int d[100001];
template <typename T>
void doc(T& x){
  char c;
  for(c=getchar();c<'0' || c>'9';c=getchar());
  x=c-'0';
  for(c=getchar();c>='0' && c<='9';c=getchar()) x=x*10+c-'0';
}
template <typename T>
void viet(T x){
  if(x>9) viet(x/10);
  putchar(x%10+'0');
}
void nhap(){
  doc(n);doc(m);
}
void xuly(){
	res=n;
	res*=n-1;
	res*=n-2;
	res/=6;
  while(m--){
    int x,y;
    doc(x);doc(y);
    if (x > y) swap (x, y);
    if(!red[x].count(y)){
      res+=d[x]+d[y]-n+2;
      ++ d[x]; ++ d[y];
      red[x].emplace(y);
      viet(res);
      putchar('\n');
    }
    else{
      red[x].erase(y);
      -- d[x]; -- d[y];
      res+=n-2-d[x]-d[y];
      viet(res);
      putchar('\n');
    }
  }
}
main(){
  nhap();
  xuly();
}
