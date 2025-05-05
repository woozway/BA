#include <iostream>
#include <vector>
using namespace std;

bool lt(vector<int> &A, vector<int> &B) { // less than 判断A<B是否成立
  if (A.size() != B.size()) return A.size() < B.size();
  for (int i = A.size()-1; i >= 0; i--) // 从高位往低位推进
    if (A[i] != B[i]) return A[i] < B[i];
  return false;
}

vector<int> sub(vector<int> &A, vector<int> &B) { // A>=0, B>=0, A>=B
  vector<int> C;
  int t = 0; // 借位
  for (int i = 0; i < A.size(); i++) {
    t = A[i] - t;
    if (i < B.size()) t -= B[i];
    C.push_back((t + 10) % 10); // 合并处理t>0和<0的情况
    if (t < 0) t = 1;
    else t = 0;
  }
  while (C.size()>1 && C.back()==0) C.pop_back(); // 删除前导0
  return C;
}

int main() {
  string a, b;
  cin >> a >> b;

  vector<int> A, B;
  for (int i = a.size()-1; i >= 0; i--) A.push_back(a[i] - '0');
  for (int i = b.size()-1; i >= 0; i--) B.push_back(b[i] - '0');

  vector<int> C;
  if (lt(A, B)) cout << "-", C = sub(B, A);
  else C = sub(A, B);

  for (int i = C.size()-1; i >= 0; i--) printf("%d", C[i]);
  cout << endl;

  return 0;
}