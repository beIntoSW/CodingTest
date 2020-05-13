#include<stdio.h>
#include<iostream>

using namespace std;


int main(){
	int num_acorn = 0, tallest = -1, cur_month;
	int* acorn_height, *acorn_birth;

	// 도토리 수 입력 받기
	scanf("%d", &num_acorn);

	acorn_height = new int[num_acorn];
	acorn_birth = new int[num_acorn];

	for (int i = 0; i < num_acorn; i++){
		scanf("%d", &acorn_height[i]);
	}

	for (int i = 0; i < num_acorn; i++){
		scanf("%d", &acorn_birth[i]);
	}

	scanf("%d", &cur_month);

	/////////////////////////////////////////////////////////////
	//// 초기화 끝 ////
	

	// 키 큰 도토리부터 생일 같은지 찾고 종료
	for (int i = num_acorn - 1; i >= 0; i--)
	{
		if (acorn_birth[i] == cur_month)
		{
			tallest = acorn_height[i];
			break;
		}
	}

	printf("%d\n", tallest);

	// 동적할당 해제
	delete[] acorn_birth;
	delete[] acorn_height;

	return 0;
}