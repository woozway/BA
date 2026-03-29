#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10, M = 1e4 + 10;
int h[N], e[M], w[M], ne[M], idx = 1;
int dist[N], cnt[N]; // cnt[i] 记录从起点到节点 i 的当前最短路径所包含的边数
bool st[N]; // 记录是否在队列里
int n, m;

void add(int a, int b, int c) {
  e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

// 抽屉原理：在 n 个点的图中，任意不含负环的最短路最多包含 n-1 条边
// 若 cnt[i] >= n，说明路径上至少有 n+1 个点，则一定存在重复点，即存在负环
// 不需要初始化 dist 为无穷大，因为我们只关心 dist 的相对减小过程
// 即使全部初始为 0，只要有负权边 w，0 > 0 + w 就会成立并触发松弛
bool spfa() {
  queue<int> q;
  for (int i = 1; i <= n; i ++ ) { // 因为从某一特定点出发的线路不一定经过环，所以加入所有点
    q.push(i);
    st[i] = true;
  }

  while (q.size()) {
    auto t = q.front(); q.pop();
    st[t] = false;

    for (int i = h[t]; i; i = ne[i]) {
      int j = e[i];
      if (dist[j] > dist[t] + w[i]) { // 每进行一次成功的松弛，意味着找到了一条更短的路径
        dist[j] = dist[t] + w[i];

        cnt[j] = cnt[t] + 1; 
        if (cnt[j] >= n) return true;

        if (!st[j]) {
          q.push(j);
          st[j] = true;
        }
      }
    }
  }
  return false;
}

int main() {
  cin >> n >> m;
  while (m -- ) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    add(x, y, z);
  }

  if (spfa()) puts("Yes");
  else puts("No");
  return 0;
}