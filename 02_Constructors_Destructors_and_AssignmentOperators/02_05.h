#pragma once

// 항목 5: C++가 은근슬쩍 만들어 호출해 버리는 함수들에 촉각을 세우자

/*
* C++ 컴파일러는 클래스 내부에 생성자, 복사 생성자, 복사 대입 연산자, 소멸자를 
* 프로그래머가 선언해 놓지 않은 상태면 기본형태로 자동으로 만들어 준다.
*/

// 이렇게 선언된 클래스는
// class Empty {};

// 컴파일러에 의해 이런 코드가 추가된다.
class Empty {
public:
  // 기본 생성자
	Empty() {}
 
  // 복사 생성자
	Empty(const Empty& rhs) {}
 
  // 소멸자
	~Empty() {}

  // 복사 대입 연산자
	Empty& operator=(const Empty& rhs) {}
};

//Empty e1;						// 기본 생성자
//Empty e2(e1);					// 복사 생성자
//	
//e2 = e1;						// 복사 대입 연산자

//template<typename T>
//class NamedObject {
//public:
//	NamedObject(const char* name, const T& value);
//	NamedObject(const std::string name, const T& value);
//
//private:
//	std::string nameValue;
//	T objectValue;
//};

template<typename T>
class NamedObject {
public:
	// nameValue가 비상수 string의 레퍼런스이기 때문에 name은 상수 타입이 아니다.
	// 참조할 string을 가져야 하기 때문에 char*는 없앰
	NamedObject(std::string& name, const T& value);

private:
	std::string& nameValue;		// 참조자
	const T objectValue;		// 상수
};