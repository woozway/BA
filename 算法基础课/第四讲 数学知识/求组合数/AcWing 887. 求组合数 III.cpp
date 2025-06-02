#include <iostream>
using namespace std;
typedef long long LL;

int qmi(int a, int k, int p) {
  int res = 1;
  while (k) {
    if (k & 1) res = (LL)res * a % p;
    a = (LL)a * a % p;
    k >>= 1;
  }
  return res;
}

int C(int a, int b, int p) {
  if (b > a) return 0;

  int res = 1;
  for (int i = 1, j = a; i <= b; i ++, j -- ) {
    res = (LL)res * j % p;
    res = (LL)res * qmi(i, p - 2, p) % p;
  }
  return res;
}

// 卢卡斯定理：c(a, b) % p = c(a%p, b%p) * c(a/p, b/p) % p

// (1+x)^p % p = [C(p,0)*x^0 + C(p,1)*x^1 + ... + C(p,p)*x^p] % p = 1+x^p（括号可拆，同理[(1+x)^p]^k % p == (1+x^p)^k % p）
// a = ak*pk + ak-1*pk-1 + ... + a0*p0 （转为类似p进制，ak,...,a0 = 0/1）
// b = bk*pk + bk-1*pk-1 + ... + b0*p0
// 所以：(1+x)^a = (1+x)^a0 + [(1+x)^p]^a1 + ... + [(1+x)^pk]^ak
//              = (1+x)^a0 + (1+x^p)^a1 + ... + (1+x^pk)^ak
// 此时观察等式两边x^b的系数（若bi>ai，则C(a,b)=0）：
//   C(a,b) % p = C(ak,bk) * C(ak-1,bk-1) * .. * C(a0,b0) % p
int lucas(LL a, LL b, int p) {
  if (a < p && b < p) return C(a, b, p);
  return (LL)C(a % p, b % p, p) * lucas(a / p, b / p, p) % p;
}

int main() { // O(p * lgN * lgp)
  int n;
  cin >> n;

  while (n -- ) {
    LL a, b;
    int p;
    cin >> a >> b >> p;
    cout << lucas(a, b, p) << endl;
  }
  return 0;
}