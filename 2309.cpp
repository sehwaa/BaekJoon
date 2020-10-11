#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define SHORT_NUMBER 9
#define FIND_SHORT_NUMBER 7
#define MAX_HEIGHT 100

int candidate[SHORT_NUMBER];
vector<int> shorts;
int sum = 0;

void findShort(int index) {
	sum += candidate[index];
	
	if (sum == MAX_HEIGHT && shorts.size() + 1 == FIND_SHORT_NUMBER) {
		shorts.push_back(candidate[index]);
		sort(shorts.begin(), shorts.end());
		for (int i = 0; i < FIND_SHORT_NUMBER; i++) {
			cout << shorts.at(i) << endl;
		}
		return;
	} else if (sum > MAX_HEIGHT || index == SHORT_NUMBER -1) {
		sum -= candidate[index];
		return;
	}
	
	shorts.push_back(candidate[index]);
	
	for (int i = index + 1; i < SHORT_NUMBER; i++) {
		findShort(i);
		if (sum == MAX_HEIGHT && shorts.size() == FIND_SHORT_NUMBER) return;
	}
	
	if (!shorts.empty()) {
		shorts.pop_back();
		sum -= candidate[index];
	}
	return;
}

int main() {
	
	for (int i = 0; i < SHORT_NUMBER; i++) {
		int height;
		cin >> height;
		candidate[i] = height;
	}
	
	for (int i = 0; i < SHORT_NUMBER; i++) {
		findShort(i);
		if (shorts.size() == FIND_SHORT_NUMBER) {
			break;
		} else {
			while(!shorts.empty()) {
				shorts.pop_back();
			}
		}
	}
	return 0;
}