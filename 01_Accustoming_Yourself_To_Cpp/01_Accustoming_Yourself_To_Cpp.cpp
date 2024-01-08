// 01_Accustoming_Yourself_To_Cpp.cpp
#include <iostream>

/*
*   항목 2: #define을 쓰려거든 const, enum, inline을 떠올리자
*/

#define ASPECT_RATIO 1.653
const double AspectRatio = 1.653;

class GamePlayer {
private:
	static const int NumTurns = 5;
	int scores[NumTurns];

	// 구식 컴파일러의 경우
	enum { EnumNumTurns = 5 };
	int enumScores[EnumNumTurns];
};

void f(int num) {
	//std::cout << num << std::endl; 
};
#define CALL_WITH_MAX(a, b) f((a) > (b) ? (a) : (b))

// 함수에 const 사용
class Rational {};
const Rational operator*(const Rational& lhs, const Rational& rhs) {};

Rational a, b, c;
// ..
//(a * b) = c;		// 상수 결과값에 대입연산자(=) 사용하여 오류발생

int main()
{
	int a = 5, b = 0;
	CALL_WITH_MAX(++a, b);
	std::cout << a << std::endl;

	CALL_WITH_MAX(++a, b + 10);
	std::cout << a << std::endl;


	// 포인터와 상수
	using namespace std;

	char greeting[] = "Hello";
	char text[] = "Text";

	char* p = greeting;
	cout << p << endl;
	p = text;
	cout << p << endl;
	p[0] = 'Z';
	cout << p << endl;

	const char* cp = greeting;			// 포인터가 가리키는 대상이 상수(비상수 포인터)
	cout << cp << endl;
	cp = text;							// 포인터 cp가 가리키는 대상은 변경 가능
	cout << cp << endl;
	// cp[0] = 'k';						// 포인터 cp가 가리키는 대상의 값은 변경 불가능(상수 데이터)


	char* const ccp = greeting;			// 포인터가 가리키는 대상이 상수(상수 포인터)
	cout << ccp << endl;
	// ccp = text;						// 포인터 ccp가 가리키는 대상 변경 불가능
	ccp[0] = 'k';
	cout << ccp << endl;				// 포인터 ccp가 가리키는 대상의 값은 변경 가능


	const char* const cccp = greeting;	// 포인터가 가리키는 대상과 대상의 값 변경 불가능
	cout << cccp << endl;
	// cccp = text;
	// cccp[0] = 'z';
}
