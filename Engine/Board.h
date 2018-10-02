#pragma once
#include "Graphics.h"
#include "Location.h"

class Board
{
public:
	Board(Graphics& gfx);
	void DrawCell(const Location& loc, Color color);
	int GetGridWidth() const;
	int GetGridHeight() const;
	bool IsInsideBoard(const Location& loc) const;
	void DrawBoarder();
private:
	static constexpr Color borderColor = Colors::Blue;
	static constexpr int dimension = 20;
	static constexpr int cellPadding = 1;
	static constexpr int width =38;
	static constexpr int height = 28;
	static constexpr int borderWidth = 4;
	static constexpr int borderPadding = 2;
	static constexpr int x = 13;
	static constexpr int y = 12;
	Graphics& gfx;
};
