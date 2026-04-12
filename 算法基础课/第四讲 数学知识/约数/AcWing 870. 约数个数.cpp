#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod = 1e9 + 7;
unordered_map<int, int> primes;

// N=(p1^a1)*(p1^a2)*...*(pk^ak), 约数个数=(a1+1)*(a2+1)*...*(ak+1)
int main() {
  int n;
  cin >> n;

  while (n -- ) {
    int a;
    cin >> a;
    for (int i = 2; i <= a / i; i ++ )
      if (a % i == 0)
        while (a % i == 0) a /= i, primes[i] ++ ; // 这里不能写成primes[i] = s，因为有多个数
    if (a > 1) primes[a] ++ ;
  }

  LL res = 1;
  for (auto prime : primes) res = res * (prime.second + 1) % mod;
  cout << res << endl;
  return 0;
}