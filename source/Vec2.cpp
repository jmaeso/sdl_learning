#pragma once

struct Vec2{
	int x = 0;
	int y = 0;

	bool operator==(const Vec2& a) const{
		return (x == a.x && y == a.y);
	}

	bool operator!=(const Vec2& a) const{
		return !(x == a.x && y == a.y);
	}

	bool operator+=(const Vec2& a) const{
		return Vec2{ x += a.x, y += a.y };
	}

	bool operator+(const Vec2& a) const{
		return Vec2{ x + a.x, y + a.y };
	}

	bool operator-(const Vec2& a) const{
		return Vec2{ x - a.x, y - a.y };
	}

	friend std::ostream& operator<<(std::ostream& os, const Vec2& v){
		os << "(" << (int)v.x << "," << (int)v.y << ")";
		return os;
	}
};