#include <iostream>
#include <unordered_set>
#include <cstring>
using namespace std;
const int N = 110;
int f[N];

// 因为最大值在不断减小，所以一定可以结束
// 分成两堆后，由SG定理得：SG(b1,b2) = SG(b1) ^ SG(b2);
int sg(int x) {
  if (f[x] != -1) return f[x];

  unordered_set<int> S;
  for (int i = 0; i < x; i ++ )
    for (int j = 0; j <= i; j ++ ) // 为避免重复，约定第2堆<第1堆
      S.insert(sg(i) ^ sg(j));

  for (int i = 0; ; i ++ )
    if (!S.count(i)) return f[x] = i;
}

int main() {
  int n;
  cin >> n;

  memset(f, -1, sizeof f);

  int res = 0;
  while (n -- ) {
    int x;
    cin >> x;
    res ^= sg(x);
  }

  if (res) puts("Yes");
  else puts("No");
  return 0;
}