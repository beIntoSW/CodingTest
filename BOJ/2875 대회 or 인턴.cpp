#include<iostream>
#include<string>

using namespace std;



int getTotalTeam(int n, int m, int* p) {
	if (n / 2 >= m) {
		(*p) += (n - 2 * m);
		return m;
	}
	else {
		(*p) += (m - n / 2);
		return n / 2;
	}
}


int getMaxteam(int n, int m, int k) {
	int mod = 0;
	int div = getTotalTeam(n, m, &mod);

	if (k - mod > 0) {
		div -= (k - mod - 1) / 3 + 1;
	}

	if (div < 0) {
		return 0;
	}
	return div;
}


int main() {
	int n, m, k;

	scanf("%d %d %d", &n, &m, &k);

	int max_team = getMaxteam(n, m, k);

	printf("%d\n", max_team);

	return 0;
}


