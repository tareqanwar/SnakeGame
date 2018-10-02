#pragma once
class Location
{
public:
	void Add(const Location& l) {
		x += l.x;
		y += l.y;
	};
	bool operator==(const Location& rhs) const {
		return x == rhs.x && y == rhs.y;
	};
	int x;
	int y;
};