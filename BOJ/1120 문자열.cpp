#include<iostream>
#include<string>
#include<vector>

using namespace std;

const int MAX_LENGTH = 50;

/* 
	* 최소 차이를 구하는 함수

	* @param
	* table		:	차이값 저장한 벡터
*/

int getMinValue(vector<int> table) {

	// min : 최소 값을 구하기 위한, 최대 길이로 초기화
	int min = MAX_LENGTH;
	for (int tmp : table) {
		if (min > tmp) {
			min = tmp;
		}
	}

	return min;
}

/*
	* 문자열 비교를 통해 최소 값을 얻는 함수

	* @param
	* A		:	변경되는 문자열
	* B		:	비교 대상
*/
int process(string A, string B) {

	int length_dist = B.size() - A.size();
	vector<int> table = vector<int>(length_dist + 1);

	for (int start = 0; start <= length_dist; start++) {
		int dist_sum = 0;
		// 없애, 차이 출력
		for (int index = 0; index < A.size(); index++)
		{
			if (A[index] != B[index + start])
				dist_sum++;
		}

		table[start] = dist_sum;
	}

	return getMinValue(table);
}

int main() {

	string A, B;

	cin >> A >> B;

	cout << process(A, B) << endl;

	return 0;
}