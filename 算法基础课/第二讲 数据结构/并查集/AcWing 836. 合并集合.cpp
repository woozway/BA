#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int p[N];

int find(int x) { // 寻找祖宗 + 路径压缩
  if (p[x] != x) p[x] = find(p[x]);
  return p[x];
}

int main() {
  ios::sync_with_stdio(false), cin.tie(0); // 加速

  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) p[i] = i; // 初始化：p[i]表示节点i的父节点

  char op;
  int a, b;
  while (m--) {
    cin >> op >> a >> b;
    if (op == 'M') p[find(a)] = find(b);
    else puts(find(a)==find(b) ? "Yes" : "No");
  }

  return 0;
}