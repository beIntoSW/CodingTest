#include <cstdio>
#include<vector>

using namespace std;

const int MAX_N = 1000000;
vector<int> FIBONACCI_TABLE;


// *** �Ʒ� 8�ڸ������� ����ϸ� �� -> �Ʒ� 8�ڸ��� ����Ұ��̱� ������,
// *** �߰�, ���� �� ����Լ� �Ⱦ��Ÿ� �迭�� ����ص� ������. 
vector<int> makeFibonacciTable(int n) {
	const int MOD = 100000000;

	vector<int> ret(n + 1);

	// fixed value
	ret[0] = 0;
	ret[1] = 1;

	for (int i = 3; i <= n; i++) {
		ret[i] = ret[i - 1] + ret[i - 2];

		// 8�ڸ��� �ʿ��ϱ� ������
		ret[i] %= MOD;
	}

	return ret;
}

// �迭 �� ��������
int getFibo(int n) {
	
	int answer = FIBONACCI_TABLE[n];

	return answer;
}

int main() {

	// 8�ڸ������� �������, �Ǻ���ġ �迭 �����
	FIBONACCI_TABLE = makeFibonacciTable(MAX_N);


	int case_size;
	scanf("%d", &case_size);

	for (int case_index = 1; case_index <= case_size; case_index++) {
		int n;
		scanf("%d", &n);

		int answer = getFibo(n);
		printf("%d\n", answer);

	}

	FIBONACCI_TABLE.clear();

	return 0;
}
