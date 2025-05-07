#include <iostream>
using namespace std;

int exgcd(int a, int b, int &x, int &y) { // 在求gcd(a,b)的同时，找出一组解x,y满足：a*x + b*y = gcd(a,b)
  if (!b) {
    x = 1, y = 0; // a*1 + b*0 = a
    return a;
  }

  // int x1, y1;
  // int d = exgcd(b, a%b, x1, y1); // b*x1 + (a%b)*y1 = d, => 左边：b*x1 + (a - a/b * b)*y1 => a*y1 + b*(x1 - a/b*y1)
  // x = y1, y = x1 - a/b * y1;

  int d = exgcd(b, a%b, y, x); // 如果把x1,y1改成y,x 则x=x, y=y-a/b*x
  y -= a/b * x;

  return d;
}

int main() {
  int n;
  cin >> n;

  while (n--) {
    int a, b, x, y;
    scanf("%d%d", &a, &b);

    exgcd(a, b, x, y);
    printf("%d %d\n", x, y);
  }

  return 0;
}