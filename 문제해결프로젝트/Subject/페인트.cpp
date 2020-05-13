#include<cstdio>
#include<vector>

const int MAX_SEAT_NUMBER = 1000;
const int MAX_COLOR_NUMBER = 100;

// ���� ���� Ŭ����
class Painting {
public:
	int left;
	int right;
	int color;

	Painting(){}

	Painting(int left, int right, int color) :left(left), right(right), color(color) {}


};

// data : �� �¼��� ���� �迭, table : ��� ������ count�� ���� �迭(Histogram)
void fillFrequencyTable(int data[], int n, int table[]) {

	// Array Init
	for (int i = 0; i < MAX_COLOR_NUMBER; i++) {
		table[i] = 0;
	}

	// Make Histogram_color
	for (int i = 0; i < n; i++) {
		int color = data[i];
		table[color] += 1;
	}
}

// n : �¼� ����, m : ���Ǵ� �� ����
void solve(int n, int m, const Painting* paintings) {
	int* seats = new int[n];

	// seat_init
	for (int i = 0; i < n; i++) {
		seats[i] = 0;
	}

	// Insert seat_color
	for (int i = 0; i < m; i++) {
		const Painting &p = paintings[i];

		for (int j = p.left; j <= p.right; j++) {
			seats[j] = p.color;
		}
	}


	int *table = new int[MAX_COLOR_NUMBER]; // for Color Histogram
	fillFrequencyTable(seats, n, table); // Make Histogram

	int mincolor = seats[0];
	int maxcolor = seats[0];


	for (int color = 0; color < MAX_COLOR_NUMBER; color++) {
		if (table[color] == 0) // ����ġ�� by "ĥ���� ���� ���� ������ �����Ѵ�."
			continue;

		if (table[color] < table[mincolor])
		{
			mincolor = color;
		}

		if (table[color] > table[maxcolor])
		{
			maxcolor = color;
		}
		
	}


	printf("%d\n", maxcolor);
	printf("%d\n", mincolor);


	delete[] seats;
	delete[] table;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	Painting* paintings = new Painting[n];

	for (int i = 0; i < m; ++i) {
		scanf("%d", &paintings[i].left);
		scanf("%d", &paintings[i].right);
		scanf("%d", &paintings[i].color);


		// �¼� ������ 1~N�������� �迭�� �ε����� �����ֱ����� 1�� ����.
		paintings[i].left -= 1;
		paintings[i].right -= 1;

	}

	solve(n, m, paintings);

	return 0;
}
