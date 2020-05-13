#include <cstdio>
#include<vector>

using namespace std;

const int MAX_N = 1000000;
vector<int> FIBONACCI_TABLE;


// *** 아래 8자리끼리만 계산하면 됨 -> 아래 8자리만 출력할것이기 때문에,
// *** 추가, 수정 등 멤버함수 안쓸거면 배열로 사용해도 무방함. 
vector<int> makeFibonacciTable(int n) {
	const int MOD = 100000000;

	vector<int> ret(n + 1);

	// fixed value
	ret[0] = 0;
	ret[1] = 1;

	for (int i = 3; i <= n; i++) {
		ret[i] = ret[i - 1] + ret[i - 2];

		// 8자리만 필요하기 때문에
		ret[i] %= MOD;
	}

	return ret;
}

// 배열 값 가져오기
int getFibo(int n) {
	
	int answer = FIBONACCI_TABLE[n];

	return answer;
}

int main() {

	// 8자리만으로 만들어진, 피보나치 배열 만들기
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
