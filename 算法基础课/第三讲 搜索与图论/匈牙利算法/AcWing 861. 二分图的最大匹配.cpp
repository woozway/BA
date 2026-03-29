#include <bits/stdc++.h>
using namespace std;
const int N = 510, M = 1e5 + 10;
int h[N], e[M], ne[M], idx = 1;
int match[N]; // match[j]保存和n2集合中j匹配的n1集合中的元素x
bool st[N]; // 判断n2集合中的每个妹子是否已经被访问过，避免陷入死循环
int n1, n2, m;

void add(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

bool find(int x) { // 给n1集合中的x寻找n2集合中的匹配，match成功就返true
  for (int i = h[x]; i; i = ne[i]) {
    int j = e[i];
    if (!st[j]) {
      st[j] = true;
      if (!match[j] || find(match[j])) { // 当前妹子j没匹配或可以帮她匹配的哥们找下家
        match[j] = x;
        return true;
      }
    }
  }
  return false;
}

int main() { // O(nm)
  cin >> n1 >> n2 >> m;

  while (m -- ) {
    int u, v;
    scanf("%d%d", &u, &v);
    add(u, v);
  }

  int res = 0;
  for (int i = 1; i <= n1; i ++ ) {
    memset(st, false, sizeof st); // 每一次都需要重新设置n2集合访问数组，以每个男生角度重新考虑
    if (find(i)) res ++ ; // 跑下一个find(j)时，部分被设置好的match会持续作用
  }

  cout << res << endl;
  return 0;
}