// 01_Accustoming_Yourself_To_Cpp.cpp
#include <iostream>
#include <string>
/*
*   �׸� 2: #define�� �����ŵ� const, enum, inline�� ���ø���
*/

#define ASPECT_RATIO 1.653
const double AspectRatio = 1.653;

class GamePlayer {
private:
	static const int NumTurns = 5;
	int scores[NumTurns];

	// ���� �����Ϸ��� ���
	enum { EnumNumTurns = 5 };
	int enumScores[EnumNumTurns];
};

void f(int num) {
	//std::cout << num << std::endl; 
};
#define CALL_WITH_MAX(a, b) f((a) > (b) ? (a) : (b))

// �Լ��� const ���
class Rational {};
const Rational operator*(const Rational& lhs, const Rational& rhs) { return Rational{}; };

Rational a, b, c;
// ..
//(a * b) = c;		// ��� ������� ���Կ�����(=) ����Ͽ� �����߻�

// ��� ��� �Լ�
// const�� �ְ� ������ ���̷ε� �Լ� �����ε��� �����ϴ�.

class TextBlock {
public:
	TextBlock(const std::string& _text) : text{ _text } {};

	static const int MaxSize = 10;
	enum { EnumMaxSize = 10 };
	char string[MaxSize];

	const char& operator[](std::size_t position) const {
		std::cout << "��� ��� �Լ� ȣ���\n";
		return text[position];
	}


	// 1. ��� ��� �Լ��� ȣ���ϱ� ���� this�� const TextBlock&���� ĳ����
	//	- ���� ��ü���� ��� ��ü�� ������ ������ ĳ�����̱� ������ static_cast ���
	// 2. ȣ��� ��� ��� �Լ��� ��������� const�� ��������� ���� char&���� ĳ����
	//  - ��� ��ü�� ���� ��ü�� ��ȯ�ϴ� ����� const_cast ���� ����� ����
	char& operator[](std::size_t position) {
		return const_cast<char&>(static_cast<const TextBlock&>(*this)[position]);
	}

private:
	std::string text;
};

void print(const TextBlock& ctb) {
	std::cout << ctb[0] << std::endl;
}

// ��Ʈ���� ����� �˻縦 ����ϴ� ��������� �۵����� �ʴ� ����
class CTextBlock {
public:
	CTextBlock(char* str) : pText(str) {};

	char& operator[](std::size_t position) const {
		return pText[position];
	}

	// mutable Ű���带 ����ϸ� �������� ��� ������ ���� ������ �� �ִ�.
	// ���� ����� �˻� ����� ���� const ��� �Լ����� �� ������ �� �� ����� �� �ִ�.

private:
	char* pText;
};

int main()
{
	int a = 5, b = 0;
	CALL_WITH_MAX(++a, b);
	std::cout << a << std::endl;

	CALL_WITH_MAX(++a, b + 10);
	std::cout << a << std::endl;


	// �����Ϳ� ���
	using namespace std;

	char greeting[] = "Hello";
	char text[] = "Text";

	char* p = greeting;
	cout << p << endl;
	p = text;
	cout << p << endl;
	p[0] = 'Z';
	cout << p << endl;

	const char* cp = greeting;			// �����Ͱ� ����Ű�� ����� ���� ���(���� ������)
	cout << cp << endl;
	cp = text;							// ������ cp�� ����Ű�� ����� ���� ����
	cout << cp << endl;
	// cp[0] = 'k';						// ������ cp�� ����Ű�� ����� ���� ���� �Ұ���(��� ������)


	char* const ccp = greeting;			// ������ ��ü�� ���(��� ������)
	cout << ccp << endl;
	// ccp = text;						// ������ ccp�� ����Ű�� ��� ���� �Ұ���
	ccp[0] = 'k';						// ������ ccp�� ����Ű�� ����� �� ���� ����
	cout << ccp << endl;				


	const char* const cccp = greeting;	// �����Ͱ� ����Ű�� ���� ����� �� ���� �Ұ���
	cout << cccp << endl;
	// cccp = text;
	// cccp[0] = 'z';

	TextBlock tb("Hello");
	std::cout << tb[0] << std::endl;

	const TextBlock constTb("Hello");
	std::cout << constTb[0] << std::endl;

	print(tb);								// �Լ��� �Ű������� ��� ��ü�� ���޵�

	//const CTextBlock cctb("Hello");
}
