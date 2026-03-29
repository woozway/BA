#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int e[N], ne[N], idx = 1; // 默认0是dummy_head，idx存储当前已经用到了哪个点
int n;

void add(int i, int x) { // 头插，在下标是i的节点的下个位置插入一个数x
  e[idx] = x, ne[idx] = ne[i], ne[i] = idx ++ ;
}

void del(int i) { // 单链表中是删除下标i节点的下一节点（因指针单向，需找到上一节点才能进行删除）
  ne[i] = ne[ne[i]];
}

int main() {
  cin >> n;
  while (n -- ) {
    string op;
    int k, x;

    cin >> op;
    if (op == "H") cin >> x, add(0, x);
    else if (op == "D") cin >> k, del(k);
    else cin >> k >> x, add(k, x); // 这里第k个插入的数下标idx是k
  }

  for (int i = ne[0]; i; i = ne[i]) cout << e[i] << ' ';
  cout << endl;
  return 0;
}