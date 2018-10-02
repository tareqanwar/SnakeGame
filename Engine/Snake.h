#pragma once
#include "Board.h"

class Snake
{
private:
	class Segment
	{
	public:
		void InitHead(const Location& loc);
		void InitBody(Color color);
		void Follow(const Segment& next);
		void MoveBy(const Location& delte_loc);
		void Draw(Board& board) const;
		const Location& GetLocation() const;
	private:
		Location loc;
		Color color;
	};
public:
	Snake(const Location& loc);
	void MoveBy(const Location& delte_loc);
	Location GetNextHeadLocation(const Location& delta_loc) const;
	void Grow();
	void Draw(Board& board) const;
	bool IsInTile(const Location& target) const;
	bool IsInTileExceptEnd(const Location& target) const;

private:
	static constexpr Color headColor = Colors::Yellow;
	static constexpr int nSegmentsMax = 100;
	Segment segments[nSegmentsMax];
	int nSegments = 1;
};
