#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

/*
	* 음수 여부 판단하는 함수

	* @param
	* op		:	연산자를 저장한 벡터
	* index		:	인덱스
*/
bool isMinus(vector<char> op, int index) {
	if (op[index] == '-')
		return true;
	else
		return false;
}

/*
	* 전체 식의 최소 값을 구하기 위한 함수

	* @param
	* table		:	i번째 인덱스 ~ 끝까지 최소값을 저장한 벡터
	* op		:	연산자를 저장한 벡터
*/
int getMinValue(vector<int> table, vector<char> op) {
	int min = 0;
	
	for (int i = 1; i < op.size(); i++) {
		if (isMinus(op, i)) {
			min += table[i];
		}
	}

	min *= -1;

	if (!isMinus(op, 0)) {
		min += table[0];
	}

	return min;

}


/*
	* i번째 인덱스 ~ 끝까지 최소값을 저장하고, 그 중 최소값을 리턴하는 함수

	* @param
	* value		:	각 값을 저장한 벡터
	* op		:	연산자를 저장한 벡터
*/
int process(vector<int> value, vector<char> op) {
	
	/*
		end : '-'가 출력된 인덱스
		table : 최소값을 저장하기 위한 벡터
		add_value : i+1번째 인덱스 ~ end변수가 나오기 전까지 합한 값
	*/
	int end = value.size();
	vector<int> table = vector<int>(end); // 최소 값 저장, 0 ~ end
	int add_value = 0;

	for (int i = --end ; i >= 0; i--) {
		
		table[i] = add_value + value[i];

		if (isMinus(op, i)) {
			add_value = 0;
		}
		else {
			add_value = table[i];
		}
	}
	
	return getMinValue(table, op);
}



int main() {

	string input;
	cin >> input;
	vector<char> op;
	vector<int> value;
	string tmp = "";

	if (input[0] != '-')
		op.push_back('+');

	for (char a : input) {
		
		if (a >= '0' && a <= '9') {
			tmp.push_back(a);
		}
		else {
			op.push_back(a);
			value.push_back(stoi(tmp));
			tmp.clear();
		}
	}
	value.push_back(stoi(tmp));
	tmp.clear();


	int min = process(value, op);

	cout << min << endl;
	

	return 0;
}