#include <iostream>
using namespace std;
typedef long long LL;

int qmi(int a, int k, int p) {
  int res = 1 % p;
  while (k) {
    if (k & 1) res = (LL)res * a % p;
    a = (LL)a * a % p;
    k >>= 1;
  }
  return res;
}

// 求组合数：c(a, b) = a!/(b! * (a-b)!) = a*(a-1)*..*(a-b+1) / b!
int C(int a, int b, int p) {
  if (b > a) return 0;

  int res = 1;
  for (int i = 1, j = a; i <= b; i ++ , j -- ) {
    res = (LL)res * j % p;
    res = (LL)res * qmi(i, p - 2, p) % p;
  }
  return res;
}

// 卢卡斯定理：C(a, b) % p = C(a % p, b % p) * C(a / p, b / p) % p
// 时间复杂度：O(p log_p N)，适合数据范围：1 <= n <= 20, 1 <= b <= a <= 10^18, 1 <= p <= 1e5
// 1. 二项式展开模 p 的性质：
//   (1 + x)^p % p = [C(p, 0) * x^0 + C(p, 1) * x^1 + ... + C(p, p) * x^p] % p = 1 + x^p
//   （括号可拆分，同理 [(1 + x)^p]^k % p = (1 + x^p)^k % p）
// 2. 将 a 和 b 转换为 p 进制表示：
//   a = a_k * p^k + a_{k-1} * p^{k-1} + ... + a_0 * p^0
//   b = b_k * p^k + b_{k-1} * p^{k-1} + ... + b_0 * p^0
//   （其中 a_i 和 b_i 是 a 和 b 在 p进制下的位）
// 3. 递归分解组合数：
//   (1 + x)^a = (1 + x)^a_0 * [(1 + x)^p]^a_1 * ... * [(1 + x)^p^k]^a_k
//             = (1 + x)^a_0 * (1 + x^p)^a_1 * ... * (1 + x^{p^k})^a_k
//   二项式展开中 x^b 的系数就是 C(a, b)（若某个位 b_i > a_i，则 C(a, b) = 0）
// 4. 最终公式：
//   在每一项中，组合数 C(a, b) 的系数对应于逐位上的选择（a_i中选b_i）：
//     C(a, b) % p = C(a_k, b_k) * C(a_{k-1}, b_{k-1}) * .. * C(a_0, b_0) % p
int lucas(LL a, LL b, int p) {
  if (a < p && b < p) return C(a, b, p);
  return (LL)C(a % p, b % p, p) * lucas(a / p, b / p, p) % p;
}

int main() { // O(p * lgN * lgp)
  int n;
  cin >> n;
  while (n -- ) {
    LL a, b;
    int p;
    cin >> a >> b >> p;
    cout << lucas(a, b, p) << endl;
  }
  return 0;
}