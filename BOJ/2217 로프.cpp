#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX_VALUE = 10000;
const int MAX_ROPE = 100000;

vector<bool> CHECKED;

vector<int> getValueVector(vector<int> table, int num) {
	vector<int> max_table;
	for (int i = 0; i < num; i++) {
		if (CHECKED[table[i]])
		{
			continue;
		}
		max_table.push_back((num - i)*table[i]);
		CHECKED[table[i]] = true;
	}

	return max_table;
}


int getMaxWeight(vector<int> table, int num) {

	sort(table.begin(), table.end()); // less<int>() : default
	//sort


	// bool üũ
	vector<int> max_table = getValueVector(table, num);
	int max = 0;

	for (int i = 0; i < max_table.size(); i++) {
		if (max < max_table[i])
			max = max_table[i];
	}
	

	return max;
}


int main() {

	int num;

	scanf("%d", &num);

	vector<int> table = vector<int>(num);
	CHECKED = vector<bool>(MAX_VALUE+1, false);

	for (int i = 0; i < num; i++) {
		scanf("%d", &table[i]);
	}

	int max = getMaxWeight(table, num);

	printf("%d\n", max);


	return 0;
}