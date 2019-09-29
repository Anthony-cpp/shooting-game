#pragma once
#include "Singleton.h"

#define KEY(i) KEY_INPUT_ ## i

class Keyboard : public Singleton<Keyboard> {
	Keyboard();
	friend Singleton< Keyboard >;

public:
	bool Update(bool drawKeyCodeFlag = false);
	int GetPressingCount(int keyCode);
	int GetReleasingCount(int keyCode);

private:
	static const int KEY_NUM = 256;
		int m_keyPressingCount[KEY_NUM];
		int m_keyReleasingCount[KEY_NUM];

	bool IsAvailableCode(int keyCode);
};


class Mouse : public Singleton<Mouse> {
	Mouse();
	friend Singleton< Mouse >;

public:
	static constexpr int LEFT_CLICK = 0;
	static constexpr int RIGHT_CLICK = 1;

	bool Update();
	int  GetPressingCount(int keyCode);
	int  GetReleasingCount(int keyCode);
	int  GetX() { return m_x; }
	int  GetY() { return m_y; }
	bool IsMouseHoverRect(int x1, int y1, int x2, int y2);
	bool IsMouseHoverCircle(int x, int y, int r);

private:
	static constexpr int KEY_NUM = 8;
	int m_x, m_y;
	int m_buttonPressingCount[KEY_NUM];
	int m_buttonReleasingCount[KEY_NUM];

	bool isAvailableCode(int keyCode);

};

namespace input {
	bool UpdateAll(bool drawKeyCodeFlag = false);
}
