#include <iostream>
using namespace std;
typedef long long ll;

int exgcd(int a, int b, int &x, int &y) {
  if (!b) {
    x = 1, y = 0;
    return a;
  }

  int d = exgcd(b, a%b, y, x);
  y -= a/b * x;

  return d;
}

int main() {
  int n;
  cin >> n;

  while (n--) {
    int a, b, m, x, y;
    scanf("%d%d%d", &a, &b, &m); // a*x % m = b -> a*x - m*y' = b，则有解的条件是d=gcd(a,m)是b的倍数

    int d = exgcd(a, m, x, y);
    if (b % d) puts("impossible"); // b不是d的倍数，无解
    else printf("%d\n", (ll)x * (b/d) % m); // 有解，等式两边分别放大b/d倍
  }
  return 0;
}