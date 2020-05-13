#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

const int MAX_LENGTH = 100000;



// string type �Լ� XXX
class MyString{
private:
	char* ch;
	int length;

public:
	MyString(){ }

	// ������
	/*MyString(const char* str){
		this->length = strlen(str);
		this->ch = new char[this->length];

		for (int i = 0; i < this->length; i++){
			this->ch[i] = str[i];
		}
	}*/


	// ������ // string
	MyString(const string &original){
		this->length = original.length();
		this->ch = new char[this->length + 1];

		for (int i = 0; i < this->length; i++){
			this->ch[i] = original[i];
		}

		this->ch[this->length] = '\0';
	}

	// �Ҹ���
	~MyString(){
		delete[] ch;
	}

	// <������ �����ε�
	bool operator<(const MyString &o) const{
		int n = min(this->length, o.length);
		for (int i = 0; i < n; i++){
			if (this->ch[i] < o.ch[i]){
				return true;
			}
			else if (this->ch[i] > o.ch[i])
				return false;
		}

		// ���̰� ª�� �ʱ����� �� ��, �� ������ �� ū ������ �����ϰ� ����
		if (this->length < o.length){
			return true;
		}
		else{
			return false;
		}
	}

	// > ������ �����ε�
	bool operator>(const MyString &o) const{
		int n = min(this->length, o.length);
		for (int i = 0; i < n; i++){
			if (this->ch[i] < o.ch[i]){
				return false;
			}
			else if (this->ch[i] > o.ch[i])
				return true;
		}

		// ���̰� ª�� �ʱ����� �� ��, �� ������ �� ū ������ �����ϰ� ����
		if (this->length > o.length){
			return true;
		}
		else{
			return false;
		}

	}
	
	
};

int main(){
	string s1;
	string s2;

	cin >> s1 >> s2;

	MyString mys1(s1);
	MyString mys2(s2);

	if (mys1 > mys2){
		cout << "1" << endl;
	}
	else if (mys1 < mys2){
		cout << "-1" << endl;
	}
	else
		cout << "0" << endl;

	return 0;
}