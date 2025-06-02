#include <iostream>
using namespace std;
typedef long long LL;
const int N = 1e6 + 10;
int phi[N];
int primes[N], cnt;
bool st[N];

void get_eulers(int x) {
  phi[1] = 1;
  for (int i = 2; i <= x; i ++ ) {
    if (!st[i]) {
      primes[cnt ++ ] = i;
      phi[i] = i - 1; // 从phi定义出发：如果i是质数，那么1~i中有i-1个与i互质
    }

    for (int j = 0; primes[j] <= x / i; j ++ ) {
      int t = primes[j] * i;
      st[t] = true;

      if (i % primes[j] == 0) { // 记pj=primes[j], 若pj是i的质因子
        phi[t] = phi[i] * primes[j]; // 则phi[pj*i] = (pj*i)*(1-1/p1)*..*(1-1/pk) = pj*phi(i)
        break;
      }
      phi[t] = phi[i] * (primes[j] - 1); // 否则phi(pj*i) = (pj*i)*(1-1/p1)*..*(1-1/pk)*(1-1/pj) = phi(i)*pj*(1-1/pj)
    }
  }
}

int main() {
  int n;
  cin >> n;

  get_eulers(n);

  LL res = 0;
  for (int i = 1; i <= n; i ++ ) res += phi[i];
  cout << res << endl;
  return 0;
}