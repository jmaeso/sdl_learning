#pragma once

#include <iostream>

struct Vec2{
	int x = 0;
	int y = 0;

	Vec2(){
		x = 0;
		y = 0;
	}

	Vec2(int xx, int yy){
		x = xx;
		y = yy;
	}

	bool operator==(const Vec2& a) const{
		return (x == a.x && y == a.y);
	}

	bool operator!=(const Vec2& a) const{
		return !(x == a.x && y == a.y);
	}

	/*Vec2 operator+=(const Vec2& a) const{
		return Vec2( x += a.x, y += a.y );
	}

	Vec2 operator+(const Vec2& a) const{
		return{ x + a.x, y + a.y };
	}

	Vec2 operator-(const Vec2& a) const{
		return{ x - a.x, y - a.y };
	}*/

	/*friend std::ostream& operator<<(std::ostream& os, const Vec2& v){
		os << "(" << (int)v.x << "," << (int)v.y << ")";
		return os;
	}*/
};