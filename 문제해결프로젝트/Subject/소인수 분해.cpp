#include<cstdio>
#include<vector>

using namespace std;

vector<int> factorize(int n) {
	vector<int> factors;

	// 2부터 시작
	// 2 ~ sqrt(N)까지만 확인하면 됨.
	// 'div <= sqrt(N)'	=>	'div*div <= n'으로 변경
	//		=> integer이기 때문에, sqrt(N)은 소수가 나옴
	for (int div = 2; div * div <= n; div++) {
		
		// 나누어 떨어진다면? => factors벡터에 추가	=> n 업데이트
		while (n % div == 0) {
			factors.push_back(div);
			n /= div;
		}
	}

	// sqrt(N)까지 확인 후, 남아있는 숫자가 1이 아닐 경우, factors벡터에 추가
	if (n > 1) {
		factors.push_back(n);
	}

	return factors;
}

void process(int caseIndex) {
	/*
		n		:	소인수 분해할 숫자
		factors	:	factor가 들어있는 벡터
	*/
	int n;
	scanf("%d", &n);

	vector<int> factors = factorize(n);

	printf("#%d:\n", caseIndex);
	
	// 소인수 분해 출력
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
		caseSize : 횟수
	*/
	int caseSize;

	scanf("%d", &caseSize);

	for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex) {
		process(caseIndex);
	}

	return 0;
}