#pragma once

// �׸� 13: �ڿ� �������� ��ü�� �׸�!

// ���ڸ� �𵨸��� �ִ� Ŭ���� ����
// ���� ������ ���ڸ� �𵨸��� �ֻ��� Ŭ����
class Investment {};

// �Ļ� Ŭ������ ��ü�� ����ڰ� ��� ���� ���丮 �Լ� ���
// �� ��ü�� �޸� �Ҵ� ������ ����ڰ� �ؾ���
Investment* createInvestment();

void f() {
	Investment* pInv = createInvestment();
	// ...
	delete pInv;
}


#include <memory>
// auto_ptr ���
void f() {
	std::auto_ptr<Investment> pInv(createInvestment());
}