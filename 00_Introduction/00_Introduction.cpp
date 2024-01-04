#include <iostream>

/// <summary>
/// '독자 여러분 반갑습니다' 챕터에 나온
/// 용어 정리 및 이름 짓기 규칙 요약
/// </summary>
/// <returns></returns>

/*
* 1.선언(declaration)
* - 코드에 사용되는 '어떤 대상'의 이름과 타입을 컴파일러에게 알려주는 것
* - 선언에는 구체적인 세부사항이 들어가지 않는다.
*/

extern int x;							// 객체 선언
// *이 책에서는 사용자 정의 타입(구조체, 클래스 등)이 아니더라도 객체라는 용어를 사용한다.

std::size_t numDigits(int number);		// 함수 선언
// 함수의 선언문에는 시그니처(signature, 매개변수 리스트, 반환 타입)이 나와 있다.
// *시그니처에 대한 공식적인 C++ 정의에서는 함수의 반환 타입을 제외하지만, 이 책에서는 반환 타입도 시그니처의 일부로 간주.

class Widget;							// 클래스 선언

template<typename T>					// 템플릿 선언
class GraphNode;

/*
* 2. 정의(definition)
* - 선언에서 빠진 구체적인 세부사항을 컴파일러에게 제공하는 것
* - 객체의 경우 컴파일러가 해당 객체에 대한 메모리를 마련하는 부분을, 함수나 함수 템플릿의 경우에는 코드 본문을 제공하는 것
* - 클래스나 클래스 템플릿은 멤버를 넣어 준 결과를 의미
*/

int x;												// 객체 정의

std::size_t numDigits(int number) {					// 함수 정의
	std::size_t digitSoFar = 1;
	while ((number /= 10) != 0) ++digitSoFar;
	return digitSoFar;
}

class Widget {										// 클래스 정의
public:
	Widget() {};
	~Widget() {};
	// ...
};

template<typename T>								// 템플릿 정의
class GraphNode {
public:
	GraphNode() {};
	~GraphNode() {};
	// ...
};

/*
* 3. 초기화(initialization)
* - 어떤 객체에 최초의 값을 부여하는 과정
* - 사용자 정의 타입으로 생성한 객체의 초기화는 생성자에 의해 이루어진다.
*	- 기본 생성자(default constructor)는 어떤 인자도 주어지지 않은 채로 호출될 수 있는 생성자
*	- 원래부터 매개변수가 없거나 모든 매개변수가 기본 값을 가지고 있으면 기본 생성자가 될 수 있다.
*/

// 기본 생성자: 매개변수가 없음
class A {
public:
	A() {};
};

// 기본 생성자: 모든 매개변수가 기본 값을 가짐
class B {
public:
	explicit B(int x = 0, bool b = true) {};
};

// 기본 생성자 아님
class C {
public:
	explicit C(int x) {};
};

class D {
public:
	int number;
	D(int x) : number{ x } {};
};

void doSomethingWithD(D object) { std::cout << object.number << std::endl; };
void doSomethingWithB(B object) {};

/*
* 4. 복사 생성자(copy constructor)
* - 어떤 객체의 초기화를 위해 그와 같은 타입의 객체로부터 초기화를 진행할 때 호출되는 함수
* 
* 5. 복사 대입 연산자(copy assignment operator)
* - 같은 타입의 다른 객체에 어떤 객체의 값을 복사하는 용도로 사용
*/

class Widget2 {
public:
	Widget2() {};										// 기본 생성자
	Widget2(const Widget2& rhs) {};						// 복사 생성자
	Widget2& operator=(const Widget& rhs) {};			// 복사 대입 연산자
};

bool accept(Widget2 w) {};		// 값에 의한 객체 전달을 정의해 주는 함수가 복사 생성자

/**
* 6. STL(Standard Template Library)
* - 표준 템플릿 라이브러리
* - C++ 표ㅕ준 라이브러리에 속한 라이브러리로, 컨테이너, 알고리즘 등 여러 기능을 제공
* - 컨테이너, 반복자, 알고리즘에 관련된 기능들의 상당 부분을 함수 객체가 차지하고 있음
*	- 함수 객체는 연산자 operator()를 오버로드한 클래스로 만든다.
*/

/*
* 7. 미정의 동작(undefined behaviour)
* - 실행 시간에 어떤 현상이 터질지 확실히 예측할 수 없는 동작
*/

/*
* 8. 인터페이스
* - C++에는 언어 차원에서 Interface를 지원하지 않음
* - 이 책에서 말하는 인터페이스는 
* - 함수의 시그니처(반환 타입, 매개 변수 리스트 등), 어떤 클래스의 접근 가능 요소, 템플릿의 타입 매개변수 등을 의미
* - 즉, 지극히 평범하고 일반적인 설계 아이디어로서의 인터페이스를 의미
*/

/*
* 9. 사용자(client)
* - 사용자는 개발자가 만든 코드를 사용하는 아무개(사람) 혹은 아무것(코드)
*/

/*
* 10. 이름짓기
* - 특정 이름은 추상적임
* - rhs(right hand side), lhs(left hand side)는 이항 연산자(operator=)의 우변, 좌변을 나타냄
* - Widget 클래스는 아무 기능 없는 클래스
* - 포인터, 참조의 이름을 지을 때에는 T에 대한 포인터라는 의미로 다음과 같이 작성
*/

Widget* pw;		// Widget에 대한 포인터
Widget& rw;		// Widget에 대한 참조


int main()
{
	/*
	* 3.1
	* explicit의 용도
	* - explicit으로 선언된 생성자는 암시적 타입 변환을 막을 수 있다.
	*/
	D dObj1(0);
	doSomethingWithD(dObj1);			// 문제 없음. D 객체를 doSomethingWithD에 전달

	doSomethingWithD(1);				// 문제 없음. D 객체의 생성자가 호출되어 D 객체가 만들어져 doSomethingWithD에 전달

	B bObj1;
	doSomethingWithB(bObj1);			// 문제 없음.
	
	// doSomethingWithB(1);				// 에러. doSomethingWithB는 B 객체를 전달 받아야 하는데, 1을 B로 만들 수 없음.
	doSomethingWithB(B(1));				// 문제 없음.

	/*
	* 4, 5
	* 복사 생성자, 복사 대입 연산자 사용
	*/
	Widget2 w1;			// 기본 생성자 호출
	Widget2 w2(w1);		// 복사 생성자 호출
	w1 = w2;			// 복사 대입 연산자 호출
	Widget2 w3 = w1;	// 복사 생성자가 호출됨. w3는 선언만 있고 정의되어 있지 않기 때문에 복사 대입 연산자를 사용할 수 없음.

	/*
	* 7
	* 미정의 동작
	*/

	int* p;				// NULL 포인터
	std::cout << *p;	// NULL 포인터의 역참조는 미정의 동작 발생

	char name[] = "Kim";		// name은 크기가 4인 배열
	char c = name[10];			// 유효하지 않은 배열 인덱스 참조는 미정의 동작 발생
}
