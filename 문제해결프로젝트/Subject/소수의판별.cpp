#include<stdio.h>
#include<iostream>
using namespace std;


bool isPrime(int n){
	if (n <= 1){
		return false;
	}

	// 소수인지 판별하는 변수
	bool result = true;

	// 소수는 1과 자기 자신만 약수여야하기 때문에 2부터 시작해서 반복문 실행
	// ==> 약수는 짝이 맞아야하기 때문에, n -> sqrt(n)까지만 해주면 됨
		// ==> O(n) ->O(sqrt(n))이 되어 시간복잡도가 줄어들음.
			// => 반복문의 조건에 정수로 만들어주기 위해서
			//		-> i < sqrt(n) ==> i*i < n 으로 바꿔줌
	for (int i = 2; i*i < n; i++){

		// 자기 자신과, 1 이외에 나누어떨어지는값이 있다면? -> 가지치기 + 소수X
		
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