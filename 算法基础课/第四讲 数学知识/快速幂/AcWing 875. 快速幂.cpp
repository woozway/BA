#include <iostream>
using namespace std;
typedef long long ll;

ll qmi(int a, int b, int p) { // 求a^b % p，b的二进制：bk..b1b0，那么a^b = a^b0 + a^2b1 + a^4b2 + ... = a^b0 + (a^2)^b1 + ((a^2)^2)^b2 + ...
  ll res = 1 % p;
  while (b) {
    if (b & 1) res = res * a % p;
    a = a * (ll)a % p;
    b >>= 1;
  }
  return res;
}

int main() {
  int n;
  cin >> n;

  while (n--) {
    int a, b, p;
    scanf("%d%d%d", &a, &b, &p);
    printf("%lld\n", qmi(a, b, p));
  }
  return 0;
}