#include <iostream>
using namespace std;
typedef long long ll;

ll qmi(int a, int b, int p) { // 逆元：a*x % m = 1, x记为a^-1；只有当gcd(a,m)=1时，a存在逆元（模m下）；常用exgcd来求逆元
  ll res = 1 % p;
  while (b) {
    if (b & 1) res = res * a % p;
    a = a * (ll)a % p;
    b >>= 1;
  }
  return res;
}

int main() { // 费马小定理：若p是质数，且a%p!=0，a^-1 = a^(p-2)（模p下）如果p不是质数，则需要使用exgcd来求逆元
  int n;
  cin >> n;

  while (n--) {
    int a, p;
    scanf("%d%d", &a, &p);

    ll res = qmi(a, p-2, p);
    if (a % p) printf("%lld\n", res);
    else printf("impossible\n");
  }

  return 0;
}