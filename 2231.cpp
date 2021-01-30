#include <iostream>
#include <string>

using namespace std;

int main() {
	int N, constructor;
	cin >> N;
	int minM = 0;
	
	for (int i = 0; i <= N; i++) {
		string strI = to_string(i);
		int M = i;
		for (int j = 0; j < strI.size(); j++) {
			M += strI[j] - '0';
		}
		if (M == N) {
			minM = i;
			break;
		}
	}
	
	cout << minM;
	return 0;
}