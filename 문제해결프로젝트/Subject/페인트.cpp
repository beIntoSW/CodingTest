#include<cstdio>
#include<vector>

const int MAX_SEAT_NUMBER = 1000;
const int MAX_COLOR_NUMBER = 100;

// 색을 위한 클래스
class Painting {
public:
	int left;
	int right;
	int color;

	Painting(){}

	Painting(int left, int right, int color) :left(left), right(right), color(color) {}


};

// data : 각 좌석의 색깔 배열, table : 모든 색깔의 count를 위한 배열(Histogram)
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

// n : 좌석 개수, m : 사용되는 색 개수
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
		if (table[color] == 0) // 가지치기 by "칠해져 있지 않은 색상은 제외한다."
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


		// 좌석 범위가 1~N까지여서 배열의 인덱스로 맞춰주기위해 1씩 빼줌.
		paintings[i].left -= 1;
		paintings[i].right -= 1;

	}

	solve(n, m, paintings);

	return 0;
}
