#include<stdio.h>
#include<iostream>

using namespace std;

void solve(int data[], int n, int p, int q){
	int sum = 0, value = 0, count = 0;
	for (int i = 0; i < n; i++){
		value = data[i];

		if (value <= p){
			sum += value;
			count += 1;
		}
	}
	printf("%d %d\n", count, sum);
	if (sum <= q)
		printf("YES\n");
	else
		printf("NO\n");

	
}

int main(){
	int n, p, q;
	int *data;

	scanf("%d %d %d", &n, &p, &q);
	data = new int[n];

	for (int i = 0; i < n; i++){
		scanf("%d", &data[i]);
	}

	solve(data, n, p, q);

	delete[] data;
	return 0;
}