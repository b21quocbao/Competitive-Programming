#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
    freopen("test.inp", "r", stdin);
freopen("test.out", "w", stdout);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    a[i]--;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
    b[i]--;
  }
  vector<bool> in(n);
  int j = 0;
  for (int i = 0; i < n; i++) {
    int ans = 0;
    while (!in[b[i]]) {
      in[a[j++]] = true;
      ans++;
    }
    printf("%d ", ans);
  }
  putchar('\n');
}