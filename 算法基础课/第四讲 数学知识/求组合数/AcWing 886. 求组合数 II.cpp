#include <iostream>
using namespace std;
typedef long long LL;
const int N = 1e5 + 10, mod = 1e9 + 7;
int fact[N], infact[N];
int n;

// 预处理阶乘逆元，适用数据范围：1 <= n <= 1e4, 1 <= b <= a <= 1e5
// int的上限约2e9，存储时用int，计算时怕溢出用long long（上限约2e18）
int qmi(int a, int k, int p) {
  int res = 1 % p;
  while (k) {
    if (k & 1) res = (LL)res * a % p;
    a = (LL)a * a % p;
    k >>= 1;
  }
  return res;
}

// 因为模运算对于除法'/'没有分配律&结合律，所以要求逆：(i!)^-1 (mod p) = (i-1)!^-1 * i^-1 (mod p)
// 由欧拉定理得：整数a,m互质，a^-1 = qmi(a, phi(m) - 1, m), m = 1e9 + 7，所以phi(m) = m - 1
// 或由费马小定理得：整数a,m互质，m为质数，a^-1 = qmi(q, m - 2, m)
// O(NlgN) 因为c(a, b) = a!/((a-b)! * b!)，可以预处理阶乘fact和阶乘的逆infact
// 1/(a!) = 1/(a-1)! * 1/a = 1/(a-1)! * qmi(i, m - 2, m)
int main() {
  fact[0] = infact[0] = 1;
  for (int i = 1; i < N; i ++ ) {
    fact[i] = (LL)fact[i - 1] * i % mod;
    infact[i] = (LL)infact[i - 1] * qmi(i, mod - 2, mod) % mod;
  }

  cin >> n;
  while (n -- ) {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", (LL)fact[a] * infact[b] % mod * infact[a - b] % mod);
  }
  return 0;
}