#pragma once

// 항목 7: 다형성을 가진 기본 클래스에서는 소멸자를 반드시 가상 소멸자로 선언하자

// 시간 기록을 유지하는 방법을 정의하는 기본 클래스
class TimeKeeper {
public:
	TimeKeeper();
	virtual ~TimeKeeper();
};

// 파생 클래스
class AtomicClock : public TimeKeeper {};
class WaterClock : public TimeKeeper {};
class WristWatch : public TimeKeeper {};

// 베이스 클래스로 사용하지 않을 클래스
class Point {
public:
	Point(int xCoord, int yCoord);
	~Point();

private:
	int x, y;
};