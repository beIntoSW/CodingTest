#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

/*
	* ���� ���� �Ǵ��ϴ� �Լ�

	* @param
	* op		:	�����ڸ� ������ ����
	* index		:	�ε���
*/
bool isMinus(vector<char> op, int index) {
	if (op[index] == '-')
		return true;
	else
		return false;
}

/*
	* ��ü ���� �ּ� ���� ���ϱ� ���� �Լ�

	* @param
	* table		:	i��° �ε��� ~ ������ �ּҰ��� ������ ����
	* op		:	�����ڸ� ������ ����
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
	* i��° �ε��� ~ ������ �ּҰ��� �����ϰ�, �� �� �ּҰ��� �����ϴ� �Լ�

	* @param
	* value		:	�� ���� ������ ����
	* op		:	�����ڸ� ������ ����
*/
int process(vector<int> value, vector<char> op) {
	
	/*
		end : '-'�� ��µ� �ε���
		table : �ּҰ��� �����ϱ� ���� ����
		add_value : i+1��° �ε��� ~ end������ ������ ������ ���� ��
	*/
	int end = value.size();
	vector<int> table = vector<int>(end); // �ּ� �� ����, 0 ~ end
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