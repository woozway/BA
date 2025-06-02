#include <iostream>
using namespace std;

// 证明：a1^a2^...^an = x，找x最高位1所在的位置k，然后在a1~an中找ai以满足其第k位是1，
// 然后得ai'=ai^x（ai'一定小于ai），这样后手在进行异或时一定为0，先手必胜（全0局面一定被后手拿到）
//   1. 0 ^ 0 ^ ... ^ 0 = 0
//   2. a1 ^ a2 ^ ... ^ an = x (x!=0)
//   3. a1 ^ a2 ^ ... ^ ai' ^ an = x^x = 0 (ai'=ai^x, x=ai-ai^x)
int main() {
  int n;
  scanf("%d", &n);

  int res = 0;
  while (n -- ) {
    int x;
    scanf("%d", &x);
    res ^= x;
  }

  if (res) puts("Yes");
  else puts("No");
  return 0;
}