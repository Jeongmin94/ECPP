#pragma once

// 항목 8: 예외가 소멸자를 떠나지 못하도록 붙들어 놓자.

class DBConnection {
public:
	static DBConnection create();			// DBConnection 객체를 반환하는 함수

	void close();							// 연결 닫기. 연결이 실하면 예외 발생
};

// DBConnection을 관리하는 클래스
class DBConn {
public:
	~DBConn() {
		db.close();
	}

private:
	DBConnection db;
};

// 1. 프로그램 바로 종료
// - 객체 소멸이 진행되다가 에러가 발생한 후에 
// - 프로그램 실행을 계속할 수 없는 상황에서는 괜찮은 선택
DBConn::~DBConn() {
	try { db.close(); }
	catch (...) {
		// log
		std::abort();
	}
}

// 2. 예외 삼키기
// - 예외 삼키기는 대부분의 경우에서 좋은 발상이 아니다. 중요한 정보가 묻혀 버리기 때문이다.
// - 하지만 경우에 따라 불완전한 프로그램 종료 혹은 미정의 동작으로 인해 입는 위험을 감수하는 것보다 낫다.
// - 예외 삼키기를 선택했다면, 예외가 발생해도 프로그램이 신뢰성 있게 실행되어야 한다.
DBConn::~DBConn() {
	try { db.close(); }
	catch (...) {
		// log
	}
}