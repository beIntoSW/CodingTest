/*

	172570 �̿��� ������Ʈ2

*/
#include<iostream>
#include<vector>
#include<time.h>

using namespace std;

/*
	g_start		: A
	g_end		: B
	ischecked	: ��� �߾����� Ȯ���ϴ� �迭

*/
static int g_start, g_end;
vector<bool> ischecked;

// �迭�� ������ : B-A�� ��Ƽ�, �޸� ������ �Ͼ�� �ʰ� ��
// data ������ ����, �迭�� �˸��� �ε����� ������
int getIndex(const long long data) {
	return data - g_start;
}


/*
	data	: ���� ��
	op_cnt	: ���� ���� Ƚ��
*/
void getOPCnt(const long long data, int op_cnt) {

	// data�� ã�� ������ ũ�� ����
	if (data > g_end) {
		return;
	}

	// ���� ���� ���� �ε��� ��������
	int index = getIndex(data);

	// ó�� ������ ��,
	if (!ischecked[index]) {
		ischecked[index] = true;
		
		// ���� ���� ã�� ���̶�� ��� �� ����
		if (data == g_end) {
			printf("%d\n", op_cnt);
			return;
		}

		// �ּ� ���� Ƚ���� ã�� ����, ���� Ŀ���� �������� ���� ��� ����
		getOPCnt(data * 10 + 1, op_cnt + 1);
		getOPCnt(data * 2, op_cnt + 1);
	}

	//// �̹� ���Դٸ�, ����
	else {
		return;
	}

}

int main() {

	scanf("%d %d", &g_start, &g_end);

	// �ð� üũ ����
	clock_t start = clock();

	// ��� �߾����� Ȯ���ϴ� �迭 ����
	// �ε��� 0 : ���� ��, ������ �ε��� : ã�� ��
	ischecked = vector<bool>(g_end - g_start + 1, false);

	getOPCnt(g_start, 1);

	// ã�� ���ߴٸ� -1 ���
	if (!ischecked[getIndex(g_end)])
		printf("-1\n");

	// �ð� üũ ��
	clock_t end = clock();
	printf("Time : %lf\n", (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}