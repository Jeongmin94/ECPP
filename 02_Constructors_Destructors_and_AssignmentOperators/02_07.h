#pragma once

// �׸� 7: �������� ���� �⺻ Ŭ���������� �Ҹ��ڸ� �ݵ�� ���� �Ҹ��ڷ� ��������

// �ð� ����� �����ϴ� ����� �����ϴ� �⺻ Ŭ����
class TimeKeeper {
public:
	TimeKeeper();
	virtual ~TimeKeeper();
};

// �Ļ� Ŭ����
class AtomicClock : public TimeKeeper {};
class WaterClock : public TimeKeeper {};
class WristWatch : public TimeKeeper {};

// ���̽� Ŭ������ ������� ���� Ŭ����
class Point {
public:
	Point(int xCoord, int yCoord);
	~Point();

private:
	int x, y;
};