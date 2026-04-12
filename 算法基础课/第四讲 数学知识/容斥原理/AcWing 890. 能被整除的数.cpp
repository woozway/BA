#include <iostream>
using namespace std;
typedef long long LL;
const int N = 20;
int p[N];
int n, m;

// 在 1~n 的整数中，有多少个能被给定的 m 个质数中的至少一个整除：1<=m<=16, 1<=n,pi<=1e9
// 容斥原理：O(m * 2^m)：
// |S1∪S2∪S3| = (|S1|+|S2|+|S3|) - (|S1∩S2|+|S1∩S3|+|S2∩S3|) + |S1∩S2∩S3|
// 共有 C(n,1) + C(n,2) + ... + C(n,n) = (1+1)^n - C(n,0) = 2^n - 1 项：
//   1. 在 1~n 中，能被 p1 整除的数有 n/p1 个，所以 |S1| = n/p1
//   2. 能同时被 p1 和 p2 整除的数，必然能被它们的最小公倍数（因为是质数，所以就是乘积 p1*p2）整除
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i ++ ) cin >> p[i];

  int res = 0; // 把i看作二进制数，每位上1对应m个元素选中与否
  for (int i = 1; i < 1 << m; i ++ ) { // [1,2^m)共2^m-1项（至少选1个）
    int t = 1, s = 0; // t代表选出的质数的乘积，s 记录选中了几个质数
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
      if (s % 2) res += n / t; // 计算1~n中t倍数的元素个数
      else res -= n / t; // 奇加偶减
    }
  }
  cout << res << endl;

  return 0;
}