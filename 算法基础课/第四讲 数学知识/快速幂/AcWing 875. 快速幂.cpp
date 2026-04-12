#include <iostream>
using namespace std;
typedef long long LL;

// 求a^b % p，b的二进制（bk表示0/1）：bk,...,b1,b0，那么
// a^b = a^b0 * a^2b1 * a^4b2 * ... 
//     = a^b0 * (a^2)^b1 * ((a^2)^2)^b2 * ...
LL qmi(int a, int b, int p) {
  LL res = 1 % p;
  while (b) {
    if (b & 1) res = res * a % p;
    a = (LL)a * a % p;
    b >>= 1;
  }
  return res;
}

int main() {
  int n;
  cin >> n;

  while (n -- ) {
    int a, b, p;
    scanf("%d%d%d", &a, &b, &p);
    printf("%lld\n", qmi(a, b, p));
  }
  return 0;
}