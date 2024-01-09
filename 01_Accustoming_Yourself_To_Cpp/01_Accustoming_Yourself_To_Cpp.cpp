// 01_Accustoming_Yourself_To_Cpp.cpp
#include <iostream>
#include <string>
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
const Rational operator*(const Rational& lhs, const Rational& rhs) { return Rational{}; };

Rational a, b, c;
// ..
//(a * b) = c;		// 상수 결과값에 대입연산자(=) 사용하여 오류발생

// 상수 멤버 함수
// const가 있고 없고의 차이로도 함수 오버로딩이 가능하다.

class TextBlock {
public:
	TextBlock(const std::string& _text) : text{ _text } {};

	static const int MaxSize = 10;
	enum { EnumMaxSize = 10 };
	char string[MaxSize];

	const char& operator[](std::size_t position) const {
		std::cout << "상수 멤버 함수 호출됨\n";
		return text[position];
	}


	// 1. 상수 멤버 함수를 호출하기 위해 this를 const TextBlock&으로 캐스팅
	//	- 비상수 객체에서 상수 객체로 변경은 안전한 캐스팅이기 때문에 static_cast 사용
	// 2. 호출된 상수 멤버 함수의 결과값에서 const를 떼어버리기 위해 char&으로 캐스팅
	//  - 상수 객체를 비상수 객체로 변환하는 방법은 const_cast 말고 방법이 없음
	char& operator[](std::size_t position) {
		return const_cast<char&>(static_cast<const TextBlock&>(*this)[position]);
	}

private:
	std::string text;
};

void print(const TextBlock& ctb) {
	std::cout << ctb[0] << std::endl;
}

// 비트수준 상수성 검사를 통과하는 상수성으로 작동하지 않는 예시
class CTextBlock {
public:
	CTextBlock(char* str) : pText(str) {};

	char& operator[](std::size_t position) const {
		return pText[position];
	}

	// mutable 키워드를 사용하면 언제든지 멤버 변수의 값을 수정할 수 있다.
	// 논리적 상수성 검사 통과를 위해 const 멤버 함수에서 값 검증을 할 때 사용할 수 있다.

private:
	char* pText;
};

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

	const char* cp = greeting;			// 포인터가 가리키는 대상의 값이 상수(비상수 포인터)
	cout << cp << endl;
	cp = text;							// 포인터 cp가 가리키는 대상은 변경 가능
	cout << cp << endl;
	// cp[0] = 'k';						// 포인터 cp가 가리키는 대상의 값은 변경 불가능(상수 데이터)


	char* const ccp = greeting;			// 포인터 자체가 상수(상수 포인터)
	cout << ccp << endl;
	// ccp = text;						// 포인터 ccp가 가리키는 대상 변경 불가능
	ccp[0] = 'k';						// 포인터 ccp가 가리키는 대상의 값 변경 가능
	cout << ccp << endl;				


	const char* const cccp = greeting;	// 포인터가 가리키는 대상과 대상의 값 변경 불가능
	cout << cccp << endl;
	// cccp = text;
	// cccp[0] = 'z';

	TextBlock tb("Hello");
	std::cout << tb[0] << std::endl;

	const TextBlock constTb("Hello");
	std::cout << constTb[0] << std::endl;

	print(tb);								// 함수의 매개변수로 상수 객체가 전달됨

	//const CTextBlock cctb("Hello");
}
