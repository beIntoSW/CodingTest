#include<stdio.h>
#include<iostream>
#include<cmath>
using namespace std;

class Point2D{
private:
	int x, y;

public:
	Point2D(int x = 0, int y = 0){
		this->x = x;
		this->y = y;
	}

	// �Ÿ��� ���� return
	int getSquaredDistanceTo(const Point2D &target) const{
		int dx = abs(this->x - target.x);
		int dy = abs(this->y - target.y);
		return dx*dx + dy*dy;
	}

	double getDistanceTo(const Point2D &target)const{
		double sqd = (double) this->getSquaredDistanceTo(target);
		return sqrt(sqd);
	}
};

int main(){
	int n;
	Point2D *points;

	scanf("%d", &n);
	points = new Point2D[n];

	for (int i = 0; i < n; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		
		points[i] = Point2D(x, y);
	}

	int min_sqd = INT_MAX;
	int min_cnt = 0;

	// ��� �ѹ��� �Ÿ����ϱ� ���� ���� ����
	for (int i = 0; i < n; i++){
		for (int j = 0; j < i; j++){
			int sqd = points[i].getSquaredDistanceTo(points[j]);

			// �ּ��� �Ÿ��� �ּ� �Ÿ��� ���� ������ ���ؾ� ��.
			// �ּ��� ��, ���� 1�� �ʱ�ȭ
			if (sqd < min_sqd){
				min_sqd = sqd;
				min_cnt = 1;
			}
			else if (sqd == min_sqd){
				min_cnt++;
			}
		}
	}

	double distance = sqrt(min_sqd);
	printf("%.1f\n", distance);
	printf("%d\n", min_cnt);

	delete[] points;
	return 0;



}