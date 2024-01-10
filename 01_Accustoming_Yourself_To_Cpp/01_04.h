#pragma once
#include <iostream>
#include <string>
#include <list>

/*
* 항목 4: 객체를 사용하기 전에 반드시 그 객체를 초기화하자
* - C++의 객체 초기화 규칙은 복잡하며, C++을 구성하는 각 부분에 따라 다르게 작동한다.
* - 따라서 가장 좋은 방법은 모든 객체를 사용하기 전에 항상 초기화하는 것이다.
*/

// 1. 기본제공 타입으로 만들어진 비멤버 객체는 초기화를 손수 해야 한다.
//int x = 0;									// int의 직접 초기화
//const char* text = "A C-Style string";		// 포인터의 직접 초기화
//
//double d;										// 입력 스트림에서 읽음으로써 초기화
//std::cin >> d;					

// 2. 1번을 제외한 나머지 부분은 생성자로 귀결되며, 생성자에서는 해당 객체의 모든 것을 초기화하면 된다.
// - 규칙은 간단하지만 대입(assignment)과 초기화(initialization)을 헷갈리지 않는 것이 중요하다.

class PhoneNumber {

};

// Address Book Entry
class ABEntry {
public:
	ABEntry(const std::string& name, const std::string& address, const std::list<PhoneNumber>& phones);

private:
	std::string theName;
	std::string theAddress;
	std::list<PhoneNumber> thePhones;
	int numTimesConsulted;
};

ABEntry::ABEntry(const std::string& name, const std::string& address, const std::list<PhoneNumber>& phones) {
	theName = name;
	theAddress = address;
	thePhones = phones;
	numTimesConsulted = 0;
}

ABEntry::ABEntry(const std::string& name, const std::string& address, const std::list<PhoneNumber>& phones)
	:theName(name), theAddress(address), thePhones(phones), numTimesConsulted(0) 
{}
