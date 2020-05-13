#include<stdio.h>
#include<iostream>
#include<string>
#include<time.h>

using namespace std;

#define ROCK 1
#define SCISSORS 0
#define PAPER -1

#define WIN 1
#define DRAW 0
#define LOSE -1

class Game{
private:
	int value;
	static bool rock, scissors, paper;
	int iswin; // 1 = win, 0 = lose, -1 = default
public:
	Game(){
		iswin = DRAW;
	}

	/*Game(const string str){
	if (str.compare("가위") == 0)
	this->value = SCISSORS;
	else if (str.compare("바위") == 0)
	this->value = ROCK;
	else
	this->value = PAPER;
	}*/

	void setValue(const string str, int index){
		if (str.compare("가위") == 0){
			this->value = SCISSORS;
			if (!scissors)
				scissors = true;
		}
		else if (str.compare("바위") == 0)
		{
			this->value = ROCK;
			if (!rock)
				rock = true;
		}
		else{
			this->value = PAPER;
			if (!paper)
				paper = true;
		}
	}

	int getValue()
	{
		return this->value;
	}

	void setIsWin(int win){
	this->iswin = win;
	}

	int getIsWin(){
	return this->iswin;
	}


	// 무조건 2개가 떠야 해 //고쳐야함
	bool isDraw(){
		if (rock && paper && scissors)
			return true;
		else if ((!rock && !paper) || (!rock && !scissors) || (!scissors && !paper))
			return true;
		else
			return false;
	}

	int checkWin(int a, int b){
		if (a == ROCK && b == PAPER)
			return LOSE;
		else if (a == PAPER && b == ROCK)
			return WIN;
		else if (a == b)
			return DRAW;
		else if (a > b)
			return WIN;
		else
			return LOSE;
	}


	bool operator>(const Game &o){
		if (this->checkWin(this->value, o.value) == 1)
			return true;
		else
			return false;
	}

	bool operator<(const Game &o){
		if (this->checkWin(this->value, o.value) == -1)
			return true;
		else
			return false;
	}

	bool operator==(const Game&o){
		if (this->checkWin(this->value, o.value) == 0)
			return true;
		else
			return false;
	}

};

bool Game::rock = false, Game::scissors = false,  Game::paper = false;


// b 기준
int playGame(Game a, Game b){
	if (a>b)
		return LOSE;
	else if (a == b)
		return DRAW;
	else
		return WIN;
}

int main(){
	int num, res;
	Game* game_state;
	bool isdraw = false;
	string answer;
	


	cin >> num;
	cin.ignore();
	game_state = new Game[num];

	//getline(cin, answer, '\n');
	//cout << answer << endl;
	/*scanf("%s", &answer);*/

	cin >> answer;

	clock_t start = clock();

	game_state[0].setValue(answer, 0);

	for (int i = 1; i < num; i++){
		//scanf("%s", &answer);
		cin >> answer;
		game_state[i].setValue(answer, i);

		res = playGame(game_state[i - 1], game_state[i]);
		if (res == DRAW)
			game_state[i].setIsWin(game_state[i-1].getIsWin());
		else
			game_state[i].setIsWin(res);
		
		if (i == 1){
			game_state[i - 1].setIsWin(playGame(game_state[i], game_state[i - 1]));
		}

	}

	if (game_state[0].isDraw()){
		cout << "draw";
	}
	else{
		for (int i = 0; i < num; i++){
			res = game_state[i].getIsWin();

			if (res == DRAW)
			{
				isdraw = true;
				continue;
			}
			else if (isdraw){
				for (int j = 0; j < i; j++){
					cout << j << " ";
				}
				isdraw = false;
			}

			if (res == WIN){
				cout << i << " ";
			}
		}
	}
	cout << endl;

	
	delete[] game_state;
	clock_t end = clock();
	printf("Time : %lf\n", (double)(end - start) / CLOCKS_PER_SEC);

	return 0;
}