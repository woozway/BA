#include <iostream>
using namespace std;
typedef long long LL;

LL qmi(int a, int b, int p) {
  LL res = 1 % p;
  while (b) {
    if (b & 1) res = res * a % p;
    a = (LL)a * a % p;
    b >>= 1;
  }
  return res;
}

// 1. 费马小定理：若整数a与p互质，且p是一个质数，则a^(p-1) ≡ 1 (mod p) => 在模p下逆元a^-1 = a^(p-2)，可用qmi计算
//   计算步骤：i. is_prime(p) && gcd(a, p)==1; ii. a^-1 = qmi(a, p-2, p)

// 2. 欧拉定理：若整数a与m互质，则a^phi(m) ≡ 1 (mod m)（当m是质数p时，即为费马小定理）=> 在模m下逆元a^-1 = a^(phi(m)-1)
//   计算步骤：i. gcd(a, m)==1; ii. phi(m); iii. a^-1 = qmi(a, phi(m)-1, m)

// 另外还可以使用扩展欧几里得算法exgcd直接求逆元（解线性同余方程ax + by = gcd(a,b)）：
//   若a,b互质，ax + by = 1；在模b时，ax ≡ 1 (mod b), 此时a^-1 = x (mod b)
int main() {
  int n;
  cin >> n;

  while (n -- ) {
    int a, p;
    scanf("%d%d", &a, &p);

    LL res = qmi(a, p - 2, p);
    if (a % p) printf("%lld\n", res); // 因为p是质数，a,p互质的条件是a%p != 0，即a不是p的倍数
    else printf("impossible\n");
  }
  return 0;
}