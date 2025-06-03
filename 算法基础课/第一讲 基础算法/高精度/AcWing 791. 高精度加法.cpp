#include <iostream>
#include <vector>
using namespace std;
const int base = 1e9; // 压9位

vector<int> add(vector<int> &A, vector<int> &B) { // C=A+B, A>=0, B>=0
  if (A.size() < B.size()) return add(B, A);

  vector<int> C;
  int t = 0;
  for (int i = 0; i < A.size(); i ++ ) {
    t += A[i]; // 进位
    if (i < B.size()) t += B[i];
    // C.push_back(t % 10);
    // t /= 10;
    C.push_back(t % base); // 压位优化
    t /= base;
  }
  if (t) C.push_back(t);

  return C;
}

int main() {
  string a, b;
  cin >> a >> b;

  vector<int> A, B; // 由低到高倒着存，方便加减运算
  // for (int i = a.size() - 1; i >= 0; i -- ) A.push_back(a[i] - '0');
  // for (int i = b.size() - 1; i >= 0; i -- ) B.push_back(b[i] - '0');
  for (int i = a.size() - 1, s = 0, j = 0, t = 1; ~i; i -- ) {
    // A.push_back(a[i] - '0');
    s += (a[i] - '0') * t;
    j ++, t *= 10;
    if (j == 9 || i == 0) {
      A.push_back(s);
      s = j = 0;
      t = 1;
    }
  }
  for (int i = b.size() - 1, s = 0, j = 0, t = 1; ~i; i -- ) {
    // B.push_back(b[i] - '0');
    s += (b[i] - '0') * t;
    j ++, t *= 10;
    if (j == 9 || i == 0) {
      B.push_back(s);
      s = j = 0;
      t = 1;
    }
  }

  auto C = add(A, B);

  // for (int i = C.size() - 1; i >= 0; i -- ) printf("%d", C[i]);
  cout << C.back(); // 第一个数不需要最高位补零
  for (int i = C.size() - 2; ~i; i -- ) printf("%09d", C[i]);
  cout << endl;

  return 0;
}