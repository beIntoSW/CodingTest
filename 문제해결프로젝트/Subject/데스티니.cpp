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

	// 거리의 제곱 return
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

	// 모두 한번씩 거리구하기 위한 이중 포문
	for (int i = 0; i < n; i++){
		for (int j = 0; j < i; j++){
			int sqd = points[i].getSquaredDistanceTo(points[j]);

			// 최소의 거리와 최소 거리인 쌍의 개수를 구해야 함.
			// 최소일 때, 개수 1로 초기화
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