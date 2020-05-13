#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int get_area(int la, int ra, int ta, int ba, int lb, int rb, int tb, int bb) {

	int l, r, t, b;
	l = max(la, lb); // �������� �簢���� ���� ��ǥ�� <= ū��
	r = min(ra, rb); // �������� �簢���� ������ ��ǥ�� <= ������
	t = min(ta, tb); // �������� �簢���� ���� ��ǥ�� <= ������
	b = max(ba, bb); // �������� �簢���� �Ʒ��� ��ǥ�� <= ū��


	// 
	/*if (l <= r && b <= t)
		return ((r - l)*(t - b));
	return 0;*/
	
	// ������ �׻� ����� ���;� �ϱ� ������ ���밪�� ����
	return abs((r-l)*(t-b));
}

void test_case() {
	int ax, ay, bx, by;
	int px, py, qx, qy;

	scanf("%d %d %d %d", &ax, &ay, &bx, &by);
	scanf("%d %d %d %d", &px, &py, &qx, &qy);

	int la, ra, ba, ta; // ���簢�� a
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

	int lb, rb, bb, tb; // ���簢�� b
	lb = min(px, qx);
	rb = max(px, qx);
	tb = max(py, qy);
	bb = min(py, qy);

	int answer = get_area(la, ra, ta, ba, lb, rb, tb, bb);

	printf("%d\n", answer);
}

int main() {
	int t; // test case ��
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		test_case();
	}

	return 0;
}