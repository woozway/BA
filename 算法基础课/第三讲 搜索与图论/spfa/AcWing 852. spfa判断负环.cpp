#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int N = 2e3 + 10, M = 1e4 + 10;
int n, m;
int h[N], e[M], w[M], ne[M], idx = 1;
int dist[N], cnt[N]; // cnt[i]保存到达i节点有几条不同路径
bool st[N];

void add(int a, int b, int c) {
  e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool spfa() { // 由于抽屉原理得：若cnt[i]>=n（即一条路径上遇到了n+1个点），7那么肯定存在负环
  queue<int> q; // 这里不再需要初始化dist了，因为dist不再记录最短路径，而只是为了跑cnt

  for (int i = 1; i <= n; i++) { // 因为从某一特定点出发的线路不一定经过环，所以加入所有点
    q.push(i);
    st[i] = true; // 记录是否在队列里
  }

  while (q.size()) {
    auto t = q.front(); q.pop();
    st[t] = false;

    for (int i = h[t]; i; i = ne[i]) {
      int j = e[i];
      if (dist[j] > dist[t] + w[i]) {
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

  for (int i = 0; i < m; i++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    add(x, y, z);
  }

  if (spfa()) puts("Yes");
  else puts("No");

  return 0;
}