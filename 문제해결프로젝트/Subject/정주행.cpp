#include<stdio.h>
#include<iostream>
using namespace std;

// �������� ���� = YES / �׷��� �ʴٸ� = NO
// ���θ� ǥ��! // �ִ� - �ּ� = ũ�� - 1 ���� �ƴ޾ƾ� ��.
bool isConsecutive(int data[], int n){
	int max_data = data[0];
	int min_data = data[0];

	for (int i = 0; i < n; i++){

		// �� ������ ���� // ������ �׷��� else���� �� ��
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