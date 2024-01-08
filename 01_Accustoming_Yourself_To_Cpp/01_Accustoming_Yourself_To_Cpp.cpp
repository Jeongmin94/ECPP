// 01_Accustoming_Yourself_To_Cpp.cpp
#include <iostream>

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
const Rational operator*(const Rational& lhs, const Rational& rhs) {};

Rational a, b, c;
// ..
//(a * b) = c;		// ��� ������� ���Կ�����(=) ����Ͽ� �����߻�

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

	const char* cp = greeting;			// �����Ͱ� ����Ű�� ����� ���(���� ������)
	cout << cp << endl;
	cp = text;							// ������ cp�� ����Ű�� ����� ���� ����
	cout << cp << endl;
	// cp[0] = 'k';						// ������ cp�� ����Ű�� ����� ���� ���� �Ұ���(��� ������)


	char* const ccp = greeting;			// �����Ͱ� ����Ű�� ����� ���(��� ������)
	cout << ccp << endl;
	// ccp = text;						// ������ ccp�� ����Ű�� ��� ���� �Ұ���
	ccp[0] = 'k';
	cout << ccp << endl;				// ������ ccp�� ����Ű�� ����� ���� ���� ����


	const char* const cccp = greeting;	// �����Ͱ� ����Ű�� ���� ����� �� ���� �Ұ���
	cout << cccp << endl;
	// cccp = text;
	// cccp[0] = 'z';
}
