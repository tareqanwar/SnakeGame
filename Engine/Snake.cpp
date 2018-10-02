#include "Snake.h"
#include <assert.h>

Snake::Snake(const Location& loc)
{
	constexpr int nBodyColors = 4;
	constexpr Color bodyColors[nBodyColors] = {
		{ 10, 100, 32 },
		{ 10, 130, 48 },
		{ 18, 160, 48 },
		{ 10, 130, 48 }
	};
	for (int i = 0; i < nSegmentsMax-1; ++i) {
		segments[i].InitBody(bodyColors[i % nBodyColors]);
	}
	segments[0].InitHead(loc);
}

void Snake::MoveBy(const Location& delte_loc)
{ 
	for (int i = nSegments - 1; i > 0; --i) {
		segments[i].Follow(segments[i-1]);
	}
	segments[0].MoveBy(delte_loc);
}

Location Snake::GetNextHeadLocation(const Location& delta_loc) const
{	
	Location l(segments[0].GetLocation());
	l.Add(delta_loc);
	return l;
}

void Snake::Grow()
{
	if (nSegments <= nSegmentsMax) {
		++nSegments;
	}
}

void Snake::Draw(Board& board) const
{
	for (int i = 0; i < nSegments; ++i) {
		segments[i].Draw(board);
	}
}

bool Snake::IsInTileExceptEnd(const Location& target) const
{
	for (int i = 0; i < nSegments  - 1; ++i) {
		if (segments[i].GetLocation() == target) {
			return true;
		}
	}

	return false;
}

bool Snake::IsInTile(const Location& target) const
{
	for (int i = 0; i < nSegments; ++i) {
		if (segments[i].GetLocation() == target) {
			return true;
		}
	}

	return false;
}

void Snake::Segment::InitHead(const Location& in_loc)
{
	loc = in_loc;
	color = Snake::headColor;
}

void Snake::Segment::InitBody(Color in_color)
{
	color = in_color;
}

void Snake::Segment::Follow(const Segment& next)
{
	loc = next.loc;
}

void Snake::Segment::MoveBy(const Location& delte_loc)
{
	assert(abs(delte_loc.x) + abs(delte_loc.y) == 1);
	loc.Add(delte_loc);
}

void Snake::Segment::Draw(Board& board) const
{
	board.DrawCell(loc, color);
}

const Location& Snake::Segment::GetLocation() const
{
	return loc;
}
