#include<cstdio>
#include<vector>

using namespace std;

// 최대 등수 + 1
const int max_value = 100000 + 1;

// 최대 신입사원 수를 구하는 함수
/*
	table의 index : 서류점수
	table의 값	  : 면접점수

	서류점수를 기준으로 정렬하기 위해, index로 사용함 
*/
int getMaxEmp_faster(vector<int> table)
{
	/*
		emp_num : 최대 신입사원 수
		rank	: 가장 높은 점수를 저장할 변수 ex) 1 ~ i-1 번째까지 중 가장 높은 점수
	*/
	int emp_num = table.size() - 1;
	int rank = max_value;

	// 가장 높은 점수를 저장한 rank변수와 비교해서, 가지치기 
	for (int i = 1; i < table.size(); i++) {

		if (rank > table[i]) {
			rank = table[i];
		}
		else {
			emp_num--;
		}
	}

	return emp_num;
}


// 최대 신입사원 수를 구하는 함수
int getMaxEmp(vector<int> table) 
{
	/*
		emp_num : 최대 신입사원 수
	*/
	int emp_num = table.size() - 1;

	// 2중 반복문을 이용해서, 비교
	for (int i = 2; i < table.size(); i++) {
		if (table[i] == 1) {
			continue;
		}
		else {
			for (int j = i-1; j >= 1; j--) {
				if (table[i] >= table[j]) {
					emp_num--;
					break;
				}
			}
		}
	}

	return emp_num;
}

void process(int testIndex) 
{
	int person;

	scanf("%d", &person);

	vector<int> table = vector<int>(person + 1);

	for (int i = 0; i < person; i++) {
		int score_1, score_2;
		scanf("%d %d", &score_1, &score_2);

		table[score_1] = score_2;
	}
	
	printf("%d\n", getMaxEmp_faster(table));
	// printf("%d\n", getMaxEmp(table));

}


int main() {
	int testcase;

	scanf("%d", &testcase);

	for (int testIndex = 0; testIndex < testcase; testIndex++) {
		process(testIndex);
	}


	return 0;
}