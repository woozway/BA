#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> div(vector<int> &A, int b, int &r) { // 大整数A>=0，整数b>0
  vector<int> C;
  r = 0;
  for (int i = A.size() - 1; i >= 0; i -- ) { // 除法从高位开始
    r = r * 10 + A[i];
    C.push_back(r / b); // 由r<b和r>=b两种情况合并
    r %= b;
  }

  reverse(C.begin(), C.end()); // 为保持和加减乘一致，这里翻转一下
  while (C.size() > 1 && C.back() == 0) C.pop_back();

  return C;
}

int main() {
  string a;
  int b;
  cin >> a >> b;

  vector<int> A;
  for (int i = a.size() - 1; i >= 0; i -- ) A.push_back(a[i] - '0');

  int r;
  auto C = div(A, b, r);

  for (int i = C.size() - 1; i >= 0; i -- ) printf("%d", C[i]);
  cout << endl << r << endl;

  return 0;
}