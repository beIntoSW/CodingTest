#include<cstdio>

const int MAX_TABLE_LENGTH = 10000; // 0 ~ 9999 by counting

void fillFrequencyTable(int data[], int n, int table[]) {

	int frequent_number = 0;

	// �ʱ�ȭ
	for (int i = 0; i < MAX_TABLE_LENGTH; i++)
	{
		table[i] = 0;
	}

	// table �迭 ä���(�󸶳� �ߺ��Ǿ���)
	for (int i = 0; i < n; i++) {
		frequent_number = data[i]; // ��ȭ��ȣ ���ڸ� = frequent_number
		table[frequent_number] += 1; // table's index = ��ȭ��ȣ ���ڸ� // table�� �� = �ߺ��� ��
	}
}


int getFrequentNumber(int data[], int n) {
	int frequent_number = 0;

	int table[MAX_TABLE_LENGTH];

	fillFrequencyTable(data, n, table);
	

	for (int i = 0; i < MAX_TABLE_LENGTH; i++) {

		// Ƚ�� ���� ���, ���� ������ ���ڸ� ����ؾ��ϱ� ������ '='�� ������ ����.
		if (table[i] > table[frequent_number])
			frequent_number = i;

	}
	

	return frequent_number;
}

int main() {
	int n;

	scanf("%d", &n);
	int* data = new int[n];

	for (int i = 0; i < n; i++) {
		scanf("%d", &data[i]);
	}

	int answer = getFrequentNumber(data, n);

	printf("%04d", answer); // ������ 4�ڸ� ����� ���� %04 //// 4�ڸ��� ������ ����ϴµ�, �� �κ��� 0���� ä���.

	delete[] data;

	return 0;
}