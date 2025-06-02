#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long LL;
const int mod = 1e9 + 7;
unordered_map<int, int> primes;

// N=(p1^a1)*(p1^a2)*...*(pk^ak), 约数之和=(p1^0+...+p1^a1)+...+(pk^0+...+pk^ak
int main() {
  int n;
  cin >> n;

  while (n -- ) {
    int a;
    cin >> a;
    for (int i = 2; i <= a / i; i ++ )
      if (a % i == 0)
        while (a % i == 0) a /= i, primes[i] ++ ;
    if (a > 1) primes[a] ++ ;
  }

  LL res = 1;
  for (auto prime : primes) {
    int p = prime.first, a = prime.second;

    LL t = 1;
    while (a -- ) t = (t * p + 1) % mod;
    res = res * t % mod;
  }
  cout << res << endl;
  return 0;
}