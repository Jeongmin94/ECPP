#pragma once

// ### �׸� 11: operator=������ �ڱ���Կ� ���� ó���� ������ �ʵ��� ����

class Bitmap {};

class Widget {
public:

	// �������� �ʰ� ������ ���Կ�����
	// *this�� rhs�� ���� ��ü�� ���ɼ��� ����
	// �� ��쿡 delete pb�� �ϸ� this�Ӹ� �ƴ϶� rhs�� ��ü���� �����
	Widget& operator=(const Widget& rhs) {
		delete pb;
		pb = new Bitmap(*rhs.pb);

		return *this;
	}

private:
	Bitmap* pb;
};

// �ڱ���� �˻�
Widget& Widget::operator=(const Widget& rhs) {
	if (this == &rhs) return *this;

	delete pb;
	pb = new Bitmap(*rhs.pb);

	return *this;
}

// Bitmap ��ü ���� �������� �߻��ϴ� ���� ó�� 
Widget& Widget::operator=(const Widget& rhs) {
	Bitmap* pOrig = pb;					// ������ pb�� ��򰡿� ����
	pb = new Bitmap(*rhs.pb);			// �� ���� pb�� *pb�� �纻�� ����Ű�� ����
	delete pOrig;						// ������ pb ����

	return *this;
}

// ���� �� �¹ٲٱ�
class Widget {
	void swap(Widget& rhs);
};

Widget& Widget::operator=(const Widget& rhs) {
	Widget temp(rhs);				// rhs�� �����Ϳ� ���� �纻 ����
	swap(temp);						// *this�� �����͸� �纻�� �Ͱ� ����
	return *this
}

// Ŭ������ ���� ���� �����ڴ� ���ڸ� ������ ���ϵ��� �����ϴ� ���� ������
// ���� ���� ������ �����ϸ� ���޵� ����� �纻�� ������ �̿��ϴ� ���
Widget& Widget::operator=(Widget rhs) {
	swap(this);
	return *this;
}