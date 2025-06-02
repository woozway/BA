#include <iostream>
using namespace std;
const int N = 1e5 + 10, M = 31 * N;
int son[M][2], idx;

void insert(int x) {
  int p = 0;
  for (int i = 30; i >= 0; i -- ) {
    int t = x >> i & 1;
    if (!son[p][t]) son[p][t] = ++ idx;
    p = son[p][t];
  }
}

int query(int x) {
  int p = 0, res = 0;
  for (int i = 30; i >= 0; i -- ) {
    int t = x >> i & 1;
    if (son[p][!t]) res += 1 << i, p = son[p][!t]; // 尝试找能使异或后的数变大的，即异或后为1的
    else p = son[p][t]; // 没有找到，将就一下
  }
  return res;
}

int main() { // 可引申为trie存汉字等应用
  int n;
  cin >> n;

  int a, res = 0;
  for (int i = 0; i < n; i ++ ) {
    scanf("%d", &a); // 直接在线处理
    insert(a); // 这里为防止处理第一个元素插入式特判，改变顺序为先插入再查询，效果不变
    res = max(res, query(a));
  }

  cout << res << endl;
  return 0;
}