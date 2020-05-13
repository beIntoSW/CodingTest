#include<cstdio>
#include<vector>
#include<time.h>
#include<cmath>
using namespace std;

const int MAX_GEAR_NUM = 4;
const int MIN_GEAR_NUM = 1;
const int TOOTH_COUNT = 8;
const int RIGHT = 2;
const int LEFT = 6;

class GEAR {
private:
	vector<bool>  tooth;
	int value;

public:
	GEAR(vector<bool> _tooth, int _value) :tooth(_tooth), value(_value)
	{

	}
	GEAR() { }

	// 회전
	void rotate() {
		vector<bool>::iterator it;
		bool buf = this->tooth.back();

		this->tooth.pop_back();

		it = this->tooth.begin();
		this->tooth.insert(it, buf);
	}

	void rotate_reverse() {
		vector<bool>::iterator it;
		bool buf = this->tooth.front();


		it = this->tooth.begin();
		this->tooth.erase(it);

		it = this->tooth.end();
		this->tooth.insert(it, buf);
	}



	bool getTooth(int index) {
		return this->tooth[index];
	}



	// boolean 할까 고민중..
	int getScore() {
		if (this->tooth[0] == false) {
			return 0;
		}
		else
			return value;
	}

};


// 3시 9시 check 후 rotation



bool isRotate(GEAR g1, GEAR g2) {
	if (g1.getTooth(RIGHT) == g2.getTooth(LEFT))
		return false;
	else
		return true;
}

int getDirection(int dir) {
	if (dir == 1)
		return -1;
	else if (dir == -1)
		return 1;
	else
		return 0;
}

void doRot(vector<GEAR*> gear, vector<int> rot_arr) {

	for (int i = 1; i < MAX_GEAR_NUM + 1; i++) {
		if (rot_arr[i] == 1) {
			gear[i]->rotate();
		}
		else if (rot_arr[i] == -1) {
			gear[i]->rotate_reverse();
		}
	}
}

//// 재귀로 풀어볼까?
//void setRotArr(vector<GEAR*> gear, vector<int> rot_arr, int gear_num) {
//	
//	
//	int direction = rot_arr[gear_num];
//	// 오른쪽
//	for (int i = gear_num + 1; i <= MAX_GEAR_NUM; i++) {
//		
//		if (isRotate(*gear[i - 1], *gear[i])) {
//			rot_arr[i] = getDirection(direction);
//		}
//		direction = rot_arr[i];
//	}
//
//	direction = rot_arr[gear_num];
//	// 왼쪽
//	for (int i = gear_num - 1; i > 0; i--) {
//		if (isRotate(*gear[i], *gear[i + 1])) {
//			rot_arr[i] = getDirection(direction);
//		}
//		direction = rot_arr[i];
//	}
//}

// 재귀로 풀어볼까?
void setRotArr(vector<GEAR*> gear, int gear_num, int direction) {

	vector<int> rot_arr = vector<int>(MAX_GEAR_NUM + 1);
	rot_arr[gear_num] = direction;

	// 오른쪽
	for (int i = gear_num + 1; i <= MAX_GEAR_NUM; i++) {

		if (isRotate(*gear[i - 1], *gear[i])) {
			rot_arr[i] = getDirection(direction);
		}
		direction = rot_arr[i];
	}

	direction = rot_arr[gear_num];
	// 왼쪽
	for (int i = gear_num - 1; i > 0; i--) {
		if (isRotate(*gear[i], *gear[i + 1])) {
			rot_arr[i] = getDirection(direction);
		}
		direction = rot_arr[i];
	}

	doRot(gear, rot_arr);

}






//// 1234 돌리기
// 돌리기전 상태를 한번에 보고 하나?
void gearSelect(vector<GEAR*> gear, int num, bool dir) {



}

int main() {

	vector<GEAR*> gear;

	int state;
	gear.push_back(new GEAR());
	//// 시간 체크 시작
	//clock_t start = clock();
	double total_time = 0;

	for (int i = 1; i <= MAX_GEAR_NUM; i++) {
		scanf("%d", &state);

		// false = N극, true = S극
		clock_t start = clock();
		vector<bool> tooth = vector<bool>(TOOTH_COUNT);

		for (int j = TOOTH_COUNT - 1; j >= 0; j--) {
			tooth[j] = state % 10;
			state /= 10;
		}

		gear.push_back(new GEAR(tooth, pow(2, i - 1)));
		clock_t end = clock();
		total_time += (double)(end - start);
	}



	int rot_gear, rot_dir;
	int rot_num;
	scanf("%d", &rot_num);

	for (int i = 0; i < rot_num; i++) {
		scanf("%d %d", &rot_gear, &rot_dir);

		//vector<int> rot_arr = vector<int>(MAX_GEAR_NUM + 1);
		//rot_arr[rot_gear] = rot_dir;

		// 돌리는 함수
		clock_t start = clock();
		setRotArr(gear, rot_gear, rot_dir);
		clock_t end = clock();
		total_time += (double)(end - start);
	}

	clock_t start = clock();
	int sum = 0;
	for (int i = 1; i <= MAX_GEAR_NUM; i++) {
		sum += gear[i]->getScore();
	}
	printf("%d\n", sum);

	clock_t end = clock();
	total_time += (double)(end - start);
	printf("Time : %lf\n", (double)total_time / CLOCKS_PER_SEC);


	return 0;
}