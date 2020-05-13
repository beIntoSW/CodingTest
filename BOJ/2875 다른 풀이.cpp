#include<cstdio>
#include<algorithm>

using namespace std;
int main() {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);

	printf("%d\n", min(min(n / 2, m), (n + m - k) / 3));

	return 0;
}