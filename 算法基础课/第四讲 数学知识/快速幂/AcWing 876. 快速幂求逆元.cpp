#include <iostream>
using namespace std;
typedef long long ll;

ll qmi(int a, int b, int p) {
  ll res = 1 % p;
  while (b) {
    if (b & 1) res = res * a % p;
    a = a * (ll)a % p;
    b >>= 1;
  }
  return res;
}

// 1. 费马小定理：若整数a与m互质，且m是一个质数，则a^(m-1) % m == 1，逆元a^-1 = a^(m-2)，可用qmi计算
//   计算步骤：a. if (is_prime(m) && gcd(a,m)==1); b. a^-1 = qmi(a, m-2, m)

// 2. 欧拉定理：若整数a与p互质，则：a^phi(p) % p == 1（当p是质数m是，即为费马小定理），此时逆元a^-1 = a^(phi(m)-1)
//   计算步骤：a. gcd(a,m)==1; b. phi(m); c. a^-1 = qmi(a, phi(m)-1, m)

// 另外还可以使用扩展欧几里得算法exgcd直接求逆元（解线性同余方程ax + by = gcd(a,b)）：
//   若a,b互质，ax + by = 1；在模b时，ax = 1 (mod b), 此时a^-1 = x
int main() {
  int n;
  cin >> n;

  while (n--) {
    int a, p;
    scanf("%d%d", &a, &p);

    ll res = qmi(a, p-2, p);
    if (a % p) printf("%lld\n", res); // 因为m是质数，a,m互质的条件是a%m != 0，即a不是m的倍数
    else printf("impossible\n");
  }
  return 0;
}