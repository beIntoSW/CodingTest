#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

/*
	정리

	- 정렬이 안되있을 경우, 
		- 최대, 최소, 히스토그램, k번째 => O(N)
	- 되어있다면?
		- O(1), O(1), O(logN), O(1)

	binary search : 원하는 답을 빠르게 찾을 수 있음.(조건 : 정렬이 되어 있을 경우)
*/

vector<int> getPossibleTargets(int n, int m, int* cards, int* targets) {
	vector<int> possibleTargets;

	// sort(시작 위치, 끝 위치)
	// 오름차순으로 정렬
	sort(cards, cards + n);

	// 사용하는 카드로 3중 반복문 사용해도 되지만,
	// N : 1 ~ 1000 // M : 1 ~ 100 이기 때문에,
	// M + N의 2중 반복문을 이용한 듯 하다.
	for (int i = 0; i < m; i++) {
		int k = targets[i]; // 당첨 번호 값
		bool possible = false; // 존재 유무를 저장할 bool 변수
		
		// 사용할 카드를 도는 반복문
		for (int j = 0; j < n; ++j) {
			int x = cards[j];

			// 사용할 카드를 도는 반복문 + 중복이 될 수 있기 때문에, p <= j
			for (int p = 0; p <= j; p++) {
				int y = cards[p];
				
				int z = k - (x + y); 
				// 당첨 카드의 반복문 + 사용할 카드의 2중 반복문을 이용하기 위해, 
				// 사용하는 변수 

				// z를 이진탐색으로 찾는다!
				if (binary_search(cards, cards + n, z) == true) {
					possible = true;
					break;
				}
			}

			// 당첨 번호가 존재한다면, 다음 당첨번호로
			if (possible) {
				break;
			}
		}

		// 존재하면 추가
		if (possible) {
			possibleTargets.push_back(k);
		}
	}

	
	sort(possibleTargets.begin(), possibleTargets.end());
	return possibleTargets;
}

int main() {
	/*
		n		: 카드의 수
		m		: 당첨 번호의 수
		cards	: 카드 번호 배열
		targets	: 당첨 번호 배열
	*/
	int n, m;
	scanf("%d %d", &n, &m);

	int* cards = new int[n];
	int* targets = new int[m];

	for (int i = 0; i < n; i++) {
		scanf("%d", &cards[i]);
	}
	
	for (int i = 0; i < m; i++) {
		scanf("%d", &targets[i]);
	}

	// answers : 나올 수 있는 당첨 번호를 가진 벡터
	vector<int> answers = getPossibleTargets(n, m, cards, targets);

	if (answers.size() == 0) {
		printf("NO");
	}
	else {
		for (int i = 0; i < answers.size(); i++) {
			if (i > 0) {
				printf(" ");
			}

			printf("%d", answers[i]);
		}
	}

	delete[] cards;
	delete[] targets;

	return 0;
}