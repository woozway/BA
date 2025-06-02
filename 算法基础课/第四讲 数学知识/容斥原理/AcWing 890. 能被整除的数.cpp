#include <iostream>
using namespace std;
typedef long long LL;
const int N = 20;
int p[N];

// 容斥原理：O(m * 2^m)
// |S1∪S2∪S3| = (|S1|+|S2|+|S3|) - (|S1∩S2|+|S1∩S3|+|S2∩S3|) + |S1∩S2∩S3|
// 共有C(n,1) + C(n,2) + ... + C(n,n) = (1+1)^n - C(n,0) = 2^n -1项
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i ++ ) cin >> p[i];

  int res = 0; // 把i看作二进制数，每位上1对应m个元素选中与否
  for (int i = 1; i < 1 << m; i ++ ) {
    int t = 1, s = 0; // t代表选出的质数的乘积
    for (int j = 0; j < m; j ++ )
      if (i >> j & 1) {
        if ((LL)t * p[j] > n) {
          t = -1;
          break;
        }
        t *= p[j];
        s ++ ;
      }
    if (t != -1) {
      if (s % 2) res += n / t;
      else res -= n / t;
    }
  }
  cout << res << endl;

  return 0;
}