#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

const int MAX_LENGTH = 100000;



// string type 함수 XXX
class MyString{
private:
	char* ch;
	int length;

public:
	MyString(){ }

	// 생성자
	/*MyString(const char* str){
		this->length = strlen(str);
		this->ch = new char[this->length];

		for (int i = 0; i < this->length; i++){
			this->ch[i] = str[i];
		}
	}*/


	// 생성자 // string
	MyString(const string &original){
		this->length = original.length();
		this->ch = new char[this->length + 1];

		for (int i = 0; i < this->length; i++){
			this->ch[i] = original[i];
		}

		this->ch[this->length] = '\0';
	}

	// 소멸자
	~MyString(){
		delete[] ch;
	}

	// <연산자 오버로딩
	bool operator<(const MyString &o) const{
		int n = min(this->length, o.length);
		for (int i = 0; i < n; i++){
			if (this->ch[i] < o.ch[i]){
				return true;
			}
			else if (this->ch[i] > o.ch[i])
				return false;
		}

		// 길이가 짧은 쪽까지의 비교 후, 더 긴쪽이 더 큰 것으로 생각하고 리턴
		if (this->length < o.length){
			return true;
		}
		else{
			return false;
		}
	}

	// > 연산자 오버로딩
	bool operator>(const MyString &o) const{
		int n = min(this->length, o.length);
		for (int i = 0; i < n; i++){
			if (this->ch[i] < o.ch[i]){
				return false;
			}
			else if (this->ch[i] > o.ch[i])
				return true;
		}

		// 길이가 짧은 쪽까지의 비교 후, 더 긴쪽이 더 큰 것으로 생각하고 리턴
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