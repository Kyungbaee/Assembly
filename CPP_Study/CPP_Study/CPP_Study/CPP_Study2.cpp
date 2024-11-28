#include <iostream>
using namespace std;

// 분기문
// 반복문
// 열거형

// 숫자를 지정 안하면 첫 값은 0부터 시작
// 그 다음 값들은 이전 값 + 1
// const int를 사용한 방식은 컴파일에 따라 메모리(ptr로 주소를 참조)에 올라갈 경우도 있음
// enum은 항상 값을 대체하여 사용하기 때문에, 메모리 낭비를 하지 않음
enum ENUM_SRP
{
	ENUM_SCISSORS = 1,
	ENUM_ROCK,
	ENUM_PAPER
};

// #이 붙은거 -> 전처리 지시문
// #include <iostream>이라는 파일을 찾아서 해당 내용을 그냥 복붙
// 1) 전처리 2) 컴파일 3) 링크
#define DEFINE_SCISSORS 1+2
#define DEFINE_TEST cout << "Hello world" << '\n';

int main()
{
	srand(time(0));	// 랜덤 시드값 설정

	// rand(); 0~32767
	// int value = 1 + rand() % 3;	// 1, 2, 3

	const int SCISSORS = 1;
	const int ROCK = 2;
	const int PAPER = 3;

	while (true)
	{
		int num, com = 1 + rand() % 3;;
		bool win = false;
		bool draw = false;

		cout << "가위(1) 바위(2) 보(3) 골라주세요!" << '\n' << " > ";
		cin >> num;

		switch (num)
		{
		case (SCISSORS):
			cout << "가위(님) vs ";
			if (com == SCISSORS) {
				draw = true;
				cout << "가위(컴퓨터) ";
			}
			else if (com == PAPER) {
				win = true;
				cout << "보(컴퓨터) ";
			}
			else
				cout << "바위(컴퓨터) ";
			break;
		case (ROCK):
			cout << "바위(님) vs ";
			if (com == ROCK) {
				draw = true;
				cout << "바위(컴퓨터) ";
			}
			else if (com == SCISSORS) {
				win = true;
				cout << "가위(컴퓨터) ";
			}
			else
				cout << "보(컴퓨터) ";
			break;
		case (PAPER):
			cout << "보(님) vs ";
			if (com == PAPER) {
				draw = true;
				cout << "보(컴퓨터) ";
			}
			else if (com == ROCK) {
				win = true;
				cout << "바위(컴퓨터) ";
			}
			else
				cout << "가위(컴퓨터) ";
			break;
		}

		if (draw) cout << "비겼습니다. \n";
		else if (win) cout << "이겼습니다. \n";
		else cout << "졌습니다. \n";
		cout << '\n';
	}


	// 별찍기 1)
	// 유저들이 어떤 정수를 입력하면
	// N*N개의 별을 찍었으면 좋겠다.

	//int N;
	//cin >> N;

	//for (int i = 0; i < N; i++) 
	//{ 
	//	for (int j = 0; j < N; j++) cout << '*'; 
	//	cout << '\n';
	//}

	// 별찍기 2)
	// 1개부터 시작해서 순차적으로 줄마다 증가하게 수정

	//int N;
	//cin >> N;

	//for (int i = 0; i < N; i++) 
	//{ 
	//	for (int j = 0; j < i+1; j++) cout << '*'; 
	//	cout << '\n';
	//}

	// 별찍기 3)
	// N개부터 시작해서 순차적으로 줄마다 줄어들게 수정

	//int N;
	//cin >> N;

	//for (int i = 0; i < N; i++) 
	//{ 
	//	for (int j = 0; j < N - i; j++) cout << '*';
	//	cout << '\n';
	//}

	// 구구단
	// 2단부터 9단까지

	//for (int i = 2; i < 10; i++) {
	//	for (int j = 1; j < 10; j++)
	//		cout << i << '*' << j << '=' << i * j << '\n';
	//}
}