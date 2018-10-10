#pragma once

#include <string>
#include <SDL.h>
#include "mathHelper.h"

class Rect {
public:
	Rect();
	Rect(int x, int y, int w, int h);
	void Clear();

	static Rect CreateRect(int x, int y, int w, int h) {
		Rect tempRect(x, y, w, h);
		return tempRect;
	}

	Rect operator+(Rect* rect) {
		return Rect(this->x + rect->x, this->y + this->x, w, h);
	}
	Rect operator-(Rect* rect) {
		return Rect(this->x - rect->x, this->y - this->x, w, h);
	}
	bool operator==(const Rect* rect) {
		return (x == rect->x && y == rect->y && w == rect->w && h == rect->h);
	}
	bool operator!=(const Rect* rect) {
		return !(x == rect->x && y == rect->y && w == rect->w && h == rect->h);
	}

	SDL_Rect* ToSDLRect();
	std::string ToString();

	bool Intersects(Rect* rect);
	bool Intersects(int x, int y, int w, int h);

	bool Contains(Rect* rect);
	bool Contains(Vec2* point);
	bool Contains(int x, int y, int w, int h);

	Vec2* Position();
	Vec2* Center();
	int CenterX();
	int CenterY();

	int Left();
	int Right();
	int Top();
	int Bottom();
	int Perimiter();
	int Area();

	int GetX();
	int GetY();
	int GetW();
	int GetH();

	void SetRect(int x, int y, int w, int h);
	void SetSize(Vec2* size);
	void SetPos(Vec2* pos);
	void Translate(Vec2* offset);
	void TranslateX(int x);
	void TranslateY(int y);

	int x, y, w, h;

	virtual ~Rect();
private:
	SDL_Rect* rect;
};
