#pragma once

// 항목 9: 객체 생성 및 소멸 과정 중에는 절대ㅗ 가상 함수를 호출하지 말자

// 주식 거래에 대한 기본 클래스
// 주식 거래 모델링에 있어 중요한 기능은 감사(audit) 기능
// 따라서 주식 거래 객체가 생성될 때마다 감사 로그를 기록하기 위한 기능이 필요
class Transaction {
public:
	Transaction();

	// 주식 거래 타입에 따라 달라지는 로그 기록을 생성
	virtual void logTransaction() const = 0;
};

// 기본 클래스 생성자 
Transaction::Transaction() {

	// 생성자의 마지막 동작으로 거래를 로깅
	logTransaction();
}

// 주식 거래 파생 클래스들
class BuyTransaction : public Transaction {
public:
	virtual void logTransaction() const;
};

class SellTransaction : public Transaction {
public:
	virtual void logTransaction() const;
};

// 생성자와 소멸자에서 호출하는 함수들이 가상 함수가 될 수 없도록 만드는 규칙 적용
#include <string>

class Transaction {
public:
	explicit Transaction(const std::string& logInfo);

	void logTransaction(const std::string& logInfo) const; // 비가상 함수로 선언
};

Transaction::Transaction(const std::string& logInfo) {
	logTransaction(logInfo);
}

class BuyTransaction : public Transaction {
public:
	BuyTransaction(const std::string& logInfo) : Transaction{ logInfo };
	BuyTransaction(parameter) : Transaction(createLogString(parameter));

private:
	static std::string createLogString(parameters);
};
