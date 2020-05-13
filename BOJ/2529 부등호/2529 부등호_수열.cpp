#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<char> op;

bool isValid(vector<int> &vec) {
	
	for (int i = 0; i < op.size(); i++) {
		if (op[i] == '>' && vec[i] < vec[i + 1]) {
			return false;
		}
		else if (op[i] == '<' && vec[i] > vec[i + 1]) {
			return false;
		}
	}

	return true;
}

void display(vector<int> &vec) {
	for (int tmp : vec) {
		cout << tmp;
	}
	cout << endl;
}

int main() {
	int k;

	cin >> k;

	op = vector<char>(k);

	for (int i = 0; i < k; i++) {
		cin >> op[i];
	}

	vector<int> max_str = vector<int>(k + 1);
	vector<int> min_str = vector<int>(k + 1);
	for (int i = 0; i <= k; i++) {
		max_str[i] = 9 - i;
		min_str[i] = i;
	}

	while(true) {
		if (isValid(max_str)) {
			break;
		}
		prev_permutation(max_str.begin(), max_str.end());
	}

	while (true) {
		if (isValid(min_str)) {
			break;
		}
		next_permutation(min_str.begin(), min_str.end());
	}

	display(max_str);
	display(min_str);

	return 0;
}