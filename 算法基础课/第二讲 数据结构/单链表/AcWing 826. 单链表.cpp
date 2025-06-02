#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int e[N], ne[N], idx;

void init() {
  idx = 1; // 默认0是dummy_head，idx存储当前已经用到了哪个点
}

void add(int i, int x) { // 在下标是i的节点的下个位置插入一个数x
  e[idx] = x, ne[idx] = ne[i], ne[i] = idx ++ ;
}

void del(int i) { // 删除下标是i的节点的下一个
  ne[i] = ne[ne[i]];
}

int main() {
  init();

  int m;
  cin >> m;

  char op;
  int k, x;
  while (m -- ) {
    cin >> op; // 不要写scanf("%c", &op)，会坑
    if (op == 'H') cin >> x, add(0, x);
    else if (op == 'I') cin >> k >> x, add(k, x); // 这里第k个插入的数下标idx是k
    else cin >> k, del(k);
  }

  for (int i = ne[0]; i; i = ne[i]) cout << e[i] << ' ';
  cout << endl;
  return 0;
}