#include <bits/stdc++.h>
using namespace std;
#define int long long
const int rm=RAND_MAX+1;
const string fn="ho";
int cn;
int ran(int a,int b){
  int x=a+((int)rand()*rm*rm*rm+(int)rand()*rm*rm+(int)rand()*rm+(int)rand())%(b-a+1);
  return x;
}
int mak(int a,int b){
  int c=ran(0,2);
  if(!c) return a;
  if(c==1) return b;
  return ran(a,b);
}
void work (){
  ofstream ou ("test.inp");
  //start here
  //remember ou <<
  //int n=ran(1,10000);
  //ou<<n<<"\n";
  //for(int i=0;i<n;i++) ou<<(char)ran('a','z');
  //end here
    int m=ran(2000,2000),n=ran(2000,2000);
    ou<<m<<" "<<n<<"\n";
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            ou<<ran(0,1)<<" ";
        }
        ou<<"\n";
    }
}
bool work1(){
  ifstream in ("test.inp");
  ifstream ou ("test.out");
  ifstream an ("test.ans");
  //checker
  //end
  //cerr<<"ok\n";
//  int n;
//  string s1,s2,s3;
//  in>>n;
//  in>>s1;
//  ou>>s2;
//  an>>s3;
//  if(s2=="Impossible" && s3!=s2) return 1;
//  if(s3=="Impossible" && s2!=s3) return 1;
//  if(s2=="Impossible") return 0;
//  for(int i=0;i<n;i++){
//    if(s1[i]==s2[i]){
//      cerr<<i<<"\n";
//      return 1;
//    }
//  }
//  return 0;
    int m,n,x,l,k;
    int a[m+5],b[n+5];
    in>>m;
    in>>n;
    for(int i=1;i<=m;i++) in>>a[i];
    for(int i=1;i<=n;i++) in>>b[i];
    ou>>x;
    return 0;
}
main(){
  srand(time(nullptr));
  for(int i=0;i<1;i++){
    work();
    system("work.exe");
    system("trau.exe");
    if(system("fc test.out test.ans"))
    return 0;
//    if(work1()) return 0;
  }
  //cerr<<cn;
  cerr<<"ok";
}
