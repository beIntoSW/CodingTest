#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX_SERIAL_NUMBER = 100000;

// �󵵼� ä���
void fillFrequencyTable(const vector<int> & data, int n, vector<int> &table) {
	table.clear();

	table.resize(MAX_SERIAL_NUMBER+1,0); // 0 ~100000 ���� ǥ���Ϸ��� + 1����

	for (int i = 0; i < n; i++) {
		int serial = data[i];
		table[serial] += 1;
	}
}

// �ߺ� ���ִ� �Լ�
vector<int> getUniqueElements(const vector<int>& data, int n) {
	vector<int> ret;
	vector<int> table;

	fillFrequencyTable(data, n, table);

	// serial number : 1 ~ 100000
	for (int number = 1; number <= MAX_SERIAL_NUMBER; number++)
	{
		// �ߺ� X && ������������ ����
		if (table[number] == 1)
			ret.push_back(number);

	}
	return ret;
}



// �迭�� ���� : ���� �߰�, ����, ũ�� ���� --> ���� �ɸ� && ����
//	-> vector �����̳� ���!

/*	vector �����̳� : �ڵ����� �޸𸮰� �Ҵ�Ǵ� �迭
	vector<int> v(5) : 0���� �ʱ�ȭ�� 5���� ���Ҹ� ���� �迭 ���� // 0���� �ʱ�ȭ
	vector<int> v(5,2) : 2�� �ʱ�ȭ�� 5���� ���Ҹ� ���� �迭 ���� // Ư�� ������ �ʱ�ȭ
	
	����Լ� : https://blockdmask.tistory.com/70
	v.clear() : ��� ���� ����, �޸𸮴� �״��
	v.resize(n,3) : ũ�⸦ n���� �����ϰ� 3���� �ʱ�ȭ
*/
int main() {
	int n;
	scanf("%d", &n);

	vector<int> data = vector<int>(n);

	// �迭�� ���� ������� �Է� ����
	for (int i = 0; i < n; ++i) {
		scanf("%d", &data[i]);
	}

	const vector<int> answer = getUniqueElements(data, n);

	for (int i = 0; i < answer.size(); ++i) {
		if (i > 0)
			printf(" ");
		printf("%d", answer[i]);
	}

	return 0;
}