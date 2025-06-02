#include <iostream>
using namespace std;
const int N = 1e5 + 10, M = 1e6 + 10;
char p[N], s[M];
int ne[N]; // ne[j]存字串p[i]和p[j+1]不匹配时下一个尝试的位置

int main() { // kmp算法可用于计算循环节
  int n, m;
  cin >> n >> p + 1 >> m >> s + 1; // p和s下标分别1~n,1~m

  for (int i = 2, j = 0; i <= n; i ++ ) { // i从第2个字符开始，建立p的自匹配数组ne
    while (j && p[i] != p[j + 1]) j = ne[j];
    if (p[i] == p[j + 1]) j ++ ;
    ne[i] = j;
  }

  for (int i = 1, j = 0; i <= m; i ++ ) { // 匹配p和s
    while (j && s[i] != p[j + 1]) j = ne[j];
    if (s[i] == p[j + 1]) j ++ ;
    if (j == n) { // 找到一个匹配，输出后把当前s[i]当作没匹配继续找下一个
      j = ne[j];
      printf("%d ", i - n);
    }
  }

  return 0;
}