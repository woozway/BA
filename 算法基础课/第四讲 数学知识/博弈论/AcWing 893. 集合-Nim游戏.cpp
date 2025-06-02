#include <iostream>
#include <cstring>
#include <unordered_set>
using namespace std;
const int N = 110, M = 10010;
int n, k, s[N], f[M];

int sg(int x) { // SG(x) = mex({SG(y1), SG(y2), …, SG(yk)})
  if (f[x] != -1) return f[x]; // 记忆化搜索

  unordered_set<int> S; // 存所有x可以到的值
  for (int i = 0; i < k; i ++ ) {
    int sum = s[i];
    if (x >= sum) S.insert(sg(x - sum));
  }

  for (int i = 0; ; i ++ ) // mex操作
    if (!S.count(i)) return f[x] = i;
}

int main() {
  cin >> k;
  for (int i = 0; i < k; i ++ ) cin >> s[i];
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