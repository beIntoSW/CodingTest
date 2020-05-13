#include<stdio.h>
#include<iostream>

using namespace std;

// ������������ üũ �� true // false ����
bool isOrdered(int stu_height[], int num_stu){
	int pre_height = -1;

	for (int i = 0; i < num_stu; i++){
	
		// ���� �л��� Ű���� Ű�� ������ false ����
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