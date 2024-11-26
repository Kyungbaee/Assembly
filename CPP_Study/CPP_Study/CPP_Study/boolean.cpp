#include <iostream>

using namespace std;

// 불리언(boolean) 참/거짓
// 1바이트 정수
bool isHighLevel = true;
bool isPlayer = true;
bool isMale = false;

// char : 알파벳 / 숫자 문자를 나타낸다.
// wchar_t : 유니코드 문자를 나타낸다.

// ASCII (American Standard Code for Information Insterchange)

// 국제화 시대에는 영어만으로 서비스 할 수 없음
// 전 세계 모든 문자에 대해 유일 코드를 부여한 것이 유니코드 (unicode)
// 참고) 유니코드에서 가장 많은 번호를 차지하는게 한국어/중국어

// 유니코드는 표기 방식이 여러가지가 있는데 대표적으로 UTF-8, UTF-16
// UTF-8
// - 알파벳, 숫자 1바이트 (ASCII 동일한 번호)
// - 유럽 지역의 문자는 2바이트
// - 한글, 한자 등 3바이트
// UTF-16
// - 알파벳, 숫자, 한글, 한자 등 거의 대부분 문자 2바이트
// - 예외적인 고대 문자만 4바이트

wchar_t wch = L'안';

unsigned char flag; // 부호를 없애야 >> 을 하더라도 부호 비트가 안 딸려옴. 

// 문자열
// 문자들이 열을 지어서 모여 있는 것
// 정수 (1~8바이트) 고정 길이로
// 끝은 NULL (0)

// 한번 정해지면 절대 바뀌지 않을 값들
// constant의 약자인 const를 붙임 (변수를 상수화 한다고 함)
// const를 붙였으면 초기값을 반드시 지정해야 함

const int AIR = 0;
const int STUN = 1;
const int POLYMORPH = 2;
//const int FEAR = 3;
const int INVINCIBLE = 3;

// [데이터 영역]
// .data (초기값 있는 경우)
// .bss  (초기값 없는 경우)
// .rodata (읽기 전용 데이터)

int main()
{
	// [스택 영역]
	
	// pragma 영역 접기, 코드 영향 x
#pragma region 영역전개
	char str[] = { 'h','e','l','l','o','\0' }; // null 값을 붙여야 함.
	char str2[] = "hello world";	// null 값이 포함됨

	// cout은 char 전용
	wcout.imbue(locale("kor"));
	wcout << wch << endl;
#pragma endregion

#pragma region 비트 연산

	// ~ bitwise not
	// 단일 숫자의 모든 비트를 대상으로, 0은 1, 1은 0으로 뒤바꿈

	// & bitwise and
	// 두 숫자의 모든 비트 쌍을 대상으로, and 한다.

	// | bitwise or
	// 두 숫자의 모든 비트 쌍을 대상으로, or 한다.

	// ^ bitwise xor
	// 두 숫자의 모든 비트 쌍을 대상으로, xor 한다.

	// << 비트 좌측 이동
	// 비트열을 N만큼 왼쪽으로 이동
	// 왼쪽의 넘치는 N개의 비트는 버림. 새로 생성되는 N개의 비트는 0.
	// *2를 할 때 자주 보이는 패턴

	// >> 비트 우측 이동
	// 비트열을 N만큼 오른쪽으로 이동
	// 오른쪽의 넘치는 N개의 비트는 버림
	// 왼쪽에 새로 생성되는 N개의 비트는
	// - 부호 비트가 존재할 경우 부호 비트를 따라감 (부호있는 정수라면 이 부분을 유의)
	// - 아니면 0

	// 실습 BitFlag
	// 0b0000 [무적][공포][변이][스턴][공중부양]

	// 무적 상태로 만든다.
	flag = (1 << INVINCIBLE);

	// 변이 상태를 추가한다. (무적 + 변이)
	flag |= (1 << POLYMORPH);

	// 무적인지 확인하고 싶다. (다른 상태는 관심 없음)
	// bitmask
	bool invincible = ((flag & (1 << INVINCIBLE)) != 0);

	// 무적이거나 스턴 상태인지 확인하고 싶다면?
	bool stunOrInvincible = ((flag & 0b1010) != 0);

#pragma endregion
}