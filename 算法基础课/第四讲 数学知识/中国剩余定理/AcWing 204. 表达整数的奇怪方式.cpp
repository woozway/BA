#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

// 在求 gcd(a, b) 的同时，找出一组解 x, y 满足：a*x + b*y = gcd(a, b)
LL exgcd(LL a, LL b, LL &x, LL &y) {
  if (!b) {
    x = 1, y = 0;
    return a;
  }
  LL d = exgcd(b, a % b, y, x);
  y -= a / b * x;
  return d;
}

// EXCRT 的思想：通过不断将两个同余方程合并成一个新方程，x % a1 = m1, x % a2 = m2, ...
// 两两合并 x = k1*a1+m1, x = k2*a2+m2, ..., x = kn*an+mn，最终将 n 个方程简化为一个

// x % a1 = m1, x % a2 = m2, ... => x = k1 * a1 + m1 = k2 * a2 + m2 = ...
// 联立：a1*k1 - a2*k2 = m2 - m1, 即 a1*u + a2*v = gcd(a1, a2), (mod a1 & mod a2), k1 = u, k2 = -v
// 获取特解：u' = u * (m2 - m1)/d, 通解：u = u' + k*a2/d, 其中k为任意整数，
// 将解代回：x = k1*a1 + m1 = (u' + k*a2/d)*a1 + m1 = (u'*a1 + m1) + k*lcm(a1,a2)，新的x = k*a1' + m1'
int main() {
  int n;
  cin >> n;

  LL a1, m1;
  cin >> a1 >> m1;
  bool has_answer = true;
  for (int i = 0; i < n - 1; i ++ ) {
    LL a2, m2, u, v;
    cin >> a2 >> m2;

    LL d = exgcd(a1, a2, u, v);
    if ((m2 - m1) % d) {
      has_answer = false;
      break;
    }
    u *= (m2 - m1) / d; // 获取一个特解
    LL t = a2 / d; // t表示u的通解周期，即u的所有解在模 (a2/d) 意义下是等价的
    u = (u % t + t) % t; // 获取最小非负特解，防止后续计算导致 LL 溢出
    m1 = u * a1 + m1; // 新方程的余数 m
    a1 *= t; // 或 a1 = abs(a1 / d * a2); 新方程的模数a，即lcm(a1, a2)
  }
  // c++中语法关系，这里求的是m1模a1在数学意义上的余数
  // 经过 n-1 次合并后，所有的方程都消失了，只剩下最后一个方程：x % a1 = m1
  if (!has_answer) cout << -1 << endl;
  else cout << (m1 % a1 + a1) % a1 << endl;
  return 0;
}