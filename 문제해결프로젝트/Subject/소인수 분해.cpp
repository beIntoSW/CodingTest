#include<cstdio>
#include<vector>

using namespace std;

vector<int> factorize(int n) {
	vector<int> factors;

	// 2���� ����
	// 2 ~ sqrt(N)������ Ȯ���ϸ� ��.
	// 'div <= sqrt(N)'	=>	'div*div <= n'���� ����
	//		=> integer�̱� ������, sqrt(N)�� �Ҽ��� ����
	for (int div = 2; div * div <= n; div++) {
		
		// ������ �������ٸ�? => factors���Ϳ� �߰�	=> n ������Ʈ
		while (n % div == 0) {
			factors.push_back(div);
			n /= div;
		}
	}

	// sqrt(N)���� Ȯ�� ��, �����ִ� ���ڰ� 1�� �ƴ� ���, factors���Ϳ� �߰�
	if (n > 1) {
		factors.push_back(n);
	}

	return factors;
}

void process(int caseIndex) {
	/*
		n		:	���μ� ������ ����
		factors	:	factor�� ����ִ� ����
	*/
	int n;
	scanf("%d", &n);

	vector<int> factors = factorize(n);

	printf("#%d:\n", caseIndex);
	
	// ���μ� ���� ���
	for (int i = 0; i < factors.size(); ++i) {
		if (i > 0) {
			printf(" ");
		}
		printf("%d", factors[i]);
	}

	printf("\n");
}

int main() {
	/*
		caseSize : Ƚ��
	*/
	int caseSize;

	scanf("%d", &caseSize);

	for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex) {
		process(caseIndex);
	}

	return 0;
}