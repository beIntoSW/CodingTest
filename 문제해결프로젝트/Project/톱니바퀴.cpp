/*

	172570 이영수 프로젝트2

*/

#include<cstdio>
#include<vector>
#include<time.h>
#include<cmath>
using namespace std;

const int MAX_GEAR_NUM = 4;	// 톱니바퀴 최대 개수
const int TOOTH_COUNT = 8;	// 톱니바퀴의 톱니 개수
const int RIGHT = 2;		// 오른쪽 톱니바퀴와 만나는 톱니의 인덱스
const int LEFT = 6;			// 왼쪽 톱니바퀴와와 만나는 톱니의 인덱스

class GEAR {
private:
	vector<bool>  tooth;	// 각 톱니의 상태를 나타내는 변수 // 0과 1로 나오기 때문에 bool변수를 사용
	int value;				// 각 톱니바퀴의 점수

public:
	GEAR(vector<bool> _tooth, int _value):tooth(_tooth), value(_value){	} // 생성자
	GEAR() { }	// 기본생성자
	
	// 시계방향으로 회전하는 함수
	void rotate() {
		vector<bool>::iterator it;
		bool buf = this->tooth.back();	// 시계방향 회전을 위한, 7번째 값 저장

		this->tooth.pop_back();			// 7번째 인덱스 값 제거

		it = this->tooth.begin();		// iterator를 처음으로 옮긴 후, 7번째 값 추가
		this->tooth.insert(it, buf);
	}

	// 반시계 반향으로 회전하는 함수
	void rotate_reverse() {
		vector<bool>::iterator it;
		bool buf = this->tooth.front();

		
		it = this->tooth.begin();		// 처음으로 이동
		this->tooth.erase(it);			// 처음 값 삭제
		
		it = this->tooth.end();			// 마지막으로 이동
		this->tooth.insert(it, buf);	// 마지막에 추가
	}

	// 톱니의 값을 가져오는 함수
	bool getTooth(int index) {
		return this->tooth[index];
	}



	// 12시 방향에 따라 점수를 가져오는 함수
	int getScore() {
		if (this->tooth[0] == false) {
			return 0;
		}
		else
			return value;
	}

};


// 두 톱니바퀴가 맞닿는 톱니의 '극'에 따라 회전 유무를 알려주는 함수
bool isRotate(GEAR g1, GEAR g2) {
	if (g1.getTooth(RIGHT) == g2.getTooth(LEFT))	// 극이 같을 경우, false 리턴
		return false;
	else                                            // 극이 다를 경우, true 리턴
		return true;
		
}

// 톱니바퀴가 돌아야 할 경우, 반대 방향으로 돌기 때문에, 반대 방향을 리턴하는 함수 
// return : 맞닿아서 돌아가는 톱니바퀴의 반대방향
int getDirection(int dir) {
	if (dir == 1)
		return -1;
	else if (dir == -1)
		return 1;
	else
		return 0;
}


// 회전시키는 함수
void doRot(vector<GEAR*> gear, vector<int> rot_arr) {
/*
	 gear		: 1~4번 톱니바퀴 벡터
	 rot_arr	: 1~4번 톱니바퀴의 회전 유무를 가지는 벡터
		1		: 시계방향
		0		: 회전 X
		-1		: 반시계방향
*/
	for (int i = 1; i < MAX_GEAR_NUM + 1; i++) {	
		if (rot_arr[i] == 1) {			// 시계방향 회전 시,
			gear[i]->rotate();
		}
		else if (rot_arr[i] == -1) {	// 반시계방향 회전 시, 
			gear[i]->rotate_reverse();
		}
	}
}


