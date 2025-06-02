#include <iostream>
using namespace std;

// d = gcd(a, b), => d|a, d|b, 因为r = a - q*b，所以d = gcd(b, r)
int gcd(int a, int b) {
  return b ? gcd(b, a % b) : a;
}

int main() {
  int n;
  cin >> n;

  while (n -- ) {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", gcd(a, b));
  }
  return 0;
}