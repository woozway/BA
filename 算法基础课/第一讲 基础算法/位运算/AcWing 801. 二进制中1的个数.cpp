#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  while (n -- ) {
    int x, cnt = 0;
    scanf("%d", &x);
    while (x) x -= x & (-x), cnt ++ ; // lowbit操作
    printf("%d ", cnt);
  }
  return 0;
}