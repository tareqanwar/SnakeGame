#include "Goal.h"

Goal::Goal(std::mt19937& rng, const Board& board, const Snake& snake)
{
	Goal::Respawn(rng, board, snake);
}

void Goal::Respawn(std::mt19937& rng, const Board& board, const Snake& snake)
{
	std::uniform_int_distribution<int> xDist(0, board.GetGridWidth() - 1);
	std::uniform_int_distribution<int> yDist(0, board.GetGridHeight() - 1);

	Location newLoc;

	do
	{
		newLoc.x = xDist(rng);
		newLoc.y = yDist(rng);
	} while (snake.IsInTile(newLoc));

	loc = newLoc;
}

void Goal::Draw(Board& board) const
{
	board.DrawCell(loc, color);
}

const Location& Goal::GetLocation() const
{
	return loc;
}
