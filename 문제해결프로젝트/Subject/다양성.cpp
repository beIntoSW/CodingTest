#include<stdio.h>
#include<iostream>

using namespace std;

// 유니크한 화보 수 구하는 함수
int getElementTypeCount(int pic_data[], int num){
	int countType = num, pre_pic_data = pic_data[0];


	for (int i = 1; i < num; i++){
	
		// 이전 화보 번호와 같다면 총 개수 감소
		if (pre_pic_data == pic_data[i])
			countType--;

		// 이전 화보 번호와 다르다면 변수 교체
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