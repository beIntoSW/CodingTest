#include<stdio.h>
#include<iostream>
using namespace std;

// Selection Sort = O(n^2)
// Bubble Sort = O(n^2) 지만, **** 평균적으로 연산량이 적어 -> 실제로는 Selection Sort보다 빠름****

void bubbleSort(int data[], int n){

	
	for (int i = 0; i < n; i++){
		int negativecount = 0; // 오름차순을 부정하는 개수
		// 마지막에 접근할 필요 없기 때문에 n-1
		for (int j = 0; j < n-i-1; j++){
			// 오름차순 X -> 자리 교환
			if (data[j] > data[j + 1])
			{
				int tmp = data[j + 1];
				data[j + 1] = data[j];
				data[j] = tmp;
				negativecount++;
			}
		}

		// 이미 정렬되어 있을 경우를 위한 가지치기?
		if (negativecount == 0)
			break;
	}
}

int main(){
	int n;
	int* data;

	scanf("%d", &n);
	data = new int[n];

	for (int i = 0; i < n; i++){
		scanf("%d", &data[i]);
	}

	bubbleSort(data, n);

	for (int i = 0; i < n; i++){
		if (i > 0){
			printf(" ");
		}
		printf("%d", data[i]);
	}

	
	delete[] data;
	return n;
}