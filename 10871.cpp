#include <iostream>

using namespace std;

int main() {
	int N, X;
	cin >> N >> X;
	for (int i = 0; i < N; i++) {
		int A;
		cin >> A;
		if (X > A) cout << A << " ";
	}
	return 0;
}