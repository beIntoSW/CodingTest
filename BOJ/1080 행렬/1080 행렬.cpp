#include<cstdio>

const int MAX = 50;
int A[MAX][MAX], B[MAX][MAX]; // 미리 최대로 생성해야 빠른 것 같음. vector를 이용하면 편하긴하나, 속도가 조금 느린 것 같음.
int n, m;

// 행렬을 변환하는 함수 ( 모든 원소를 뒤집음 )
void transfromMatrix(int r, int c) {
	for (int i = r; i <= r + 2; i++) {
		for (int j = c; j <= c + 2; j++) {
			A[i][j] = 1 - A[i][j];
		}
	}
}

int process() {
	int res = 0;

	// 왼쪽 모서리를 기준으로 함
	//  (0,0)은 한 번의 뒤집음으로 판단함. (0,0) -> (0, n-1-2)까지 고정시키고
	//									  (1,0) -> (1, n-1-2)까지 고정 반복
	// 왼쪽 모서리는 변환 후 고정, 나머지는 이후의 행렬변환에 의해 값이 변함
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 2; j++) {
			if (A[i][j] != B[i][j]) {
				transfromMatrix(i, j);
				res++;
			}
		}
	}

	// 모두 돌았을 때, 다르다면?
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (A[i][j] != B[i][j])
				return -1;
		}
	}

	return res;
}

int main() {

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		
		for (int j = 0; j < m; j++) {
			scanf("%1d", &A[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &B[i][j]);
		}
	}


	printf("%d\n", process());

	return 0;
}
