#include<stdio.h>
#include<iostream>
using namespace std;

// Selection Sort = O(n^2)
// Bubble Sort = O(n^2) ����, **** ��������� ���귮�� ���� -> �����δ� Selection Sort���� ����****

void bubbleSort(int data[], int n){

	
	for (int i = 0; i < n; i++){
		int negativecount = 0; // ���������� �����ϴ� ����
		// �������� ������ �ʿ� ���� ������ n-1
		for (int j = 0; j < n-i-1; j++){
			// �������� X -> �ڸ� ��ȯ
			if (data[j] > data[j + 1])
			{
				int tmp = data[j + 1];
				data[j + 1] = data[j];
				data[j] = tmp;
				negativecount++;
			}
		}

		// �̹� ���ĵǾ� ���� ��츦 ���� ����ġ��?
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