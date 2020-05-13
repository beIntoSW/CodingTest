#include <cstdio>
#include <vector>
using namespace std;
/*
	a & b	=	and(bitwise)
	~a		=	not(bitwise)
	a |	b	=	or(bitwise)
	a ^ b	=	xor(bitwise)
*/
int main()
{
	int num, _x, _y;
	int a[20][20] = {}; // 0À¸·Î init

	/*scanf("%d", &num);*/
	
	// input
	for (int i = 1; i < 20; i++) {
		for (int j = 1; j < 20; j++) {
			scanf("%d ", &a[i][j]);
		}
	}

	scanf("%d", &num);
	 for (int k = 0; k < num; k++)
	{
		scanf("%d %d", &_x, &_y);

		for (int i = 1; i < 20; i++) 
		{
			if (a[_x][i] == 0)
				a[_x][i] = 1;
			else
				a[_x][i] = 0;
		}

		for (int i = 1; i < 20; i++)
		{
			if (a[i][_y] == 0)
				a[i][_y] = 1;
			else
				a[i][_y] = 0;
		}

	}


	for (int i = 1; i < 20; i++) {
		for (int j = 1; j < 20; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}


	return 0;
}

