#include <iostream>
using namespace std;
typedef long long ll;

int exgcd(int a, int b, int &x, int &y) {
  if (!b) {
    x = 1, y = 0;
    return a;
  }
  int d = exgcd(b, a%b, y, x);
  y -= a / b * x;
  return d;
}

int main() {
  int n, a, b, m, x, y;
  cin >> n;
  while (n--) {
    scanf("%d%d%d", &a, &b, &m); // a*x % m = b -> a*x - m*y' = b，令y=-y'
    int d = exgcd(a, m, x, y);
    if (b % d) puts("impossible"); // b不是d的倍数，无解
    else printf("%d\n", (ll)x * (b/d) % m); // 有解，等式两边分别放大b/d倍
  }
  return 0;
}