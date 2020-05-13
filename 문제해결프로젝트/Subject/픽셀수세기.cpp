#include<stdio.h>
#include<iostream>
using namespace std;

bool isInside(long long x, long long y, long long R)
{
	// ���� ������ : x^2+y^2=R^2 ==> x^2+y^2<R^2��� ���ο� �ִ�.
	// ������ �Ű�Ƚᵵ �ǳ�?? --> sqd <R*R �̹Ƿ�, 1��и鿡�� �ȼ��� ���ʾƷ� ���� �������� �����ϴµ�, �� ���� ��ġ�°� ��ħ
	long long sqd = x*x + y*y;
	if (sqd < R*R)
		return true;
	return false;
}

// ������ ���� Integer�� �����ϱ� ������ long long ������ Ÿ�� ���
// 1��и鸸 ����ϸ� *4�ϸ� ��ü �ȼ��� ���� �� ����!
void testcase(int caseIndex){
	long long R;
	scanf("%lld", &R);

	long long sum = 0; // 1��и鿡 �����ϴ� �ȼ� ��
	long long y = R;
	for (long x = 0; x <= R; x++){
		long long height = 0;
		for (; y >= 0; y--){
			if (isInside(x, y, R)) {

				// 0 ~ R���� x �̵��ϸ鼭 y�� R ~ 0 �����������鼭 ���� �ȼ����� Ȯ��
				height = (y + 1); // ���� y�ȼ��� �� ���ο��ִٸ�? -> �� �Ʒ��� �ִ� �ȼ��� ��� �ȿ� �ִ�!
				break;
			}
		}
		sum += height;
	}
	printf("#%d\n", caseIndex);
	printf("%lld\n", sum * 4); // ��� ��и� ���
}

int main(){
	int caseSize;

	scanf("%d", &caseSize);
	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1){
		testcase(caseIndex);
	}

	return 0;
}