#include<cstdio>
#include<vector>
#include<string>
using namespace std;

// 런타임 에러(시간초과)가 발생함// 벡터 생성으로 인한 시간 초과인 것 같음

const int SIZE = 3;
int n, m;

// true : 다름, false : 같음
vector<vector<int>> vec, vec2;

void transfromMatrix(int row, int col) {

	for (int r = row - 1; r <= row + 1; r++) {
		for (int c = col - 1; c <= col + 1; c++) {

			vec[r][c] = 1 - vec[r][c];
		}
	}
}

int process() {
	int res = 0;

	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < m - 1; j++) {
			if (vec[i - 1][j - 1] != vec2[i - 1][j - 1]) {
				transfromMatrix(i, j);
				res++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vec[i][j] != vec2[i][j])
				return -1;
		}
	}

	return res;

}

int main() {

	scanf("%d %d", &n, &m);
	if (n < SIZE && m < SIZE) {
		return -1;
	}

	vec = vector<vector<int>>(n);
	vec2 = vector<vector<int>>(n);
	for (int i = 0; i < n; i++) {
		vector<int> tmp = vector<int>(m);
		for (int j = 0; j < m; j++) {
			scanf("%1d", &tmp[j]);
		}
		vec[i] = tmp;
	}

	for (int i = 0; i < n; i++) {
		vector<int> tmp = vector<int>(m);
		for (int j = 0; j < m; j++) {
			scanf("%1d", &tmp[j]);
		}
		vec2[i] = tmp;
	}

	printf("%d\n", process());


	return 0;
}
