#include <iostream>
using namespace std;
const int N = 1e5 + 10, M = N * 2; // 无向图最多M=N*2条边
int h[N], e[M], ne[M], idx = 1; // h和st和节点数N有关，e和ne和边数M有关
bool st[N]; // 记录i节点是否被访问过
int n, res = N;

void add(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

int dfs(int u) { // 返回以u为根节点子树中总节点的个数
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
  size = max(size, n - sum); // 易遗漏，还有以u为根节点子树外的所有节点构成的连通图
  res = min(res, size); // 将节点u删除后，剩余各连通块中节点数的最大值
  return sum;
}

int main() {
  cin >> n;
  for (int i = 0; i < n - 1; i ++ ) {
    int a, b;
    scanf("%d%d", &a, &b);
    add(a, b), add(b, a);
  }

  dfs(1); // 从[1~n]任意一个点开始dfs都行
  cout << res << endl;
  return 0;
}