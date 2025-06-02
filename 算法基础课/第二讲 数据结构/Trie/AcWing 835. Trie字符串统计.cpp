#include <iostream>
using namespace std;
const int N = 1e5 + 10; // N是字符串总长度最大值
int son[N][26], cnt[N], idx; // trie根节点0

void insert(string &str) {
  int p = 0; // trie树的遍历指针
  for (int i = 0; i < str.size(); i ++ ) {
    int t = str[i] - 'a';
    if (!son[p][t]) son[p][t] = ++ idx; // 每个idx都对应一个独立前缀；这里不能是idx++，否则son[p][t]不能作为后续判定条件
    p = son[p][t];
  }
  cnt[p] ++ ; // cnt[i]是下标i在trie中对应单词的个数
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
  int n;
  cin >> n; // 10^6量级往上用ios::sync_with_stdio(false), cin.tie(0)来加速

  string op, str;
  while (n -- ) {
    cin >> op >> str; // 也可以用op[2]，scanf("%s")来过滤掉多余空格和回车字符
    if (op == "I") insert(str);
    else cout << query(str) << endl;
  }
  return 0;
}