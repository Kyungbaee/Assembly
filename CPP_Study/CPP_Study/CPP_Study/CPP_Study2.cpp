#include <iostream>
using namespace std;

// �б⹮
// �ݺ���
// ������

// ���ڸ� ���� ���ϸ� ù ���� 0���� ����
// �� ���� ������ ���� �� + 1
// const int�� ����� ����� �����Ͽ� ���� �޸�(ptr�� �ּҸ� ����)�� �ö� ��쵵 ����
// enum�� �׻� ���� ��ü�Ͽ� ����ϱ� ������, �޸� ���� ���� ����
enum ENUM_SRP
{
	ENUM_SCISSORS = 1,
	ENUM_ROCK,
	ENUM_PAPER
};

// #�� ������ -> ��ó�� ���ù�
// #include <iostream>�̶�� ������ ã�Ƽ� �ش� ������ �׳� ����
// 1) ��ó�� 2) ������ 3) ��ũ
#define DEFINE_SCISSORS 1+2
#define DEFINE_TEST cout << "Hello world" << '\n';

int main()
{
	srand(time(0));	// ���� �õ尪 ����

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

		cout << "����(1) ����(2) ��(3) ����ּ���!" << '\n' << " > ";
		cin >> num;

		switch (num)
		{
		case (SCISSORS):
			cout << "����(��) vs ";
			if (com == SCISSORS) {
				draw = true;
				cout << "����(��ǻ��) ";
			}
			else if (com == PAPER) {
				win = true;
				cout << "��(��ǻ��) ";
			}
			else
				cout << "����(��ǻ��) ";
			break;
		case (ROCK):
			cout << "����(��) vs ";
			if (com == ROCK) {
				draw = true;
				cout << "����(��ǻ��) ";
			}
			else if (com == SCISSORS) {
				win = true;
				cout << "����(��ǻ��) ";
			}
			else
				cout << "��(��ǻ��) ";
			break;
		case (PAPER):
			cout << "��(��) vs ";
			if (com == PAPER) {
				draw = true;
				cout << "��(��ǻ��) ";
			}
			else if (com == ROCK) {
				win = true;
				cout << "����(��ǻ��) ";
			}
			else
				cout << "����(��ǻ��) ";
			break;
		}

		if (draw) cout << "�����ϴ�. \n";
		else if (win) cout << "�̰���ϴ�. \n";
		else cout << "�����ϴ�. \n";
		cout << '\n';
	}


	// ����� 1)
	// �������� � ������ �Է��ϸ�
	// N*N���� ���� ������� ���ڴ�.

	//int N;
	//cin >> N;

	//for (int i = 0; i < N; i++) 
	//{ 
	//	for (int j = 0; j < N; j++) cout << '*'; 
	//	cout << '\n';
	//}

	// ����� 2)
	// 1������ �����ؼ� ���������� �ٸ��� �����ϰ� ����

	//int N;
	//cin >> N;

	//for (int i = 0; i < N; i++) 
	//{ 
	//	for (int j = 0; j < i+1; j++) cout << '*'; 
	//	cout << '\n';
	//}

	// ����� 3)
	// N������ �����ؼ� ���������� �ٸ��� �پ��� ����

	//int N;
	//cin >> N;

	//for (int i = 0; i < N; i++) 
	//{ 
	//	for (int j = 0; j < N - i; j++) cout << '*';
	//	cout << '\n';
	//}

	// ������
	// 2�ܺ��� 9�ܱ���

	//for (int i = 2; i < 10; i++) {
	//	for (int j = 1; j < 10; j++)
	//		cout << i << '*' << j << '=' << i * j << '\n';
	//}
}