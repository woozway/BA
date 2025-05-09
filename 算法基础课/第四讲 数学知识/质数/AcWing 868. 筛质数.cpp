#include <iostream>
using namespace std;
const int N = 1e6 + 10;
int n;
int primes[N], cnt;
bool st[N];

void get_primes() { // 1~n中有n/ln(n)个质数
  // // 1. O(nloglogn) 埃式筛，删掉质数的倍数（有些合数会重复筛）
  // for (int i = 2; i <= n; i++) {
  //   if (st[i]) continue;
  //   primes[cnt++] = i;
  //   for (int j = i+i; j <= n; j += i) st[j] = true;
  // }

  // 2. O(n) 欧拉筛：每个合数都被自己的最小质因子筛掉（虽然不是在同一个循环里）
  for (int i = 2; i <= n; i++) {
    if (!st[i]) primes[cnt++] = i;
    for (int j = 0; primes[j] <= n/i; j++) { // pj*i<=n，>n的数就不筛了
      st[primes[j] * i] = true; // 这里primes[j]一定是primes[j]*i的最小质因子
      if (i % primes[j] == 0) break; // primes[j]一定是i的最小质因子
    }
  }
}

int main() {
  cin >> n;

  get_primes();

  cout << cnt << endl;
  return 0;
}