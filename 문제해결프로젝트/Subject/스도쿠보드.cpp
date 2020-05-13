#include<cstdio>

/*
	수업 정리

	- "-"연산이 있으면, 나머지 연산 시 음수까지 나올 수 있음.
		=> "+p"를 해줌으로써 양수로 만들어 줌.

	약수의 특징 : N = a*b (a<=b)
		- a <= sqrt(N)
		- b >= sqrt(N)

			즉, 2 ~ sqrt(N) 까지만 확인하면 됨
			-> O(sqrt(N))


	에라토스테네스의 '체' 알고리즘 = (O(N*log(log(N))))
	O(N) < O(N*log(log(N))) < O(N*log(N))
	
		for문 2번 도는데 O(N^2)이 아닌 이유
		-> 1. k^2 ~ N까지만 확인(내부 for문)
		-> 2. k의 배수만 확인(내부 for문)
			- k+1 ~ 2k-1 확인X

*/



const int MAX_ROW = 9;
const int MAX_COL = 9;

class SudokuBoard {
public:

	// 행을 구하는 함수
	int getRowByIndex(int index) {

		// 0부터 시작해서 보면, 쉽게 규칙성을 얻을 수 있음
		// 0 ~ 8이 같은 행이기 때문에, 몫을 이용할 수 있음
		return (index-1) / MAX_COL + 1;
	}

	// 열을 구하는 함수
	int getColByIndex(int index) {

		// 0부터 시작해서 보면, 쉽게 규칙성을 얻을 수 있음
		// 0 ~ 8이 같은 열이기 때문에, 나머지를 이용할 수 있음
		return (index - 1) % MAX_ROW + 1;
	}

	// 인덱스를 이용해서 그룹번호를 구하는 함수
	int getGroupByIndex(int index) {
		int r = getRowByIndex(index);	// 행 가져오기
		int c = getColByIndex(index);	// 열 가져오기

		return getGroupByPosition(r, c);
	}

	int getGroupByPosition(int row, int column) {



		// (1,2,3),(4,5,6),(7,8,9)
		//	=> -1을 해주고, 3으로 나눔으로써, 몫을 이용해서 그룹을 나눔
		//	==> 각 행의, 가장 왼쪽 그룹의 번호를 알 수 있음
		int left = ((row - 1) / 3) * 3 + 1;

		// => -1을 해주고, 3으로 나눔으로써, 같은 그룹내 숫자들은 같은 몫을 가지고 있음
		// left변수를 통해 가장 왼쪽 그룹을 알 수 있고, offset을 통해 각 행의 몇번째 그룹인지 알 수 있음
		int offset = ((column - 1) / 3);

		return left + offset;
	}

	// 행과 열을 이용해서 값을 계산하는 함수
	int getIndexByPosition(int row, int column) {

		return (row - 1) * 9 + (column - 1) % 9 + 1;

	}

};

void process(int caseIndex) {
	int index;

	scanf("%d", &index);

	SudokuBoard board = SudokuBoard();

	int row = board.getRowByIndex(index);
	int col = board.getColByIndex(index);
	int group = board.getGroupByIndex(index);

	printf("Case #%d:\n", caseIndex);
	printf("%d %d %d\n", row, col, group);

}

int main() {
	int caseSize;
	scanf("%d", &caseSize);

	for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex) {
		process(caseIndex);
	}


	return 0;
}