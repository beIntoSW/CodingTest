#include<cstdio>

/*
	���� ����

	- "-"������ ������, ������ ���� �� �������� ���� �� ����.
		=> "+p"�� �������ν� ����� ����� ��.

	����� Ư¡ : N = a*b (a<=b)
		- a <= sqrt(N)
		- b >= sqrt(N)

			��, 2 ~ sqrt(N) ������ Ȯ���ϸ� ��
			-> O(sqrt(N))


	�����佺�׳׽��� 'ü' �˰��� = (O(N*log(log(N))))
	O(N) < O(N*log(log(N))) < O(N*log(N))
	
		for�� 2�� ���µ� O(N^2)�� �ƴ� ����
		-> 1. k^2 ~ N������ Ȯ��(���� for��)
		-> 2. k�� ����� Ȯ��(���� for��)
			- k+1 ~ 2k-1 Ȯ��X

*/



const int MAX_ROW = 9;
const int MAX_COL = 9;

class SudokuBoard {
public:

	// ���� ���ϴ� �Լ�
	int getRowByIndex(int index) {

		// 0���� �����ؼ� ����, ���� ��Ģ���� ���� �� ����
		// 0 ~ 8�� ���� ���̱� ������, ���� �̿��� �� ����
		return (index-1) / MAX_COL + 1;
	}

	// ���� ���ϴ� �Լ�
	int getColByIndex(int index) {

		// 0���� �����ؼ� ����, ���� ��Ģ���� ���� �� ����
		// 0 ~ 8�� ���� ���̱� ������, �������� �̿��� �� ����
		return (index - 1) % MAX_ROW + 1;
	}

	// �ε����� �̿��ؼ� �׷��ȣ�� ���ϴ� �Լ�
	int getGroupByIndex(int index) {
		int r = getRowByIndex(index);	// �� ��������
		int c = getColByIndex(index);	// �� ��������

		return getGroupByPosition(r, c);
	}

	int getGroupByPosition(int row, int column) {



		// (1,2,3),(4,5,6),(7,8,9)
		//	=> -1�� ���ְ�, 3���� �������ν�, ���� �̿��ؼ� �׷��� ����
		//	==> �� ����, ���� ���� �׷��� ��ȣ�� �� �� ����
		int left = ((row - 1) / 3) * 3 + 1;

		// => -1�� ���ְ�, 3���� �������ν�, ���� �׷쳻 ���ڵ��� ���� ���� ������ ����
		// left������ ���� ���� ���� �׷��� �� �� �ְ�, offset�� ���� �� ���� ���° �׷����� �� �� ����
		int offset = ((column - 1) / 3);

		return left + offset;
	}

	// ��� ���� �̿��ؼ� ���� ����ϴ� �Լ�
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