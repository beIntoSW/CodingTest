#include<cstdio>

const int INIT_COIN = 1000;

void coin_count(int *coin, int *coin_num, int value) {
	*coin_num += *coin / value;
	*coin %= value;
}

int main() {
	int coin;

	scanf("%d", &coin);

	int coin_num = 0;
	coin = INIT_COIN - coin;
	
	coin_count(&coin, &coin_num, 500);
	coin_count(&coin, &coin_num, 100);
	coin_count(&coin, &coin_num, 50);
	coin_count(&coin, &coin_num, 10);
	coin_count(&coin, &coin_num, 5);
	coin_count(&coin, &coin_num, 1);

	printf("%d\n", coin_num);
	return 0;
}