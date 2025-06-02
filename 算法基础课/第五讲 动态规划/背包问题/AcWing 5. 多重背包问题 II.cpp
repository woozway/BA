#include <iostream>
using namespace std;
const int N = 12010, M = 2010; // 1000 * lg2000，上取整数N得12000
int v[N], w[N];
int f[M];

// O(N*V*lgs) 利用倍增的思想将s件同类物品分解为lgs个新物品，然后用01背包解决
int main() {
  int n, m;
  cin >> n >> m;

  int cnt = 0;
  for (int i = 1; i <= n; i ++ ) {
    int a, b, s;
    cin >> a >> b >> s;
    int k = 1;
    while (k <= s) {
      cnt ++ ;
      v[cnt] = a * k;
      w[cnt] = b * k;
      s -= k;
      k *= 2;
    }
    if (s > 0) {
      cnt ++ ;
      v[cnt] = a * s;
      w[cnt] = b * s;
    }
  }

  n = cnt;
  for (int i = 1; i <= n; i ++ )
    for (int j = m; j >= v[i]; j -- )
      f[j] = max(f[j], f[j - v[i]] + w[i]);

  cout << f[m] << endl;
  return 0;
}