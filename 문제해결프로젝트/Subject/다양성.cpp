#include<stdio.h>
#include<iostream>

using namespace std;

// ����ũ�� ȭ�� �� ���ϴ� �Լ�
int getElementTypeCount(int pic_data[], int num){
	int countType = num, pre_pic_data = pic_data[0];


	for (int i = 1; i < num; i++){
	
		// ���� ȭ�� ��ȣ�� ���ٸ� �� ���� ����
		if (pre_pic_data == pic_data[i])
			countType--;

		// ���� ȭ�� ��ȣ�� �ٸ��ٸ� ���� ��ü
		else
			pre_pic_data = pic_data[i];
	}

	return countType;
}


int main(){
	int num;
	int* pic_data;

	scanf("%d", &num);

	pic_data = new int[num];

	for(int i = 0; i < num; i++){
		scanf("%d", &pic_data[i]);
	}

	int answer = getElementTypeCount(pic_data, num);

	printf("%d\n", answer);

	delete[] pic_data;

	return 0;
}