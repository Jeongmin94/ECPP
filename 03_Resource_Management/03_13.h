#pragma once

// 항목 13: 자원 관리에는 객체가 그만!

// 투자를 모델링해 주는 클래스 설계
// 여러 형태의 투자를 모델링한 최상위 클래스
class Investment {};

// 파생 클래스의 객체를 사용자가 얻기 위한 팩토리 함수 사용
// 이 객체의 메모리 할당 해제는 사용자가 해야함
Investment* createInvestment();

void f() {
	Investment* pInv = createInvestment();
	// ...
	delete pInv;
}


#include <memory>
// auto_ptr 사용
void f() {
	std::auto_ptr<Investment> pInv(createInvestment());
}