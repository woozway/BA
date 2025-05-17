#include <cstring>
#include <iostream>
using namespace std;
const int N = 6010;
int h[N], e[N], ne[N], idx = 1;
int happy[N];
int f[N][2];
bool has_fa[N];

void add(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

// f[u,0]: 所有从以u为根的子树中选择，并且不选u这个点的方案
// f[u,1]: ...，且选择u这个点的方案
void dfs(int u) {
  f[u][1] = happy[u];

  for (int i = h[u]; i; i = ne[i]) {
    int j = e[i];
    dfs(j);

    f[u][1] += f[j][0];
    f[u][0] += max(f[j][0], f[j][1]);
  }
}

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%d", &happy[i]);

  for (int i = 0; i < n-1; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    add(b, a);
    has_fa[a] = true;
  }

  int root = 1;
  while (has_fa[root]) root++;

  dfs(root);

  cout << max(f[root][0], f[root][1]) << endl;
  return 0;
}