#include <iostream>
#include <cstring>
using namespace std;
const int N = 510, M = 1e5 + 10;
int h[N], e[M], ne[M], idx = 1;
int match[N];
bool st[N]; // 判断n2集合中的每个妹子是否已经被访问过

void add(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool find(int x) {
  for (int i = h[x]; i; i = ne[i]) {
    int j = e[i];
    if (!st[j]) {
      st[j] = true;
      if (!match[j] || find(match[j])) { // 当前j妹子没匹配或可以帮她匹配的哥们找下家
        match[j] = x;
        return true;
      }
    }
  }
  return false;
}

int main() { // O(nm)
  int n1, n2, m;
  cin >> n1 >> n2 >> m;

  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    add(u, v);
  }

  int res = 0;
  for (int i = 1; i <= n1; i++) {
    memset(st, 0, sizeof st); // 每一次都需要重新设置n2集合访问数组，以每个男生角度重新考虑
    if (find(i)) res++;
  }

  cout << res << endl;

  return 0;
}