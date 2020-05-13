/*

	172570 �̿��� ������Ʈ2

*/

#include<cstdio>
#include<vector>
#include<time.h>
#include<cmath>
using namespace std;

const int MAX_GEAR_NUM = 4;	// ��Ϲ��� �ִ� ����
const int TOOTH_COUNT = 8;	// ��Ϲ����� ��� ����
const int RIGHT = 2;		// ������ ��Ϲ����� ������ ����� �ε���
const int LEFT = 6;			// ���� ��Ϲ����Ϳ� ������ ����� �ε���

class GEAR {
private:
	vector<bool>  tooth;	// �� ����� ���¸� ��Ÿ���� ���� // 0�� 1�� ������ ������ bool������ ���
	int value;				// �� ��Ϲ����� ����

public:
	GEAR(vector<bool> _tooth, int _value):tooth(_tooth), value(_value){	} // ������
	GEAR() { }	// �⺻������
	
	// �ð�������� ȸ���ϴ� �Լ�
	void rotate() {
		vector<bool>::iterator it;
		bool buf = this->tooth.back();	// �ð���� ȸ���� ����, 7��° �� ����

		this->tooth.pop_back();			// 7��° �ε��� �� ����

		it = this->tooth.begin();		// iterator�� ó������ �ű� ��, 7��° �� �߰�
		this->tooth.insert(it, buf);
	}

	// �ݽð� �������� ȸ���ϴ� �Լ�
	void rotate_reverse() {
		vector<bool>::iterator it;
		bool buf = this->tooth.front();

		
		it = this->tooth.begin();		// ó������ �̵�
		this->tooth.erase(it);			// ó�� �� ����
		
		it = this->tooth.end();			// ���������� �̵�
		this->tooth.insert(it, buf);	// �������� �߰�
	}

	// ����� ���� �������� �Լ�
	bool getTooth(int index) {
		return this->tooth[index];
	}



	// 12�� ���⿡ ���� ������ �������� �Լ�
	int getScore() {
		if (this->tooth[0] == false) {
			return 0;
		}
		else
			return value;
	}

};


// �� ��Ϲ����� �´�� ����� '��'�� ���� ȸ�� ������ �˷��ִ� �Լ�
bool isRotate(GEAR g1, GEAR g2) {
	if (g1.getTooth(RIGHT) == g2.getTooth(LEFT))	// ���� ���� ���, false ����
		return false;
	else                                            // ���� �ٸ� ���, true ����
		return true;
		
}

// ��Ϲ����� ���ƾ� �� ���, �ݴ� �������� ���� ������, �ݴ� ������ �����ϴ� �Լ� 
// return : �´�Ƽ� ���ư��� ��Ϲ����� �ݴ����
int getDirection(int dir) {
	if (dir == 1)
		return -1;
	else if (dir == -1)
		return 1;
	else
		return 0;
}


// ȸ����Ű�� �Լ�
void doRot(vector<GEAR*> gear, vector<int> rot_arr) {
/*
	 gear		: 1~4�� ��Ϲ��� ����
	 rot_arr	: 1~4�� ��Ϲ����� ȸ�� ������ ������ ����
		1		: �ð����
		0		: ȸ�� X
		-1		: �ݽð����
*/
	for (int i = 1; i < MAX_GEAR_NUM + 1; i++) {	
		if (rot_arr[i] == 1) {			// �ð���� ȸ�� ��,
			gear[i]->rotate();
		}
		else if (rot_arr[i] == -1) {	// �ݽð���� ȸ�� ��, 
			gear[i]->rotate_reverse();
		}
	}
}


