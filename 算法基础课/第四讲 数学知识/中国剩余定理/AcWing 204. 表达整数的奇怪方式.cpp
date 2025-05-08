#include <iostream>
using namespace std;
typedef long long ll;

ll exgcd(ll a, ll b, ll &x, ll &y) {
  if (!b) {
    x = 1, y = 0;
    return a;
  }
  ll d = exgcd(b, a%b, y, x);
  y -= a/b * x;
  return d;
}

int main() { // 两两合并x=k1*a1+m1, x=k2*a2+m2, ..., x=kn*an+mn
  int n;
  cin >> n;

  ll a1, m1;
  cin >> a1 >> m1;
  bool has_answer = true;
  for (int i = 0; i < n-1; i++) {
    ll a2, m2;
    cin >> a2 >> m2;

    ll k1, k2;
    ll d = exgcd(a1, a2, k1, k2);
    if ((m2 - m1) % d) { // 由x = k1*a1 + m1 = k2*a2 + m2 => k1*a1 - k2*a2 = m2 - m1，有解等价于(m2-m1)%d==0
      has_answer = false;
      break;
    }

    // 求得一个解k1,k2后，通解为：k1 + k*a2/d, k2 + k*a1/d (k为任意整数,这里只用到k1的通解)
    // x = k1*a1 + m1 = (k1+k*a2/d)*a1 + m1 = k1*a1+m1 + k*(a1*a2/d) = k*[a,b] + k1*a1+m1 = k*a + m
    k1 *= (m2 - m1) / d; // 等式两边扩大(m2-m1)/d倍才是解k1
    ll t = a2 / d;
    k1 = (k1%t + t) % t; // 将解变成一个最小的正整数解
    m1 = k1*a1 + m1; // 新方程的m
    a1 = abs(a1 / d * a2); // 新方程的a，即[a1,a2]
  }

  if (has_answer) cout << (m1%a1 + a1) % a1 << endl; // c++中语法关系，这里求的是m1模a1在数学意义上的余数
  else puts("-1");

  return 0;
}