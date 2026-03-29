#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL; // ULL 64位自动取模，M=2^64
const int N =  1e5 + 10, P = 131; // 或13331，经验值冲突概率小
ULL h[N], p[N]; // h[k]是前缀哈希，即字符串str[1~k]的哈希值；p[i]=P^i
int n, m;
char str[N];

ULL get(int l, int r) { // 求子串s[l~r]的哈希值
  return h[r] - h[l - 1] * p[r - l + 1];
}

// 取固定值P和M，把字符串看作P进制数，求出该P进制数对M的余作为其Hash值
// 例：S="abc", c="d", T="xy"，令a=1, b=2, ..., y=25, z=26
//  S表示为P进制数：1 2 3
//  H(S) = 1*P^2 + 2*P + 3
//  H(S+c) = 1*P^3 + 2*P^2 + 3*P + 4 = H(S)*P + 4

//  S+T表示为P进制数：1 2 3 24 25，即abcxy
//  H(S+T) = 1*P^4 + 2*P^3 + 3*P^2 + 24*P^1 + 25*P^0
//  S在P进制下左移length(T)位：1 2 3 0 0
//  二者相减就是T的P进制数：24 25
//  H(T) = H(S+T) - (1*P^2 + 2*P + 3) * P^2 = 24*P^1 + 25

// 上述操作可O(N)处理字符串所有前缀Hash值，在O(1)时间内查询其任意子串的Hash
int main() {
  cin >> n >> m >> str + 1;

  p[0] = 1;
  for (int i = 1; i <= n; i ++ ) {
    p[i] = p[i - 1] * P;
    h[i] = h[i - 1] * P + str[i]; // 这里不用str[i]-'a'，否则比较a和aaa时，两个哈希值都是0（即不能让某个字符映射为0，c++中'\0'的ASCII才是0）
  }

  while (m -- ) {
    int l1, r1, l2, r2;
    scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
    if (get(l1, r1) == get(l2, r2)) puts("Yes");
    else puts("No");
  }
  return 0;
}