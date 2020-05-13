#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

/*
	����

	- ������ �ȵ����� ���, 
		- �ִ�, �ּ�, ������׷�, k��° => O(N)
	- �Ǿ��ִٸ�?
		- O(1), O(1), O(logN), O(1)

	binary search : ���ϴ� ���� ������ ã�� �� ����.(���� : ������ �Ǿ� ���� ���)
*/

vector<int> getPossibleTargets(int n, int m, int* cards, int* targets) {
	vector<int> possibleTargets;

	// sort(���� ��ġ, �� ��ġ)
	// ������������ ����
	sort(cards, cards + n);

	// ����ϴ� ī��� 3�� �ݺ��� ����ص� ������,
	// N : 1 ~ 1000 // M : 1 ~ 100 �̱� ������,
	// M + N�� 2�� �ݺ����� �̿��� �� �ϴ�.
	for (int i = 0; i < m; i++) {
		int k = targets[i]; // ��÷ ��ȣ ��
		bool possible = false; // ���� ������ ������ bool ����
		
		// ����� ī�带 ���� �ݺ���
		for (int j = 0; j < n; ++j) {
			int x = cards[j];

			// ����� ī�带 ���� �ݺ��� + �ߺ��� �� �� �ֱ� ������, p <= j
			for (int p = 0; p <= j; p++) {
				int y = cards[p];
				
				int z = k - (x + y); 
				// ��÷ ī���� �ݺ��� + ����� ī���� 2�� �ݺ����� �̿��ϱ� ����, 
				// ����ϴ� ���� 

				// z�� ����Ž������ ã�´�!
				if (binary_search(cards, cards + n, z) == true) {
					possible = true;
					break;
				}
			}

			// ��÷ ��ȣ�� �����Ѵٸ�, ���� ��÷��ȣ��
			if (possible) {
				break;
			}
		}

		// �����ϸ� �߰�
		if (possible) {
			possibleTargets.push_back(k);
		}
	}

	
	sort(possibleTargets.begin(), possibleTargets.end());
	return possibleTargets;
}

int main() {
	/*
		n		: ī���� ��
		m		: ��÷ ��ȣ�� ��
		cards	: ī�� ��ȣ �迭
		targets	: ��÷ ��ȣ �迭
	*/
	int n, m;
	scanf("%d %d", &n, &m);

	int* cards = new int[n];
	int* targets = new int[m];

	for (int i = 0; i < n; i++) {
		scanf("%d", &cards[i]);
	}
	
	for (int i = 0; i < m; i++) {
		scanf("%d", &targets[i]);
	}

	// answers : ���� �� �ִ� ��÷ ��ȣ�� ���� ����
	vector<int> answers = getPossibleTargets(n, m, cards, targets);

	if (answers.size() == 0) {
		printf("NO");
	}
	else {
		for (int i = 0; i < answers.size(); i++) {
			if (i > 0) {
				printf(" ");
			}

			printf("%d", answers[i]);
		}
	}

	delete[] cards;
	delete[] targets;

	return 0;
}