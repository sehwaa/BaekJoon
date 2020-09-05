#include <iostream>

using namespace std;

int main() {
  int A; string B;
  cin >> A >> B;

  for(int i = B.length() - 1; i >= 0; i--) {
    int su = B[i] - '0';
    cout << A * su << endl;
  }

  cout << A * stoi(B);
  return 0;
}