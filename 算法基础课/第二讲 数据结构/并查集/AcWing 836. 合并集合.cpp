#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int p[N];
int n, m;

int find(int x) { // 寻找祖宗 + 路径压缩
  if (p[x] != x) p[x] = find(p[x]);
  return p[x];
}

int main() {
  cin >> n >> m;

  for (int i = 1; i <= n; i ++ ) p[i] = i; // 初始化：p[i]表示节点i的父节点

  while (m -- ) {
    char op;
    int a, b;

    cin >> op >> a >> b;
    if (op == 'M') p[find(a)] = find(b);
    else puts(find(a) == find(b) ? "Yes" : "No");
  }
  return 0;
}