// 각 톱니바퀴의 회전 유무를 판단하고 리턴하는 함수
/*
	gear		: 1~4번 톱니바퀴 벡터
	gear_num	: 입력받은 회전하게 되는 톱니바퀴 번호
	direction	: 입력받은 회전 방향
*/
vector<int> setRotArr(vector<GEAR*> gear, int gear_num, int direction) {
	
	/*
		rot_arr		:	1~4번 톱니바퀴의 회전 유무를 저장할 벡터
	*/
	vector<int> rot_arr = vector<int>(MAX_GEAR_NUM + 1);

	// 입력받은 톱니바퀴에 회전할 방향 저장
	rot_arr[gear_num] = direction;


	// 회전하는 톱니바퀴의 좌,우가 방향이 다르므로 좌, 우 를 나눠서 반복문을 실행

	// 입력받은 톱니바퀴를 기준으로 4번 톱니바퀴까지 회전 유무 저장
	for (int i = gear_num + 1; i <= MAX_GEAR_NUM; i++) {// 입력받은 톱니바퀴 ~ 4번 톱니바퀴까지 반복문 실행

		if (isRotate(*gear[i - 1], *gear[i])) {			// 맞닿는 부분이 같은 극이 아닐 경우,
			rot_arr[i] = getDirection(direction);		// i번째 톱니바퀴의 회전방향 저장
		}
		direction = rot_arr[i];							// 다음 비교를 위해 i번째 톱니바퀴의 회전방향 저장
	}

	direction = rot_arr[gear_num];						// 1번 톱니바퀴까지 회전 유무 판단을 위해 입력받은 톱니바퀴의 방향 저장 
	
	// 입력받은 톱니바퀴를 기준으로 1번 톱니바퀴까지 회전 유무 저장
	for (int i = gear_num - 1; i > 0; i--) {			// 입력받은 톱니바퀴 ~ 1번 톱니바퀴까지 반복문 실행
		if (isRotate(*gear[i], *gear[i + 1])) {			// 맞닿는 부분이 같은 극이 아닐 경우,
			rot_arr[i] = getDirection(direction);		// i번째 톱니바퀴의 회전방향 저장
		}
		direction = rot_arr[i];							// 다음 비교를 위해 i번째 톱니바퀴의 회전방향 저장
	}
						
	return rot_arr;										// 각 톱니바퀴 리턴
}

int main() {
	
	vector<GEAR*> gear;									// 톱니바퀴 객체 벡터 생성

	int state;
	gear.push_back(new GEAR());							// 1~4번 인덱스를 사용하기 위해, 0번째 인덱스 채워주기

	for (int i = 1; i <= MAX_GEAR_NUM; i++) {			
		scanf("%d", &state);

		// false = N극, true = S극
		vector<bool> tooth = vector<bool>(TOOTH_COUNT);	// 8의 크기를 가진 bool 벡터 생성

		for (int j = TOOTH_COUNT-1; j >= 0; j--) {		// 7번째 인덱스 -> 0번째 인덱스까지 역순으로 반복
			tooth[j] = state % 10;						// 나머지를 이용해서 값 저장
			state /= 10;
		}

		gear.push_back(new GEAR(tooth, pow(2,i-1)));	// 톱니 벡터와 각 톱니바퀴의 점수를 가진 객체 저장

	}

	
	/*
		rot_num		:	회전 횟수
		rot_gear	:	회전하게 될 톱니바퀴
		rot_dir		:	회전하는 방향
	*/
	int rot_gear, rot_dir;
	int rot_num;
	scanf("%d", &rot_num);

	for (int i = 0; i < rot_num; i++) {
		scanf("%d %d", &rot_gear, &rot_dir);

		vector<int> rot_arr = setRotArr(gear, rot_gear, rot_dir);				// 회전 유무 저장한 벡터 저장
		doRot(gear, rot_arr);													// 회전 유무를 저장한 벡터를 이용해서 모든 톱니바퀴 회전
	}


	int sum = 0;
	for (int i = 1; i <= MAX_GEAR_NUM; i++) {									// 각 톱니바퀴의 점수 합 계산
		sum += gear[i]->getScore();
	}
	printf("%d\n", sum);



	return 0;
}