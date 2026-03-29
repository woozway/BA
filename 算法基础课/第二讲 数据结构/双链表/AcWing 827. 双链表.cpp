#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int e[N], l[N], r[N], idx;
int n;

void add(int i, int x) { // 在下标是i的节点的下个位置插入一个数x
  e[idx] = x, l[idx] = i, r[idx] = r[i], l[r[i]] = idx, r[i] = idx ++ ;
}

void del(int i) { // 双链表中删除的是下标i的节点，而非其下一个节点
  l[r[i]] = l[i], r[l[i]] = r[i];
}

int main() {
  r[0] = 1, l[1] = 0, idx = 2; // 初始化双链表头尾，默认0,1分别是头尾指针

  cin >> n;
  while (n -- ) {
    string op;
    int k, x;

    cin >> op;
    if (op == "L") cin >> x, add(0, x);
    else if (op == "R") cin >> x, add(l[1], x); // 转化很妙
    else if (op == "D") cin >> k, del(k + 1); // +1因为idx从2开始，这里第k个插入的数下标idx是k+1
    else if (op == "IL") cin >> k >> x, add(l[k + 1], x);
    else cin >> k >> x, add(k + 1, x);
  }

  for (int i = r[0]; i != 1; i = r[i]) cout << e[i] << ' '; // i!=1停止,因为idx从2开始
  cout << endl;
  return 0;
}