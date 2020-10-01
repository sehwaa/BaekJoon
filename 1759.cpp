#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 15

int L, C;
vector<char> alphabet;
bool visited[MAX][MAX];
vector<char> secret;

void recursiveSearch(int index) {
	secret.push_back(alphabet[index]);

	if (secret.size() == L) {
		int ja = 0; int mo = 0;
		for (int i = 0; i < secret.size(); i++) {
			if (secret[i] == 'a' || secret[i] == 'e' || secret[i] == 'i' || secret[i] == 'o' || secret[i] == 'u') mo++;
			else ja++;
		}

		if (ja >= 2 && mo >= 1) {
			for (int i = 0; i < secret.size(); i++) {
				cout << secret[i];
			}
			cout << endl;
		}
		return;
	}

	for (int j = index + 1; j < C; j++) {
		if (!visited[index][j]) {
			recursiveSearch(j);
		}
		secret.pop_back();
	}
}

int main() {
	cin >> L >> C;

	for (int i = 0; i < C; i++) {
		char a;
		cin >> a;
		alphabet.push_back(a);
	}

	sort(alphabet.begin(), alphabet.end());

	for (int i = 0; i < alphabet.size(); i++) {
		recursiveSearch(i);
		secret.pop_back();
	}
	return 0;
}