#include <iostream>
using namespace std;
typedef long long LL;
const int mod = 1e9 + 7;

// 这里的 mod 是质数，可用快速幂 qmi 求逆元，否则要用扩展欧几里得 exgcd 求逆元
int qmi(int a, int k, int p) {
  int res = 1 % p;
  while (k) {
    if (k & 1) res = (LL)res * a % p;
    a = (LL)a * a % p;
    k >>= 1;
  }
  return res;
}

// 卡特兰数 Catalan：作图从 (0, 0) -> (n, n) 不经过对角线往上移一步的红线的方案数
// (n, n) 点关于 y = x+1（红线）的对称点为 (n-1, n+1)，对于每条经过红线的非法路径，
// 可将其在第一次碰到 y = x+1 后的剩余部分关于红线作轴对称变换，得(0, 0) -> (n-1, n+1)为非法路径总数，
// 二者相减即为合法方案数：C(2n, n) - C(2n, n-1) = C(2n, n) / (n+1)
// C(a, b) = a*(a-1)*..*(a-b+1) / b!
int main() {
  int n;
  cin >> n;

  int res = 1;
  for (int i = n * 2, j = 1; j <= n; i -- , j ++ ) {
    res = (LL)res * i % mod;
    res = (LL)res * qmi(j, mod - 2, mod) % mod;
  }
  res = (LL)res * qmi(n + 1, mod - 2, mod) % mod;

  cout << res << endl;
  return 0;
}