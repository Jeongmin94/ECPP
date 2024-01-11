#pragma once

// �׸� 5: C++�� ���ٽ�½ ����� ȣ���� ������ �Լ��鿡 �˰��� ������

/*
* C++ �����Ϸ��� Ŭ���� ���ο� ������, ���� ������, ���� ���� ������, �Ҹ��ڸ� 
* ���α׷��Ӱ� ������ ���� ���� ���¸� �⺻���·� �ڵ����� ����� �ش�.
*/

// �̷��� ����� Ŭ������
// class Empty {};

// �����Ϸ��� ���� �̷� �ڵ尡 �߰��ȴ�.
class Empty {
public:
  // �⺻ ������
	Empty() {}
 
  // ���� ������
	Empty(const Empty& rhs) {}
 
  // �Ҹ���
	~Empty() {}

  // ���� ���� ������
	Empty& operator=(const Empty& rhs) {}
};

//Empty e1;						// �⺻ ������
//Empty e2(e1);					// ���� ������
//	
//e2 = e1;						// ���� ���� ������

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
	// nameValue�� ���� string�� ���۷����̱� ������ name�� ��� Ÿ���� �ƴϴ�.
	// ������ string�� ������ �ϱ� ������ char*�� ����
	NamedObject(std::string& name, const T& value);

private:
	std::string& nameValue;		// ������
	const T objectValue;		// ���
};