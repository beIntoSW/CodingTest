#include<stdio.h>
#include<iostream>

using namespace std;

// 오름차순인지 체크 후 true // false 리턴
bool isOrdered(int stu_height[], int num_stu){
	int pre_height = -1;

	for (int i = 0; i < num_stu; i++){
	
		// 이전 학생의 키보다 키가 작으면 false 리턴
		if (pre_height > stu_height[i])
			return false;

		pre_height = stu_height[i];
	}

	return true;
}

int main()
{
	int num_stu;
	int* stu_height;
	////////////////////////////////////////////////
	///////////// init ////////////////////
	scanf("%d", &num_stu);
	stu_height = new int[num_stu];
	for (int i = 0; i < num_stu; i++){
		scanf("%d", &stu_height[i]);
	}

	/////////////////////////////////////////////////////////

	if (isOrdered(stu_height, num_stu))
		printf("YES\n");
	else
		printf("NO\n");

	delete[] stu_height;
	return 0;

}