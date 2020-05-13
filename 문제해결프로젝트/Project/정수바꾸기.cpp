/*

	172570 이영수 프로젝트2

*/
#include<iostream>
#include<vector>
#include<time.h>

using namespace std;

/*
	g_start		: A
	g_end		: B
	ischecked	: 계산 했었는지 확인하는 배열

*/
static int g_start, g_end;
vector<bool> ischecked;

// 배열의 사이즈 : B-A로 잡아서, 메모리 에러가 일어나지 않게 함
// data 변수에 따른, 배열의 알맞은 인덱스를 리턴함
int getIndex(const long long data) {
	return data - g_start;
}


/*
	data	: 현재 값
	op_cnt	: 현재 연산 횟수
*/
void getOPCnt(const long long data, int op_cnt) {

	// data가 찾는 값보다 크면 리턴
	if (data > g_end) {
		return;
	}

	// 현재 값에 대한 인덱스 가져오기
	int index = getIndex(data);

	// 처음 나왔을 때,
	if (!ischecked[index]) {
		ischecked[index] = true;
		
		// 현재 값이 찾는 값이라면 출력 후 종료
		if (data == g_end) {
			printf("%d\n", op_cnt);
			return;
		}

		// 최소 연산 횟수를 찾기 위해, 값이 커지는 방향으로 먼저 재귀 실행
		getOPCnt(data * 10 + 1, op_cnt + 1);
		getOPCnt(data * 2, op_cnt + 1);
	}

	//// 이미 나왔다면, 리턴
	else {
		return;
	}

}

int main() {

	scanf("%d %d", &g_start, &g_end);

	// 시간 체크 시작
	clock_t start = clock();

	// 계산 했었는지 확인하는 배열 생성
	// 인덱스 0 : 시작 값, 마지막 인덱스 : 찾는 값
	ischecked = vector<bool>(g_end - g_start + 1, false);

	getOPCnt(g_start, 1);

	// 찾지 못했다면 -1 출력
	if (!ischecked[getIndex(g_end)])
		printf("-1\n");

	// 시간 체크 끝
	clock_t end = clock();
	printf("Time : %lf\n", (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}