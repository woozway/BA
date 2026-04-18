#include <iostream>
using namespace std;
const int N = 12010, M = 2010; // 1000 * lg2000，上取整数N得12000
int v[N], w[N]; // 从v[1], w[1]开始存
int f[M]; // f[i]表示体积i所能装下的最大价值
int n, m;

// O(N*V*lgs) 利用倍增的思想将s件同类物品分解为lgs个新物品，然后用01背包解决
// 因为每个整数都可以用一个二进制数字来表示，而每种物品的体积和价值是相同的，
// 所以可以通过将 s 拆分成：2^0 + 2^1 + 2^2 + ... + r 来优化
int main() {
  cin >> n >> m; // 0<n<=1000, 0<m<=2000, 0<vi,wi,si<=2000

  int cnt = 0;
  for (int i = 0; i < n; i ++ ) {
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
    if (s > 0) { // 处理最后剩下的不足 2 的幂的部分
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