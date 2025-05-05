#include <iostream>
using namespace std;
typedef unsigned long long ull; // ull 64位自动取模
const int N =  1e5 + 10, P = 131; // 或13331，经验值冲突概率小
ull h[N], p[N]; // h[k]是前缀哈希，即字符串s[1~k]的哈希值
char str[N];

ull get(int l, int r) { // 求子串s[l~r]的哈希值
  return h[r] - h[l-1]*p[r-l+1];
}

int main() {
  int n, m;
  cin >> n >> m >> str + 1;

  p[0] = 1;
  for (int i = 1; i <= n; i++) {
    p[i] = p[i-1] * P;
    h[i] = h[i-1]*P + str[i]; // 注意这里不用str[i]-'a'，否则当比较a和aaa时，两个哈希值都是0（c++中'\0'的ASCII才是0）
  }

  int l1, r1, l2, r2;
  while (m--) {
    scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
    if (get(l1, r1) == get(l2, r2)) puts("Yes");
    else puts("No");
  }

  return 0;
}