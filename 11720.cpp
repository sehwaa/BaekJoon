#include <iostream>

using namespace std;

int main() {
  int N;
  cin >> N;
  string su;
  cin >> su;

  int answer = 0;

  for (int i = 0; i < su.size(); i++) {
    answer += su[i] -'0';
  }

  cout << answer;
  return 0;
}