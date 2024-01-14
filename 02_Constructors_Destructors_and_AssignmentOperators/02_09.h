#pragma once

// �׸� 9: ��ü ���� �� �Ҹ� ���� �߿��� ����� ���� �Լ��� ȣ������ ����

// �ֽ� �ŷ��� ���� �⺻ Ŭ����
// �ֽ� �ŷ� �𵨸��� �־� �߿��� ����� ����(audit) ���
// ���� �ֽ� �ŷ� ��ü�� ������ ������ ���� �α׸� ����ϱ� ���� ����� �ʿ�
class Transaction {
public:
	Transaction();

	// �ֽ� �ŷ� Ÿ�Կ� ���� �޶����� �α� ����� ����
	virtual void logTransaction() const = 0;
};

// �⺻ Ŭ���� ������ 
Transaction::Transaction() {

	// �������� ������ �������� �ŷ��� �α�
	logTransaction();
}

// �ֽ� �ŷ� �Ļ� Ŭ������
class BuyTransaction : public Transaction {
public:
	virtual void logTransaction() const;
};

class SellTransaction : public Transaction {
public:
	virtual void logTransaction() const;
};

// �����ڿ� �Ҹ��ڿ��� ȣ���ϴ� �Լ����� ���� �Լ��� �� �� ������ ����� ��Ģ ����
#include <string>

class Transaction {
public:
	explicit Transaction(const std::string& logInfo);

	void logTransaction(const std::string& logInfo) const; // �񰡻� �Լ��� ����
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
