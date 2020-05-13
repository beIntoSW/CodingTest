#include<cstdio>
#include<vector>

using namespace std;

class Sieve {
public:
	/*
		maximumValue	:	에라토스테네스의 체에서 다룰 가장 큰 범위의 값
		isPrime			:	각 숫자별 소수 유무
	*/
	int maximumValue;
	vector<bool> isPrime;


	// 생성자 & 초기화
	Sieve(int maximumValue) {
		// false로 초기화 & 각 인덱스가 숫자를 의미하기 때문에, 
		// maximumValue + 1의 크기를 가진 벡터 생성
		this->isPrime.assign(maximumValue + 1, true);

		this->maximumValue = maximumValue;

		// 소수 유무를 채우는 함수
		this->fillSieve();
	}


	/*
		const
		- 객체 내부 변수 변경 불가
		- const 함수만 호출 가능

		소수 여부 출력하는 함수
	*/
	bool isPrimeNumber(int num) const {
		return this->isPrime[num];
	}

	// 소수 유무를 채우는 함수
	void fillSieve() {

		// 0과 1은 소수가 아니기 때문에 처음에 처리해줌
		this->isPrime[0] = this->isPrime[1] = false;

		// 2부터 최대값 까지 소수 유무를 채움
		for (int num = 2; num <= this->maximumValue; num++) {

			// 소수가 아닐 경우
			if (isPrime[num] == false) {
				continue;
			}

			/*
				소수일 경우,
				소수의 제곱부터 체크 후 -> 소수의 배수 체크 ==> 소수가 아니라고 변경
					=> mul변수 이전은 왜 확인하지 않을까?
						-> 2 ~ (mul-1) 까지 소수 체크 후, 그의 배수들을 소수가 아니라고 했기 때문에
			*/
			for (long long mul = (long long)num * num; mul <= maximumValue; mul += num) {
				// *** mul에 대해, mul을 나누는 '최초의 소인수 num'이 등장 ***
				int index = (int)mul;
				this->isPrime[index] = false;
			}
		}
	}
};

// 모든 소수 가져오는 함수
vector<int> getAllPrimeNumbers(int from, int to, const Sieve& sieve) {
	vector<int> primes;

	for (int num = from; num <= to; num++) {

		// num이 소수라면? 벡터에 추가
		if (sieve.isPrimeNumber(num)) {
			primes.push_back(num);
		}
	}

	return primes;
}


void process(int caseIndex, const Sieve& sieve) {
	int L, R;
	scanf("%d %d", &L, &R);

	vector<int> allPrimeNumbers = getAllPrimeNumbers(L, R, sieve);

	printf("Case #%d:\n", caseIndex);

	// allPrimeNumbers : 모든 소수가 들어가있는 벡터
	printf("%d\n", (int)allPrimeNumbers.size());
}

int main() {
	/*
		MAX_VALUE	: L과 R이 받을 수 있는 최대 값
		caseSize	: 테스트 케이스 수
	*/
	const int MAX_VALUE = 1000000;
	Sieve sieve = Sieve(MAX_VALUE);

	int caseSize;
	scanf("%d", &caseSize);
	
	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex++) {
		process(caseIndex, sieve);
	}
}