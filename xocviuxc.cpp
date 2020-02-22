#include <iostream>
#include <cstdlib>

using namespace std;

const int tope=2000;

void trasponer(int v[tope][tope],int vaux[tope][tope],int n,int m)
{
  for (int i=0;i<n;i++)
    for (int j=0;j<m;j++)
      vaux[j][i]=v[i][j];
}

void soluciona(int hor[tope][tope],int ver[tope][tope],int sol[tope][tope],int n,int m)
{
  sol[0][0]=0;
  for (int j=1;j<m;j++)
    sol[0][j]=sol[0][j-1]^hor[0][j-1];
  for (int i=1;i<n;i++) {
    sol[i][0]=sol[i-1][0]^ver[i-1][0];
    for (int j=1;j<m;j++)
      if ((sol[i][j-1]^hor[i][j-1]^ver[i-1][j])==sol[i-1][j])
	sol[i][j]=sol[i][j-1]^hor[i][j-1];
      else if (j<m-1)
	sol[i][j]=hor[i][j]^ver[i-1][j+1]^sol[i-1][j+1];
      else
	sol[i][j]=0;
  }
}

int n,m;
int hor[tope][tope];
int horaux[tope][tope];
int ver[tope][tope];
int veraux[tope][tope];
int sol[tope][tope];
int solaux[tope][tope];

int main()
{
  int k;
  cin>>n>>m>>k;
  int numdesigual=0;
  for (int j=0;j<m-1;j++) {
    char c;
    cin>>c;
    hor[0][j]=(c=='N');
    numdesigual+=(c=='N');
  }
  for (int i=0;i<n-1;i++) {
    for (int j=0;j<m-1;j++) {
      char c;
      cin>>c;
      ver[i][j]=(c=='N');
      numdesigual+=(c=='N');
    }
    
  }
  for (int i=0;i<n-1;i++) {
  for (int j=0;j<m;j++) {
      char c;
      cin>>c;
      hor[i+1][j]=(c=='N');
      numdesigual+=(c=='N');
    }
  }
  if (k==1) {
    if (4*numdesigual>n*(m-1)+m*(n-1)) {
      cout<<"-1"<<endl;
    } else {
      for (int i=0;i<n;i++) {
	for (int j=0;j<m;j++) {
	  if (j>0) cout<<" ";
	  cout<<1;
	}
	cout<<endl;
      }
    }
    exit(0);
  }
  if (m>=n) {
    soluciona(hor,ver,sol,n,m);
  } else {
    trasponer(hor,veraux,n,m-1);
    trasponer(ver,horaux,n-1,m);
    soluciona(horaux,veraux,solaux,m,n);
    trasponer(solaux,sol,m,n);
  }
  for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++) {
      if (j>0) cout<<" ";
      cout<<sol[i][j]+1;
    }
    cout<<endl;
  }
}