// �� ��Ϲ����� ȸ�� ������ �Ǵ��ϰ� �����ϴ� �Լ�
/*
	gear		: 1~4�� ��Ϲ��� ����
	gear_num	: �Է¹��� ȸ���ϰ� �Ǵ� ��Ϲ��� ��ȣ
	direction	: �Է¹��� ȸ�� ����
*/
vector<int> setRotArr(vector<GEAR*> gear, int gear_num, int direction) {
	
	/*
		rot_arr		:	1~4�� ��Ϲ����� ȸ�� ������ ������ ����
	*/
	vector<int> rot_arr = vector<int>(MAX_GEAR_NUM + 1);

	// �Է¹��� ��Ϲ����� ȸ���� ���� ����
	rot_arr[gear_num] = direction;


	// ȸ���ϴ� ��Ϲ����� ��,�찡 ������ �ٸ��Ƿ� ��, �� �� ������ �ݺ����� ����

	// �Է¹��� ��Ϲ����� �������� 4�� ��Ϲ������� ȸ�� ���� ����
	for (int i = gear_num + 1; i <= MAX_GEAR_NUM; i++) {// �Է¹��� ��Ϲ��� ~ 4�� ��Ϲ������� �ݺ��� ����

		if (isRotate(*gear[i - 1], *gear[i])) {			// �´�� �κ��� ���� ���� �ƴ� ���,
			rot_arr[i] = getDirection(direction);		// i��° ��Ϲ����� ȸ������ ����
		}
		direction = rot_arr[i];							// ���� �񱳸� ���� i��° ��Ϲ����� ȸ������ ����
	}

	direction = rot_arr[gear_num];						// 1�� ��Ϲ������� ȸ�� ���� �Ǵ��� ���� �Է¹��� ��Ϲ����� ���� ���� 
	
	// �Է¹��� ��Ϲ����� �������� 1�� ��Ϲ������� ȸ�� ���� ����
	for (int i = gear_num - 1; i > 0; i--) {			// �Է¹��� ��Ϲ��� ~ 1�� ��Ϲ������� �ݺ��� ����
		if (isRotate(*gear[i], *gear[i + 1])) {			// �´�� �κ��� ���� ���� �ƴ� ���,
			rot_arr[i] = getDirection(direction);		// i��° ��Ϲ����� ȸ������ ����
		}
		direction = rot_arr[i];							// ���� �񱳸� ���� i��° ��Ϲ����� ȸ������ ����
	}
						
	return rot_arr;										// �� ��Ϲ��� ����
}

int main() {
	
	vector<GEAR*> gear;									// ��Ϲ��� ��ü ���� ����

	int state;
	gear.push_back(new GEAR());							// 1~4�� �ε����� ����ϱ� ����, 0��° �ε��� ä���ֱ�

	for (int i = 1; i <= MAX_GEAR_NUM; i++) {			
		scanf("%d", &state);

		// false = N��, true = S��
		vector<bool> tooth = vector<bool>(TOOTH_COUNT);	// 8�� ũ�⸦ ���� bool ���� ����

		for (int j = TOOTH_COUNT-1; j >= 0; j--) {		// 7��° �ε��� -> 0��° �ε������� �������� �ݺ�
			tooth[j] = state % 10;						// �������� �̿��ؼ� �� ����
			state /= 10;
		}

		gear.push_back(new GEAR(tooth, pow(2,i-1)));	// ��� ���Ϳ� �� ��Ϲ����� ������ ���� ��ü ����

	}

	
	/*
		rot_num		:	ȸ�� Ƚ��
		rot_gear	:	ȸ���ϰ� �� ��Ϲ���
		rot_dir		:	ȸ���ϴ� ����
	*/
	int rot_gear, rot_dir;
	int rot_num;
	scanf("%d", &rot_num);

	for (int i = 0; i < rot_num; i++) {
		scanf("%d %d", &rot_gear, &rot_dir);

		vector<int> rot_arr = setRotArr(gear, rot_gear, rot_dir);				// ȸ�� ���� ������ ���� ����
		doRot(gear, rot_arr);													// ȸ�� ������ ������ ���͸� �̿��ؼ� ��� ��Ϲ��� ȸ��
	}


	int sum = 0;
	for (int i = 1; i <= MAX_GEAR_NUM; i++) {									// �� ��Ϲ����� ���� �� ���
		sum += gear[i]->getScore();
	}
	printf("%d\n", sum);



	return 0;
}