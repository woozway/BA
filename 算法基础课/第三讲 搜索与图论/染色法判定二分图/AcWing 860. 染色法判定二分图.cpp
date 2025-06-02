#include <iostream>
using namespace std;
const int N = 1e5 + 10, M = N * 2;
int h[N], e[M], ne[M], idx = 1;
int color[N];

void add(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

bool dfs(int u, int c) { // 染色法 O(n+m)
  color[u] = c;

  for (int i = h[u]; i; i = ne[i]) {
    int j = e[i];
    if (!color[j]) {
      if (!dfs(j, 3 - c)) return false;
    }
    else if (color[j] == c) return false;
  }

  return true;
}

int main() { // 一个图能被染色成二分图当且仅当图中没有奇数环
  int n, m;
  cin >> n >> m;
  while (m -- ) {
    int u, v;
    scanf("%d%d", &u, &v);
    add(u, v), add(v, u);
  }

  bool flag = true;
  for (int i = 1; i <= n; i ++ ) // 图中可能有多个连通块
    if (!color[i])
      if (!dfs(i, 1)) { // 染色1和2
        flag = false;
        break;
      }

  if (flag) puts("Yes");
  else puts("No");
  return 0;
}