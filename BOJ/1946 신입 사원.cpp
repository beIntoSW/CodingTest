#include<cstdio>
#include<vector>

using namespace std;

// �ִ� ��� + 1
const int max_value = 100000 + 1;

// �ִ� ���Ի�� ���� ���ϴ� �Լ�
/*
	table�� index : ��������
	table�� ��	  : ��������

	���������� �������� �����ϱ� ����, index�� ����� 
*/
int getMaxEmp_faster(vector<int> table)
{
	/*
		emp_num : �ִ� ���Ի�� ��
		rank	: ���� ���� ������ ������ ���� ex) 1 ~ i-1 ��°���� �� ���� ���� ����
	*/
	int emp_num = table.size() - 1;
	int rank = max_value;

	// ���� ���� ������ ������ rank������ ���ؼ�, ����ġ�� 
	for (int i = 1; i < table.size(); i++) {

		if (rank > table[i]) {
			rank = table[i];
		}
		else {
			emp_num--;
		}
	}

	return emp_num;
}


// �ִ� ���Ի�� ���� ���ϴ� �Լ�
int getMaxEmp(vector<int> table) 
{
	/*
		emp_num : �ִ� ���Ի�� ��
	*/
	int emp_num = table.size() - 1;

	// 2�� �ݺ����� �̿��ؼ�, ��
	for (int i = 2; i < table.size(); i++) {
		if (table[i] == 1) {
			continue;
		}
		else {
			for (int j = i-1; j >= 1; j--) {
				if (table[i] >= table[j]) {
					emp_num--;
					break;
				}
			}
		}
	}

	return emp_num;
}

void process(int testIndex) 
{
	int person;

	scanf("%d", &person);

	vector<int> table = vector<int>(person + 1);

	for (int i = 0; i < person; i++) {
		int score_1, score_2;
		scanf("%d %d", &score_1, &score_2);

		table[score_1] = score_2;
	}
	
	printf("%d\n", getMaxEmp_faster(table));
	// printf("%d\n", getMaxEmp(table));

}


int main() {
	int testcase;

	scanf("%d", &testcase);

	for (int testIndex = 0; testIndex < testcase; testIndex++) {
		process(testIndex);
	}


	return 0;
}