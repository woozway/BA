#include <iostream>
using namespace std;
typedef long long LL;
const int N = 100010, mod = 1e9 + 7;

// 这里的mod是质数，可用快速幂qmi求逆元，否则要用扩展欧几里得exgcd求逆元
int qmi(int a, int k, int p) {
  int res = 1;
  while (k) {
    if (k & 1) res = (LL)res * a % p;
    a = (LL)a * a % p;
    k >>= 1;
  }
  return res;
}

// 卡特兰数Catalan：作图从(0,0)->(n,n)不经过对角线往上移一步的红线的方案数
// (n,n)点关于y=x+1（红线）的对称点为(n-1,n+1)
// 轴对称变换后可得非法方案数：C(2n,n)-C(2n,n-1)=C(2n,n)/(n+1)，剩下即为合法方案数
int main() {
  int n;
  cin >> n;

  int a = n * 2, b = n;
  int res = 1;
  for (int i = a; i > a - b; i -- ) res = (LL)res * i % mod;
  for (int i = 1; i <= b; i ++ ) res = (LL)res * qmi(i, mod - 2, mod) % mod;
  res = (LL)res * qmi(n + 1, mod - 2, mod) % mod;

  cout << res << endl;
  return 0;
}