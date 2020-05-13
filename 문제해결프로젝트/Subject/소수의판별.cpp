#include<stdio.h>
#include<iostream>
using namespace std;


bool isPrime(int n){
	if (n <= 1){
		return false;
	}

	// �Ҽ����� �Ǻ��ϴ� ����
	bool result = true;

	// �Ҽ��� 1�� �ڱ� �ڽŸ� ��������ϱ� ������ 2���� �����ؼ� �ݺ��� ����
	// ==> ����� ¦�� �¾ƾ��ϱ� ������, n -> sqrt(n)������ ���ָ� ��
		// ==> O(n) ->O(sqrt(n))�� �Ǿ� �ð����⵵�� �پ����.
			// => �ݺ����� ���ǿ� ������ ������ֱ� ���ؼ�
			//		-> i < sqrt(n) ==> i*i < n ���� �ٲ���
	for (int i = 2; i*i < n; i++){

		// �ڱ� �ڽŰ�, 1 �̿ܿ� ����������°��� �ִٸ�? -> ����ġ�� + �Ҽ�X
		
		if (n%i == 0)
		{
			result = false;
			break;
		}
	}
	return result;
}

void testcase(int caseIndex){
	int n;
	scanf("%d", &n);

	bool result = isPrime(n);

	printf("Case #%d\n", caseIndex);
	if (result){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
}

int main(){
	int caseSize;
	scanf("%d", &caseSize);

	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1){
		testcase(caseIndex);
	}

	return 0;
}