// CodeUp 1098
#include<cstdio>
#include<vector>

using namespace std;
const int SIZE = 100+1;

void checkTable(bool table[SIZE][SIZE]) {
	int l, d, x, y;

	// d : 0	-> 가로
	// d : 1	-> 세로

	scanf("%d %d %d %d", &l, &d, &x, &y);
	
	for (int i = 0; i < l; i++) {
		if (d == 0) {
			table[x][y + i] = 1;
		}
		else {
			table[x + i][y] = 1;
		}
	}
}

void displayTable(bool table[SIZE][SIZE], int x, int y) {
	for (int _x = 1; _x <= x; _x++) {
		for (int _y = 1; _y <= y; _y++) {
			printf("%d ", table[_x][_y]);
		}
		printf("\n");
	}
}

int main() {

	int _x, _y, num_bar;
	scanf("%d %d", &_x, &_y);
	scanf("%d", &num_bar);
	bool table[SIZE][SIZE] = {};
	
	for (int index = 0; index < num_bar; index++) {
		checkTable(table);
	}

	displayTable(table, _x, _y);
	


	return 0;
}