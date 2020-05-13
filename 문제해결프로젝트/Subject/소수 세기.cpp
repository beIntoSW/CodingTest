#include<cstdio>
#include<vector>

using namespace std;

class Sieve {
public:
	/*
		maximumValue	:	�����佺�׳׽��� ü���� �ٷ� ���� ū ������ ��
		isPrime			:	�� ���ں� �Ҽ� ����
	*/
	int maximumValue;
	vector<bool> isPrime;


	// ������ & �ʱ�ȭ
	Sieve(int maximumValue) {
		// false�� �ʱ�ȭ & �� �ε����� ���ڸ� �ǹ��ϱ� ������, 
		// maximumValue + 1�� ũ�⸦ ���� ���� ����
		this->isPrime.assign(maximumValue + 1, true);

		this->maximumValue = maximumValue;

		// �Ҽ� ������ ä��� �Լ�
		this->fillSieve();
	}


	/*
		const
		- ��ü ���� ���� ���� �Ұ�
		- const �Լ��� ȣ�� ����

		�Ҽ� ���� ����ϴ� �Լ�
	*/
	bool isPrimeNumber(int num) const {
		return this->isPrime[num];
	}

	// �Ҽ� ������ ä��� �Լ�
	void fillSieve() {

		// 0�� 1�� �Ҽ��� �ƴϱ� ������ ó���� ó������
		this->isPrime[0] = this->isPrime[1] = false;

		// 2���� �ִ밪 ���� �Ҽ� ������ ä��
		for (int num = 2; num <= this->maximumValue; num++) {

			// �Ҽ��� �ƴ� ���
			if (isPrime[num] == false) {
				continue;
			}

			/*
				�Ҽ��� ���,
				�Ҽ��� �������� üũ �� -> �Ҽ��� ��� üũ ==> �Ҽ��� �ƴ϶�� ����
					=> mul���� ������ �� Ȯ������ ������?
						-> 2 ~ (mul-1) ���� �Ҽ� üũ ��, ���� ������� �Ҽ��� �ƴ϶�� �߱� ������
			*/
			for (long long mul = (long long)num * num; mul <= maximumValue; mul += num) {
				// *** mul�� ����, mul�� ������ '������ ���μ� num'�� ���� ***
				int index = (int)mul;
				this->isPrime[index] = false;
			}
		}
	}
};

// ��� �Ҽ� �������� �Լ�
vector<int> getAllPrimeNumbers(int from, int to, const Sieve& sieve) {
	vector<int> primes;

	for (int num = from; num <= to; num++) {

		// num�� �Ҽ����? ���Ϳ� �߰�
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

	// allPrimeNumbers : ��� �Ҽ��� ���ִ� ����
	printf("%d\n", (int)allPrimeNumbers.size());
}

int main() {
	/*
		MAX_VALUE	: L�� R�� ���� �� �ִ� �ִ� ��
		caseSize	: �׽�Ʈ ���̽� ��
	*/
	const int MAX_VALUE = 1000000;
	Sieve sieve = Sieve(MAX_VALUE);

	int caseSize;
	scanf("%d", &caseSize);
	
	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex++) {
		process(caseIndex, sieve);
	}
}