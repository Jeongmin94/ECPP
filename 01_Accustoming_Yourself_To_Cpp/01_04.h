#pragma once
#include <iostream>
#include <string>
#include <list>

/*
* �׸� 4: ��ü�� ����ϱ� ���� �ݵ�� �� ��ü�� �ʱ�ȭ����
* - C++�� ��ü �ʱ�ȭ ��Ģ�� �����ϸ�, C++�� �����ϴ� �� �κп� ���� �ٸ��� �۵��Ѵ�.
* - ���� ���� ���� ����� ��� ��ü�� ����ϱ� ���� �׻� �ʱ�ȭ�ϴ� ���̴�.
*/

// 1. �⺻���� Ÿ������ ������� ���� ��ü�� �ʱ�ȭ�� �ռ� �ؾ� �Ѵ�.
//int x = 0;									// int�� ���� �ʱ�ȭ
//const char* text = "A C-Style string";		// �������� ���� �ʱ�ȭ
//
//double d;										// �Է� ��Ʈ������ �������ν� �ʱ�ȭ
//std::cin >> d;					

// 2. 1���� ������ ������ �κ��� �����ڷ� �Ͱ�Ǹ�, �����ڿ����� �ش� ��ü�� ��� ���� �ʱ�ȭ�ϸ� �ȴ�.
// - ��Ģ�� ���������� ����(assignment)�� �ʱ�ȭ(initialization)�� �򰥸��� �ʴ� ���� �߿��ϴ�.

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
