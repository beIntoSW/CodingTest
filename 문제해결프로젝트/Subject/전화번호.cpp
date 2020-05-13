#include<cstdio>

const int MAX_TABLE_LENGTH = 10000; // 0 ~ 9999 by counting

void fillFrequencyTable(int data[], int n, int table[]) {

	int frequent_number = 0;

	// 초기화
	for (int i = 0; i < MAX_TABLE_LENGTH; i++)
	{
		table[i] = 0;
	}

	// table 배열 채우기(얼마나 중복되었나)
	for (int i = 0; i < n; i++) {
		frequent_number = data[i]; // 전화번호 뒷자리 = frequent_number
		table[frequent_number] += 1; // table's index = 전화번호 뒷자리 // table의 값 = 중복된 값
	}
}


int getFrequentNumber(int data[], int n) {
	int frequent_number = 0;

	int table[MAX_TABLE_LENGTH];

	fillFrequencyTable(data, n, table);
	

	for (int i = 0; i < MAX_TABLE_LENGTH; i++) {

		// 횟수 같을 경우, 먼저 나오는 숫자를 출력해야하기 때문에 '='을 붙이지 않음.
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

	printf("%04d", answer); // 무조건 4자리 출력을 위한 %04 //// 4자리를 무조건 출력하는데, 빈 부분을 0으로 채운다.

	delete[] data;

	return 0;
}