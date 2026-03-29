#include <iostream>
using namespace std;
const int N = 1e5 + 10; // N是所有字符串的总长度上限，决定了Trie的最大节点数
int son[N][26], cnt[N], idx; // idx是节点计数器；每条边表示一个字符，每个节点是一个前缀
int n;

// trie[a][b]：a表示节点编号（和最多有多少个节点有关），b表示分叉
//        0
//    a/ b| \c  ..
//    a   b   c  ..
// ..  d/e|\f  |\ ..
//    bd be bf
void insert(string &str) {
  int p = 0; // trie树的遍历指针，从根节点0开始
  for (int i = 0; i < str.size(); i ++ ) {
    int t = str[i] - 'a';
    if (!son[p][t]) son[p][t] = ++ idx; // 每个idx都对应一个独立前缀；这里不能是idx++，否则son[p][t]不能作为后续判定条件
    p = son[p][t];
  }
  cnt[p] ++ ; // cnt[i]是从Trie的根节点0走到i这个节点位置所对应的单词个数
}

int query(string &str) {
  int p = 0;
  for (int i = 0; i < str.size(); i ++ ) {
    int t = str[i] - 'a';
    if (!son[p][t]) return 0;
    p = son[p][t];
  }
  return cnt[p];
}

int main() {
  cin >> n; // 10^6量级往上用ios::sync_with_stdio(false), cin.tie(0)来加速
  while (n -- ) {
    string op, str;
    cin >> op >> str; // 也可以用op[2]，scanf("%s")来过滤掉多余空格和回车字符
    if (op == "I") insert(str);
    else cout << query(str) << endl;
  }
  return 0;
}