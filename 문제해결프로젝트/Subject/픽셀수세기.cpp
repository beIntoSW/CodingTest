#include<stdio.h>
#include<iostream>
using namespace std;

bool isInside(long long x, long long y, long long R)
{
	// 원의 방정식 : x^2+y^2=R^2 ==> x^2+y^2<R^2라면 내부에 있다.
	// 조건은 신경안써도 되나?? --> sqd <R*R 이므로, 1사분면에서 픽셀의 왼쪽아래 점을 기준으로 결정하는데, 딱 원에 걸치는건 안침
	long long sqd = x*x + y*y;
	if (sqd < R*R)
		return true;
	return false;
}

// 들어오는 값이 Integer가 부족하기 때문에 long long 데이터 타입 사용
// 1사분면만 계산하면 *4하면 전체 픽셀수 구할 수 있음!
void testcase(int caseIndex){
	long long R;
	scanf("%lld", &R);

	long long sum = 0; // 1사분면에 존재하는 픽셀 수
	long long y = R;
	for (long x = 0; x <= R; x++){
		long long height = 0;
		for (; y >= 0; y--){
			if (isInside(x, y, R)) {

				// 0 ~ R까지 x 이동하면서 y는 R ~ 0 까지내려오면서 내부 픽셀인지 확인
				height = (y + 1); // 높이 y픽셀이 원 내부에있다면? -> 그 아래에 있는 픽셀은 모두 안에 있다!
				break;
			}
		}
		sum += height;
	}
	printf("#%d\n", caseIndex);
	printf("%lld\n", sum * 4); // 모든 사분면 출력
}

int main(){
	int caseSize;

	scanf("%d", &caseSize);
	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1){
		testcase(caseIndex);
	}

	return 0;
}