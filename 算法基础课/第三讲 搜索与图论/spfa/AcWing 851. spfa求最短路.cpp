#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, M = N;
int h[N], e[M], w[M], ne[M], idx = 1;
int dist[N];
bool st[N]; // 用于记录节点i是否已经在队列里
int n, m;

void add(int a, int b, int c) {
  e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

// spfa正确性依赖于：
//   1. 松弛操作最终会传播到所有受影响的节点
//   2. 在执行完所有松弛操作后，dist 数组会收敛到正确的最短路径值
void spfa() { // 最差O(nm)：是对bf的优化，适合于稀疏图
  memset(dist, 0x3f, sizeof dist);
  queue<int> q;
  dist[1] = 0;
  q.push(1);
  st[1] = true;

  while (q.size()) { // 区别于bf的无脑更新，spfa使用FIFO队列仅优化那些dist发生了变化的点
    auto t = q.front(); q.pop(); // 和dijkstra不同，spfa并不保证队头拿出的节点已经是距离最小的
    st[t] = false;

    for (int i = h[t]; i; i = ne[i]) {
      int j = e[i];
      if (dist[j] > dist[t] + w[i]) { // 这里不能写成if (!st[j] && dist[j] > dist[t] + w[i])
        dist[j] = dist[t] + w[i]; // 这里是w[i]不是j，因为i是那条边idx
        if (!st[j]) { // 若j已经在队列中，但发现了到达j的更短路径，写在外边就无法更新了
          q.push(j);
          st[j] = true;
        }
      }
    }
  }
}

int main() { // 单源最短路
  cin >> n >> m;
  while (m -- ) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    add(x, y, z);
  }

  spfa();
  if (dist[n] == 0x3f3f3f3f) puts("impossible"); // spfa是判断if (dist[j] > dist[t] + w[i])再更新，所以不会出现bf中0x3f3f3f/2的情况
  else printf("%d\n", dist[n]);

  return 0;
}