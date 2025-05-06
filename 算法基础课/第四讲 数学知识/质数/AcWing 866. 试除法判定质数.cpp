#include <iostream>
using namespace std;

bool is_prime(int x) { // O(sqrt(x)) 试除法：如果x是合数，那么它一定有一个因子<=sqrt(x)
  if (x < 2) return false;
  for (int i = 2; i <= x/i; i++)
    if (x % i == 0) return false;
  return true;
}

int main() {
  int n;
  cin >> n;

  while (n--) {
    int a;
    cin >> a;
    if (is_prime(a)) puts("Yes");
    else puts("No");
  }

  return 0;
}