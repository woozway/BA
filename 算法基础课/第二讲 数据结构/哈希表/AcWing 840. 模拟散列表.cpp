#include <iostream>
using namespace std;
const int N = 1e5 + 10, P = 100003; // 素数
int h[N], e[N], ne[N], idx = 1;

void insert(int x) {
  int k = (x % P + P) % P; // c++中负数求余是负数，这里保证k>=0
  e[idx] = x, ne[idx] = h[k], h[k] = idx ++ ;
}

bool query(int x) {
  int k = (x % P + P) % P;
  for (int i = h[k]; i; i = ne[i])
    if (e[i] == x) return true;
  return false;
}

int main() { // 拉链法
  int n;
  cin >> n;

  char op;
  int x;
  while (n -- ) {
    cin >> op >> x;
    if (op == 'I') insert(x);
    else puts(query(x) ? "Yes" : "No");
  }
  return 0;
}