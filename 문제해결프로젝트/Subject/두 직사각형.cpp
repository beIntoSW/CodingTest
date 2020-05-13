#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int get_area(int la, int ra, int ta, int ba, int lb, int rb, int tb, int bb) {

	int l, r, t, b;
	l = max(la, lb); // 겹쳐지는 사각형의 왼쪽 좌표값 <= 큰값
	r = min(ra, rb); // 겹쳐지는 사각형의 오른쪽 좌표값 <= 작은값
	t = min(ta, tb); // 겹쳐지는 사각형의 위쪽 좌표값 <= 작은값
	b = max(ba, bb); // 겹쳐지는 사각형의 아래쪽 좌표값 <= 큰값


	// 
	/*if (l <= r && b <= t)
		return ((r - l)*(t - b));
	return 0;*/
	
	// 면적이 항상 양수가 나와야 하기 때문에 절대값을 취함
	return abs((r-l)*(t-b));
}

void test_case() {
	int ax, ay, bx, by;
	int px, py, qx, qy;

	scanf("%d %d %d %d", &ax, &ay, &bx, &by);
	scanf("%d %d %d %d", &px, &py, &qx, &qy);

	int la, ra, ba, ta; // 직사각형 a
	/*
		l : left
		r : right
		t : top
		b : bottom
	*/

	la = min(ax, bx);
	ra = max(ax, bx);
	ta = max(ay, by);
	ba = min(ay, by);

	int lb, rb, bb, tb; // 직사각형 b
	lb = min(px, qx);
	rb = max(px, qx);
	tb = max(py, qy);
	bb = min(py, qy);

	int answer = get_area(la, ra, ta, ba, lb, rb, tb, bb);

	printf("%d\n", answer);
}

int main() {
	int t; // test case 수
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		test_case();
	}

	return 0;
}