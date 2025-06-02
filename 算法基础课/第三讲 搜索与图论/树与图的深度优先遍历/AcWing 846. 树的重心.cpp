#include <iostream>
using namespace std;
const int N = 1e5 + 10, M = N * 2; // 最多M条边
int h[N], e[M], ne[M], idx = 1;
bool st[N]; // 记录i节点是否被访问过
int n, res = N;

void add(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

int dfs(int u) { // 返回以u为根节点的总节点个数
  st[u] = true;

  int sum = 1, size = 0; // sum记录以u为根的子树的总节点数；size记录删除u之后所有连通图最大的节点数
  for (int i = h[u]; i; i = ne[i]) {
    int j = e[i];
    if (!st[j]) {
      int s = dfs(j);
      size = max(size, s);
      sum += s;
    }
  }

  size = max(size, n - sum); // 还有以u为根节点子树外的所有节点
  res = min(res, size);

  return sum;
}

int main() {
  cin >> n;
  for (int i = 0; i < n - 1; i ++ ) {
    int a, b;
    scanf("%d%d", &a, &b);
    add(a, b), add(b, a);
  }

  dfs(1); // 从任意一个点开始dfs都行
  cout << res << endl;

  return 0;
}