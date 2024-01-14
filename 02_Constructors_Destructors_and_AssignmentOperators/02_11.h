#pragma once

// ### 항목 11: operator=에서는 자기대입에 대한 처리가 빠지지 않도록 하자

class Bitmap {};

class Widget {
public:

	// 안전하지 않게 구현된 대입연산자
	// *this와 rhs가 같은 객체일 가능성이 있음
	// 이 경우에 delete pb를 하면 this뿐만 아니라 rhs의 객체에도 적용됨
	Widget& operator=(const Widget& rhs) {
		delete pb;
		pb = new Bitmap(*rhs.pb);

		return *this;
	}

private:
	Bitmap* pb;
};

// 자기대입 검사
Widget& Widget::operator=(const Widget& rhs) {
	if (this == &rhs) return *this;

	delete pb;
	pb = new Bitmap(*rhs.pb);

	return *this;
}

// Bitmap 객체 생성 과정에서 발생하는 예외 처리 
Widget& Widget::operator=(const Widget& rhs) {
	Bitmap* pOrig = pb;					// 원래의 pb를 어딘가에 복사
	pb = new Bitmap(*rhs.pb);			// 그 다음 pb가 *pb의 사본을 가리키게 만듬
	delete pOrig;						// 원래의 pb 삭제

	return *this;
}

// 복사 후 맞바꾸기
class Widget {
	void swap(Widget& rhs);
};

Widget& Widget::operator=(const Widget& rhs) {
	Widget temp(rhs);				// rhs의 데이터에 대해 사본 생성
	swap(temp);						// *this의 데이터를 사본의 것과 스왑
	return *this
}

// 클래스의 복사 대입 연산자는 인자를 값으로 취하도록 선언하는 것이 가능함
// 값에 의한 전달을 수행하면 전달된 대상의 사본이 생김을 이용하는 방법
Widget& Widget::operator=(Widget rhs) {
	swap(this);
	return *this;
}