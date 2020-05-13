#include<stdio.h>
#include<iostream>
using namespace std;

// 연속적인 수열 = YES / 그렇지 않다면 = NO
// 여부를 표현! // 최대 - 최소 = 크기 - 1 임을 꺠달아야 함.
bool isConsecutive(int data[], int n){
	int max_data = data[0];
	int min_data = data[0];

	for (int i = 0; i < n; i++){

		// 두 조건은 독립 // 병렬임 그래서 else쓰면 안 돼
		if (data[i] < min_data)
			min_data = data[i];
		if (data[i] > max_data)
			max_data = data[i];
	}
	if (max_data - min_data == n - 1)
		return true;
	else
		return false;
}

int main(){
	int n;
	int* data;

	scanf("%d", &n);
	data = new int[n];
	for (int i = 0; i < n; i++){
		scanf("%d", &data[i]);
	}

	bool result = isConsecutive(data, n);

	if (result){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}

	delete[] data;
	return 0;
}