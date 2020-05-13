#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

const int MAX_SERIAL_NUMBER = 100000;

// 빈도수 채우기
void fillFrequencyTable(const vector<int> & data, int n, vector<int> &table) {
	table.clear();

	table.resize(MAX_SERIAL_NUMBER+1,0); // 0 ~100000 까지 표현하려고 + 1해줌

	for (int i = 0; i < n; i++) {
		int serial = data[i];
		table[serial] += 1;
	}
}

// 중복 없애는 함수
vector<int> getUniqueElements(const vector<int>& data, int n) {
	vector<int> ret;
	vector<int> table;

	fillFrequencyTable(data, n, table);

	// serial number : 1 ~ 100000
	for (int number = 1; number <= MAX_SERIAL_NUMBER; number++)
	{
		// 중복 X && 오름차순으로 대입
		if (table[number] == 1)
			ret.push_back(number);

	}
	return ret;
}



// 배열의 단점 : 원소 추가, 삭제, 크기 변경 --> 오래 걸림 && 불편
//	-> vector 컨테이너 사용!

/*	vector 컨테이너 : 자동으로 메모리가 할당되는 배열
	vector<int> v(5) : 0으로 초기화된 5개의 원소를 갖는 배열 생성 // 0으로 초기화
	vector<int> v(5,2) : 2로 초기화된 5개의 원소를 갖는 배열 생성 // 특정 값으로 초기화
	
	멤버함수 : https://blockdmask.tistory.com/70
	v.clear() : 모든 원소 제거, 메모리는 그대로
	v.resize(n,3) : 크기를 n으로 변경하고 3으로 초기화
*/
int main() {
	int n;
	scanf("%d", &n);

	vector<int> data = vector<int>(n);

	// 배열과 같은 방법으로 입력 받음
	for (int i = 0; i < n; ++i) {
		scanf("%d", &data[i]);
	}

	const vector<int> answer = getUniqueElements(data, n);

	for (int i = 0; i < answer.size(); ++i) {
		if (i > 0)
			printf(" ");
		printf("%d", answer[i]);
	}

	return 0;
}